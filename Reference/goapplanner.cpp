#include "goapplanner.h"

#include <heap.h>
#include <graph.h>
#include <stack.h>

#include "goapaction.h"

Queue<GoapAction*> GoapPlanner::makePlan(DArray<GoapAction*> availableActions,
	NiceMap worldState, const char* goalKey, bool goalVal)
{
	Queue<GoapAction*> result;

	// let's try to make a tree
	DArray<GoapNode*> tree;
	for (int i = 0; i < availableActions.getCount(); ++i)
	{
		if (!canDoAction(availableActions[i], worldState))
			continue;
		// make a node from this action
		auto node = new GoapNode();
		node->action = availableActions[i];
		node->cost = node->action->getCost();
		node->reached = false;
		node->prev = nullptr;

		auto others = availableActions;
		others.remove(node->action);
		node->otherActions = others;

		node->resultState = worldState;
		applyState(&(node->resultState), node->action->getEffects());

		tree.add(node);

		if (node->resultState[goalKey] == goalVal)
		{
			node->reached = true;
		}
		else
		{
			auto l = processAction(node, goalKey, goalVal);
			for (int j = 0; j < l.getCount(); ++j)
				tree.add(l[j]);
		}
	}

	// (badly) find all nodes at the end of the tree
	DArray<GoapNode*> leaves;
	for (int i = 0; i < tree.getCount(); ++i)
	{
		bool hasLeaf = false;

		for (int j = 0; j < tree.getCount(); ++j)
		{
			if (tree[j]->prev == tree[i])
			{
				hasLeaf = true;
				break;
			}
		}

		if (!hasLeaf)
			leaves.add(tree[i]);
	}

	// grab the cheapest end point 
	auto cheapestLeaf = leaves[0];
	for (int i = 0; i < leaves.getCount(); ++i)
	{
		auto leaf = leaves[i];
		if (leaf->cost < cheapestLeaf->cost)
			cheapestLeaf = leaf;
	}

	// put the action path into a DArray so we can reverse it
	DArray<GoapAction*> reverse;
	while (cheapestLeaf)
	{
		reverse.add(cheapestLeaf->action);
		cheapestLeaf = cheapestLeaf->prev;
	}

	// push that array backwards into the queue
	for (int i = reverse.getCount() - 1; i >= 0; --i)
		result.push(reverse[i]);

	// clean up our tree
	for (int i = 0; i < tree.getCount(); ++i)
		delete tree[i];

	return result;
}

bool GoapPlanner::canDoAction(GoapAction* action, NiceMap worldState)
{
	for (auto a : (*action->getPreconditions()))
		if (worldState[a.first] != a.second)
			return false;
	return true;
}

void GoapPlanner::applyState(NiceMap* applyTo, NiceMap* toApply)
{
	for (auto a : (*toApply))
		(*applyTo)[a.first] = a.second;
}

DArray<GoapNode*> GoapPlanner::processAction(GoapNode* onode, std::string goalKey,
	bool goalVal)
{
	DArray<GoapNode*> result;

	for (int i = 0; i < onode->otherActions.getCount(); ++i)
	{
		if (!canDoAction(onode->otherActions[i], onode->resultState))
			continue;
		// make a node from this action
		auto node = new GoapNode();
		node->action = onode->otherActions[i];
		node->cost = onode->cost + node->action->getCost();
		node->reached = false;
		node->prev = onode;

		auto others = onode->otherActions;
		others.remove(node->action);
		node->otherActions = others;

		node->resultState = onode->resultState;
		applyState(&(node->resultState), node->action->getEffects());

		result.add(node);

		if (node->resultState[goalKey] == goalVal)
		{
			node->reached = true;
		}
		else
		{
			auto l = processAction(node, goalKey, goalVal);
			for (int j = 0; j < l.getCount(); ++j)
				result.add(l[j]);
		}

	}

	return result;
}

DArray<GoapAction*> GoapPlanner::getAvailableActions(DArray<GoapAction*> actions, NiceMap world)
{
	DArray<GoapAction*> result;
	for (int i = 0; i < actions.getCount(); ++i)
	{
		if (canDoAction(actions[i], world))
			result.add(actions[i]);
	}
	return result;
}
