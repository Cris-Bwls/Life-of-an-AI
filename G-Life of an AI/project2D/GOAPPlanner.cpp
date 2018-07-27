#include "GOAPPlanner.h"
#include "GOAPActionBase.h"

#include <vector>
#include <algorithm>

GOAPPlanner::GOAPPlanner()
{
}


GOAPPlanner::~GOAPPlanner()
{
}

std::queue<GOAPActionBase*> GOAPPlanner::MakePlan(EGOAPSymbol symbol, bool goalVal)
{
	auto Compare = [](auto a, auto b)
	{
		return a->fScore < b->fScore;
	};

	GOAPGraph graph = MakeGraph();

	GOAPGraphNode* root = graph.rootNode;
	root->previous = root;
	root->fScore = 0.0f;
	root->gScore = 0.0f;
	root->hScore = 0.0f;

	std::vector<GOAPGraphNode*> nodeHeap;
	

	nodeHeap.push_back(root);
	std::push_heap(nodeHeap.begin(), nodeHeap.end(), Compare);

	while (nodeHeap.size() > 0)
	{
		// Remove lowest node from open list and set traversed to true
		GOAPGraphNode* node = nodeHeap.front();
		std::pop_heap(nodeHeap.begin(), nodeHeap.end(), Compare);
		nodeHeap.pop_back();

		node->traversed = true;

		// Loop through nodes
		for (auto edge : node->edgesFrom)
		{
			GOAPGraphNode* other = edge->pNodeTo;

			// Skip traversed nodes
			if (other->traversed)
				continue;

			// Calculate Cost
			float cost = edge->pAction->GetRunningCost();

			float newScore = node->gScore + cost;

			if (newScore > other->gScore)
				continue;

			// Store gScore
			other->gScore = newScore;

			// Calculate hScore
			auto currentPreConditions = edge->pAction->GetPreConditions();
			float score = currentPreConditions->size();

			for (int i = 0; i < currentPreConditions->size(); ++i)
			{
				//HERENOW
				currentPreConditions.
			}
			
			other->hScore = score;

			// Set Final Score
			other->fScore = other->gScore + other->hScore;

			// point to the currently processing node
			other->previous = node;
			// point to previous action
			other->prevAction = edge->pAction;

			// terribly check if the node's already in the heap to be processed
			bool inHeap = false;
			for (int i = 0; i < nodeHeap.size(); ++i)
			{
				if (nodeHeap[i] == other)
				{
					inHeap = true;
					break;
				}
			}

			// if it's not, stick it on!
			if (!inHeap)
			{
				nodeHeap.push_back(other);
				std::push_heap(nodeHeap.begin(), nodeHeap.end(), Compare);
			}
		}
	}

	// let's grab the cheapest node that results in the state we want
	GOAPGraphNode* endPoint = nullptr;
	float cheapestScore = INFINITY;
	for (auto node : graph.nodes)
	{
		if (node->worldState[symbol] == goalVal &&
			node->fScore < cheapestScore)
		{
			endPoint = node;
			cheapestScore = node->fScore;
		}
	}

	std::queue<GOAPActionBase*> result;

	// no plan was available
	if (!endPoint)
	{
		return result;
	}

	// this should never happen if the end point is valid
	// even if it's the only node in the path, the previous node will
	// point to itself
	if (!endPoint->previous)
	{
		return result;
	}

	// get the plan from the graph and stick it into a vector so we can 
	// put it into the queue in the right order
	std::vector<GOAPActionBase*> path;
	while (endPoint->previous != endPoint)
	{
		path.push_back(endPoint->prevAction);
		endPoint->prevAction->SetStatus(EACTIONSTATUS_INACTIVE);

		endPoint = endPoint->previous;
	}

	// push it into the queue backwards so it's in the right order
	for (int i = path.size() - 1; i >= 0; --i)
		result.push(path[i]);

	return result;
}

void GOAPPlanner::SetActionList(std::vector<GOAPActionBase*>* pActionList)
{
	m_pActionList = pActionList;
}

void GOAPPlanner::SetState(SymbolMap const & newState)
{
	m_worldState = newState;
}

bool GOAPPlanner::CanDoAction(GOAPActionBase * action, SymbolMap & state)
{
	for (auto p : *action->GetPreConditions())
		if (state[p.first] != p.second)
			return false;
	return true;
}

GOAPGraph GOAPPlanner::MakeGraph()
{
	GOAPGraph graph;
	GOAPGraphNode* rootNode = graph.getNode(m_worldState);
	rootNode->actionsLeft = *m_pActionList;

	std::queue<GOAPGraphNode*> nodeQueue;
	nodeQueue.push(rootNode);

	while (!nodeQueue.empty())
	{
		GOAPGraphNode* node = nodeQueue.front();
		nodeQueue.pop();

		node->traversed = true;

		for (GOAPActionBase* action : node->actionsLeft)
		{
			// we only want to process actions we can do with the current state
			// not necessary but this lowers the number of nodes and
			// connections a whole lot
			if (!CanDoAction(action, node->worldState))
				continue;

			// make a copy of the node's world state to apply this action to
			SymbolMap newMap = node->worldState;
			for (auto const& effect : *action->GetEffects())
				newMap[effect.first] = effect.second;

			// get the node with this world state
			// if one doesn't exist, this function creates it
			GOAPGraphNode* newNode = graph.getNode(newMap);

			// this happens if the action doesn't affect the state, like
			// if an effect of an action is already present in the state
			if (newNode == node)
				continue;

			// this node's actions list is just the current node's one
			// minus the action of this edge
			auto actionsList = node->actionsLeft; // make a copy
			auto actionFind = std::find(actionsList.begin(), actionsList.end(),
				action);
			// this action should always exist since we're literally in the
			// loop of the container we copied, but check just in case
			if (actionFind != actionsList.end())
				actionsList.erase(actionFind);

			newNode->actionsLeft = actionsList;

			// GoapEdge constructor handles giving itself to the node which
			// handles deleting it :)
			GOAPGraphEdge* newEdge = new GOAPGraphEdge(node, newNode, action);

			// grab a reference to the container in the queue so we can nicely
			// use its begin() and end() functions
			auto queueContainer = nodeQueue._Get_container();
			auto nodeFind = std::find(queueContainer.begin(), queueContainer.end(), newNode);

			// check if it was traversed since the node isn't guaranteed to be
			// a newly created one
			if (!newNode->traversed && nodeFind == queueContainer.end())
				nodeQueue.push(newNode);
		}
	}

	// reset all traversed values for use in A*
	for (auto node : graph.nodes)
	node->traversed = false;
	
	return graph;
}

void GOAPPlanner::PrintPlanFromNode(GOAPGraphNode * node)
{
}
