#include "goapplanner.h"

#include <heap.h>

#include "goapaction.h"

GoapPlanner::~GoapPlanner()
{
	for (GoapAction* a : m_actions)
		delete a;
}

std::queue<GoapAction*> GoapPlanner::makePlan(std::string const& goalKey,
	bool goalVal) const
{
	GoapGraph graph = makeGraph();

	GoapNode* root = graph.rootNode;
	root->previous = root;
	root->fScore = 0.0f;
	root->gScore = 0.0f;
	root->hScore = 0.0f;

	Heap<GoapNode*> nodeHeap;
	nodeHeap.setCompareFunction([](auto a, auto b)
	{
		return a->fScore < b->fScore;
	});

	nodeHeap.push(root);

	while (nodeHeap.getCount() > 0)
	{
		GoapNode* node = nodeHeap.pop();

		node->traversed = true;

		for (auto edge : node->edgesFrom)
		{
			GoapNode* other = edge->to;

			if (other->traversed)
				continue;

			float cost = edge->action->getRunningCost();

			// just doing dijkstra's for now
			float newScore = node->gScore + cost;

			if (newScore > other->fScore)
				continue;

			other->gScore = newScore;
			other->fScore = newScore;
			other->hScore = newScore;

			// point to the currently processing node
			other->previous = node;
			// keep track of the action so it's less work to extract the
			// plan from the graph
			other->prevAction = edge->action;

			// terribly check if the node's already in the heap to be processed
			bool inHeap = false;
			for (int i = 0; i < nodeHeap.getCount(); ++i)
			{
				if (nodeHeap[i] == other)
				{
					inHeap = true;
					break;
				}
			}

			// if it's not, stick it on!
			if (!inHeap)
				nodeHeap.push(other);
		}
	}

	// let's grab the cheapest node that results in the state we want
	GoapNode* endPoint = nullptr;
	float cheapestScore = INFINITY;
	for (auto node : graph.nodes)
	{
		if (node->worldState[goalKey] == goalVal &&
			node->fScore < cheapestScore)
		{
			endPoint = node;
			cheapestScore = node->fScore;
		}
	}

	std::queue<GoapAction*> result;

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
	std::vector<GoapAction*> path;
	while (endPoint->previous != endPoint)
	{
		path.push_back(endPoint->prevAction);
		endPoint->prevAction->setStatus(ACTION_NOT_RUNNING);

		endPoint = endPoint->previous;
	}

	// push it into the queue backwards so it's in the right order
	for (int i = path.size() - 1; i >= 0; --i)
		result.push(path[i]);

	return result;
}

void GoapPlanner::addAction(GoapAction* action)
{
	m_actions.push_back(action);
}

void GoapPlanner::setState(StateMap const& newState)
{
	m_worldState = newState;
}

bool GoapPlanner::canDoAction(GoapAction* action, StateMap& state) const
{
	for (auto p : *action->getPreconditions())
		if (state[p.first] != p.second)
			return false;
	return true;
}

GoapGraph GoapPlanner::makeGraph() const
{
	GoapGraph graph;
	GoapNode* rootNode = graph.getNode(m_worldState);
	rootNode->actionsLeft = m_actions;

	std::queue<GoapNode*> nodeQueue;
	nodeQueue.push(rootNode);

	while (!nodeQueue.empty())
	{
		GoapNode* node = nodeQueue.front();
		nodeQueue.pop();

		node->traversed = true;

		for (GoapAction* action : node->actionsLeft)
		{
			// we only want to process actions we can do with the current state
			// not necessary but this lowers the number of nodes and
			// connections a whole lot
			if (!canDoAction(action, node->worldState))
				continue;

			// make a copy of the node's world state to apply this action to
			StateMap newMap = node->worldState;
			for (auto const& effect : *action->getEffects())
				newMap[effect.first] = effect.second;

			// get the node with this world state
			// if one doesn't exist, this function creates it
			GoapNode* newNode = graph.getNode(newMap);

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
			GoapEdge* newEdge = new GoapEdge(node, newNode, action);

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

void GoapPlanner::printPlanFromNode(GoapNode* node) const
{
	std::vector<GoapAction*> actions;

	// backtrack and put all actions into a vector
	GoapNode* thisNode = node;
	while (thisNode != thisNode->previous)
	{
		actions.push_back(thisNode->prevAction);
		thisNode = thisNode->previous;
	}

	printf(" => ");

	// and then print it backwards
	for (int i = actions.size() - 1; i >= 0; --i)
		printf("%s -> ", actions[i]->getName().c_str());

	// delete the trailing arrow and spaces
	printf("\b\b\b\b    \n");
}
