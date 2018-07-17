#include "StaticObjectManager.h"
#include <typeinfo>
#include "Grass.h"
#include "Rock.h"
#include "Tree.h"
#include "Construction.h"
#include "Crafter.h"
#include "Forge.h"
#include "Stockpile.h"
#include "Cabin.h"
#include "Hut.h"
#include "Tent.h"

StaticObjectManager* StaticObjectManager::m_pInstance = nullptr;

StaticObjectManager::StaticObjectManager()
{
	m_pGrassContainer = new ObjectContainer<Grass>;
	m_pRockContainer = new ObjectContainer<Rock>;
	m_pTreeContainer = new ObjectContainer<Tree>;
	m_pConstructionContainer = new ObjectContainer<Construction>;
	m_pCrafterContainer = new ObjectContainer<Crafter>;
	m_pForgeContainer = new ObjectContainer<Forge>;
	m_pStockpileContainer = new ObjectContainer<Stockpile>;
	m_pCabinContainer = new ObjectContainer<Cabin>;
	m_pHutContainer = new ObjectContainer<Hut>;
	m_pTentContainer = new ObjectContainer<Tent>;
}


StaticObjectManager::~StaticObjectManager()
{
	delete m_pGrassContainer;
	delete m_pRockContainer;
	delete m_pTreeContainer;
	delete m_pConstructionContainer;
	delete m_pCrafterContainer;
	delete m_pForgeContainer;
	delete m_pStockpileContainer;
	delete m_pCabinContainer;
	delete m_pHutContainer;
	delete m_pTentContainer;
}

void StaticObjectManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new StaticObjectManager();
	}
}

void StaticObjectManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

StaticObjectManager* StaticObjectManager::GetInstance()
{
	return m_pInstance;
}

void StaticObjectManager::Update(float fDeltaTime)
{
	// GRASS
	for (int i = 0; i < m_pGrassContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pGrassContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pGrassContainer->m_ActiveObjects.begin();
			m_pGrassContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pGrassContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// ROCK
	for (int i = 0; i < m_pRockContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pRockContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pRockContainer->m_ActiveObjects.begin();
			m_pRockContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pRockContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// TREE
	for (int i = 0; i < m_pTreeContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pTreeContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pTreeContainer->m_ActiveObjects.begin();
			m_pTreeContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pTreeContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// CONSTRUCTION
	for (int i = 0; i < m_pConstructionContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pConstructionContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pConstructionContainer->m_ActiveObjects.begin();
			m_pConstructionContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pConstructionContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// CRAFTER
	for (int i = 0; i < m_pCrafterContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pCrafterContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pCrafterContainer->m_ActiveObjects.begin();
			m_pCrafterContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pCrafterContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// FORGE
	for (int i = 0; i < m_pForgeContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pForgeContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pForgeContainer->m_ActiveObjects.begin();
			m_pForgeContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pForgeContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// STOCKPILE
	for (int i = 0; i < m_pStockpileContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pStockpileContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pStockpileContainer->m_ActiveObjects.begin();
			m_pStockpileContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pStockpileContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// CABIN
	for (int i = 0; i < m_pCabinContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pCabinContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pCabinContainer->m_ActiveObjects.begin();
			m_pCabinContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pCabinContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
	
	// HUT
	for (int i = 0; i < m_pHutContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pHutContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pHutContainer->m_ActiveObjects.begin();
			m_pHutContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pHutContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
	
	// TENT
	for (int i = 0; i < m_pTentContainer->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pTentContainer->m_ActiveObjects[i];

		// Current is alive
		if (current->GetIsAlive())
		{
			// Update Current
			current->Update(fDeltaTime);
		}
		// ELSE current is NOT alive
		else
		{
			// current is removed from active list
			auto begin = m_pTentContainer->m_ActiveObjects.begin();
			m_pTentContainer->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pTentContainer->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
}

void StaticObjectManager::Draw(aie::Renderer2D* pRenderer)
{
	// GRASS
	for (int i = 0; i < m_pGrassContainer->m_ActiveObjects.size(); ++i)
	{
		m_pGrassContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// ROCK
	for (int i = 0; i < m_pRockContainer->m_ActiveObjects.size(); ++i)
	{
		m_pRockContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// TREE
	for (int i = 0; i < m_pTreeContainer->m_ActiveObjects.size(); ++i)
	{
		m_pTreeContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// CONSTRUCTION
	for (int i = 0; i < m_pConstructionContainer->m_ActiveObjects.size(); ++i)
	{
		m_pConstructionContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// CRAFTER
	for (int i = 0; i < m_pCrafterContainer->m_ActiveObjects.size(); ++i)
	{
		m_pCrafterContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// FORGE
	for (int i = 0; i < m_pForgeContainer->m_ActiveObjects.size(); ++i)
	{
		m_pForgeContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// STOCKPILE
	for (int i = 0; i < m_pStockpileContainer->m_ActiveObjects.size(); ++i)
	{
		m_pStockpileContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// CABIN
	for (int i = 0; i < m_pCabinContainer->m_ActiveObjects.size(); ++i)
	{
		m_pCabinContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// HUT
	for (int i = 0; i < m_pHutContainer->m_ActiveObjects.size(); ++i)
	{
		m_pHutContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// TENT
	for (int i = 0; i < m_pTentContainer->m_ActiveObjects.size(); ++i)
	{
		m_pTentContainer->m_ActiveObjects[i]->Draw(pRenderer);
	}
}

StaticObject* StaticObjectManager::PlaceObject(EStaticObjectType eObjectType, Vector2 v2Pos)
{


	switch (eObjectType)
	{
	// DEFAULT (NOT USED)
	case ESTATICOBJECTTYPE_DEFAULT:
		return nullptr;

	// Grass
	case ESTATICOBJECTTYPE_RESOURCE_OBJECT_GRASS:
		{ // Extra Scope for variables
			auto container = m_pGrassContainer;
			Grass* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Grass;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Rock
	case ESTATICOBJECTTYPE_RESOURCE_OBJECT_ROCK:
		{ // Extra Scope for variables
			auto container = m_pRockContainer;
			Rock* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Rock;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Tree
	case ESTATICOBJECTTYPE_RESOURCE_OBJECT_TREE:
		{ // Extra Scope for variables
			auto container = m_pTreeContainer;
			Tree* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Tree;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Construction (Cant be created alone)
	case ESTATICOBJECTTYPE_BUILDING_CONSTRUCTION:
		return nullptr;

	// Crafter
	case ESTATICOBJECTTYPE_BUILDING_CRAFTER:
		{ // Extra Scope for variables
			auto container = m_pCrafterContainer;
			Crafter* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Crafter;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Forge
	case ESTATICOBJECTTYPE_BUILDING_FORGE:
		{ // Extra Scope for variables
			auto container = m_pGrassContainer;
			Grass* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Grass;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Stockpile
	case ESTATICOBJECTTYPE_BUILDING_STOCKPILE:
		{ // Extra Scope for variables
			auto container = m_pGrassContainer;
			Grass* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Grass;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Cabin
	case ESTATICOBJECTTYPE_BUILDING_HOUSING_CABIN:
		{ // Extra Scope for variables
			auto container = m_pGrassContainer;
			Grass* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Grass;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Hut
	case ESTATICOBJECTTYPE_BUILDING_HOUSING_HUT:
		{ // Extra Scope for variables
			auto container = m_pGrassContainer;
			Grass* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Grass;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// Tent
	case ESTATICOBJECTTYPE_BUILDING_HOUSING_TENT:
		{ // Extra Scope for variables
			auto container = m_pGrassContainer;
			Grass* object = nullptr;

			// IF there are reserve objects
			if (container->m_ReserveObjects.size() > 0)
			{
				// get a reserve object
				object = container->m_ReserveObjects.back();
				container->m_ReserveObjects.pop_back();
			}
			else
			{
				// make a new object
				object = new Grass;
			}

			// Setup object
			object->SetIsAlive(true);
			object->SetPos(v2Pos);

			// Add to active list
			container->m_ActiveObjects.push_back(object);

			return object;
		}
		break;

	// TOTAL (NOT USED)
	case ESTATICOBJECTTYPE_TOTAL:
		return nullptr;
	// Switch DEFAULT (NOT USED)
	default:
		return nullptr;
	}
}

void StaticObjectManager::RemoveObject(StaticObject* object)
{
	auto objectTypeHash = typeid(*object).hash_code();

	// Grass
	if (objectTypeHash == typeid(Grass).hash_code())
	{
		auto polyObject = (Grass*)object;
		auto containerActive = m_pGrassContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pGrassContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Rock
	else if (objectTypeHash == typeid(Rock).hash_code())
	{
		auto polyObject = (Rock*)object;
		auto containerActive = m_pRockContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pRockContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Tree
	else if (objectTypeHash == typeid(Tree).hash_code())
	{
		auto polyObject = (Tree*)object;
		auto containerActive = m_pTreeContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pTreeContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Construction
	else if (objectTypeHash == typeid(Construction).hash_code())
	{
		auto polyObject = (Construction*)object;
		auto containerActive = m_pConstructionContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pConstructionContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Crafter
	else if (objectTypeHash == typeid(Crafter).hash_code())
	{
		auto polyObject = (Crafter*)object;
		auto containerActive = m_pCrafterContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pCrafterContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Forge
	else if (objectTypeHash == typeid(Forge).hash_code())
	{
		auto polyObject = (Forge*)object;
		auto containerActive = m_pForgeContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pForgeContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Stockpile
	else if (objectTypeHash == typeid(Stockpile).hash_code())
	{
		auto polyObject = (Stockpile*)object;
		auto containerActive = m_pStockpileContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pStockpileContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Cabin
	else if (objectTypeHash == typeid(Cabin).hash_code())
	{
		auto polyObject = (Cabin*)object;
		auto containerActive = m_pCabinContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pCabinContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Hut
	else if (objectTypeHash == typeid(Hut).hash_code())
	{
		auto polyObject = (Hut*)object;
		auto containerActive = m_pHutContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pHutContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Tent
	else if (objectTypeHash == typeid(Tent).hash_code())
	{
		auto polyObject = (Tent*)object;
		auto containerActive = m_pTentContainer->m_ActiveObjects;

		for (int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pTentContainer->m_ReserveObjects.push_back(polyObject);
			}
		}
	}
}