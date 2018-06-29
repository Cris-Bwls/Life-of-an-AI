#include <crtdbg.h>

#include "ofMain.h"
#include "ofApp.h"

#include "goapaction.h"
#include "goapplanner.h"

class GetAxeAction : public GoapAction
{
public:
	GetAxeAction() : GoapAction()
	{
		m_preconditions["axeAvailable"] = true;
		m_effects["hasAxe"] = true;

		m_name = "Get Axe";
	}
};

class ChopLogAction : public GoapAction
{
public:
	ChopLogAction() : GoapAction()
	{
		m_preconditions["hasAxe"] = true;
		m_effects["hasWood"] = true;

		m_name = "Chop Log";
	}
};

class CollectBranchesAction : public GoapAction
{
public:
	CollectBranchesAction() : GoapAction()
	{
		m_effects["hasWood"] = true;

		m_name = "Collect Branches";

		m_cost = 3.0f;
	}
};

class CollectFlintAction : public GoapAction
{
public:
	CollectFlintAction() : GoapAction()
	{
		m_preconditions["flintAvailable"] = true;
		m_effects["hasFlint"] = true;

		m_name = "Collect Flint";
	}
};

class MakeFireAction : public GoapAction
{
public:
	MakeFireAction() : GoapAction()
	{
		m_preconditions["hasFlint"] = true;
		m_preconditions["hasWood"] = true;
		m_effects["hasFire"] = true;

		m_name = "Light Fire";
	}
};

class GetWaterAction : public GoapAction
{
public:
	GetWaterAction() : GoapAction()
	{
		m_preconditions["waterAvailable"] = true;
		m_effects["hasWater"] = true;

		m_name = "Collect Water";
	}
};

class BoilWaterAction : public GoapAction
{
public:
	BoilWaterAction() : GoapAction()
	{
		m_preconditions["hasFire"] = true;
		m_preconditions["hasWater"] = true;
		m_effects["hasBoilingWater"] = true;

		m_name = "Boil Water";
	}
};

class GetNoodlesAction: public GoapAction
{
public:
	GetNoodlesAction() : GoapAction()
	{
		m_preconditions["noodlesAvailable"] = true;
		m_effects["hasUncookedNoodles"] = true;

		m_name = "Collect Noodles";
	}
};

class CookNoodlesAction : public GoapAction
{
public:
	CookNoodlesAction() : GoapAction()
	{
		m_preconditions["hasBoilingWater"] = true;
		m_preconditions["hasUncookedNoodles"] = true;
		m_effects["hasCookedNoodles"] = true;

		m_name = "Cook Noodles";
	}
};

class EatNoodlesAction : public GoapAction
{
public:
	EatNoodlesAction() : GoapAction()
	{
		m_preconditions["hasCookedNoodles"] = true;
		m_effects["hasCookedNoodles"] = false;
		m_effects["isHungry"] = false;

		m_name = "Eat Noodles";
	}
};

//========================================================================
int main( ){
	//At start of main()
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GoapPlanner planner;

	//make our world state
	std::map<std::string, bool> worldState;
	// what do we have
	worldState["isHungry"] = true;

	worldState["hasAxe"] = false;
	worldState["hasFire"] = false;
	worldState["hasWood"] = false;
	worldState["hasFlint"] = false;
	worldState["hasWater"] = false;
	worldState["hasBoilingWater"] = false;
	worldState["hasCookedNoodles"] = false;
	worldState["hasUncookedNoodles"] = false;

	// what's available
	worldState["axeAvailable"] = true;
	worldState["flintAvailable"] = true;
	worldState["waterAvailable"] = true;
	worldState["noodlesAvailable"] = true;

	DArray<GoapAction*> actions;
	actions.add(new GetAxeAction());
	actions.add(new ChopLogAction());
	actions.add(new GetWaterAction());
	actions.add(new MakeFireAction());
	actions.add(new BoilWaterAction());
	actions.add(new EatNoodlesAction());
	actions.add(new GetNoodlesAction());
	actions.add(new CookNoodlesAction());
	actions.add(new CollectFlintAction());
	actions.add(new CollectBranchesAction());

	printf("Making plan to be NOT hungry\n");
	auto plan = planner.makePlan(actions, worldState, "isHungry", false);

	printf("Resulting plan: ");
	while (!plan.isEmpty())
	{
		auto a = plan.pop();
		printf("%s, ", a->getName().c_str());
		delete a;
	}
	printf("\b\b  \n");

	//for (int i = 0; i < actions.getCount(); ++i)
	//	delete actions[i];

	system("pause");
	return 0;

	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
