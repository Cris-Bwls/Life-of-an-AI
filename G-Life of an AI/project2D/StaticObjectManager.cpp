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
	m_pGrassPool = new ObjectPool<Grass>;
	m_pRockPool = new ObjectPool<Rock>;
	m_pTreePool = new ObjectPool<Tree>;
	m_pConstructionPool = new ObjectPool<Construction>;
	m_pCrafterPool = new ObjectPool<Crafter>;
	m_pForgePool = new ObjectPool<Forge>;
	m_pStockpilePool = new ObjectPool<Stockpile>;
	m_pCabinPool = new ObjectPool<Cabin>;
	m_pHutPool = new ObjectPool<Hut>;
	m_pTentPool = new ObjectPool<Tent>;
}


StaticObjectManager::~StaticObjectManager()
{
	delete m_pGrassPool;
	delete m_pRockPool;
	delete m_pTreePool;
	delete m_pConstructionPool;
	delete m_pCrafterPool;
	delete m_pForgePool;
	delete m_pStockpilePool;
	delete m_pCabinPool;
	delete m_pHutPool;
	delete m_pTentPool;
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
	for (unsigned int i = 0; i < m_pGrassPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pGrassPool->m_ActiveObjects[i];

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
			auto begin = m_pGrassPool->m_ActiveObjects.begin();
			m_pGrassPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pGrassPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// ROCK
	for (unsigned int i = 0; i < m_pRockPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pRockPool->m_ActiveObjects[i];

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
			auto begin = m_pRockPool->m_ActiveObjects.begin();
			m_pRockPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pRockPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// TREE
	for (unsigned int i = 0; i < m_pTreePool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pTreePool->m_ActiveObjects[i];

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
			auto begin = m_pTreePool->m_ActiveObjects.begin();
			m_pTreePool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pTreePool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// CONSTRUCTION
	for (unsigned int i = 0; i < m_pConstructionPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pConstructionPool->m_ActiveObjects[i];

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
			auto begin = m_pConstructionPool->m_ActiveObjects.begin();
			m_pConstructionPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pConstructionPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// CRAFTER
	for (unsigned int i = 0; i < m_pCrafterPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pCrafterPool->m_ActiveObjects[i];

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
			auto begin = m_pCrafterPool->m_ActiveObjects.begin();
			m_pCrafterPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pCrafterPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// FORGE
	for (unsigned int i = 0; i < m_pForgePool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pForgePool->m_ActiveObjects[i];

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
			auto begin = m_pForgePool->m_ActiveObjects.begin();
			m_pForgePool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pForgePool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// STOCKPILE
	for (unsigned int i = 0; i < m_pStockpilePool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pStockpilePool->m_ActiveObjects[i];

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
			auto begin = m_pStockpilePool->m_ActiveObjects.begin();
			m_pStockpilePool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pStockpilePool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// CABIN
	for (unsigned int i = 0; i < m_pCabinPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pCabinPool->m_ActiveObjects[i];

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
			auto begin = m_pCabinPool->m_ActiveObjects.begin();
			m_pCabinPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pCabinPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
	
	// HUT
	for (unsigned int i = 0; i < m_pHutPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pHutPool->m_ActiveObjects[i];

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
			auto begin = m_pHutPool->m_ActiveObjects.begin();
			m_pHutPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pHutPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
	
	// TENT
	for (unsigned int i = 0; i < m_pTentPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pTentPool->m_ActiveObjects[i];

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
			auto begin = m_pTentPool->m_ActiveObjects.begin();
			m_pTentPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pTentPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
}

void StaticObjectManager::Draw(aie::Renderer2D* pRenderer)
{
	// GRASS
	for (unsigned int i = 0; i < m_pGrassPool->m_ActiveObjects.size(); ++i)
	{
		m_pGrassPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// ROCK
	for (unsigned int i = 0; i < m_pRockPool->m_ActiveObjects.size(); ++i)
	{
		m_pRockPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// TREE
	for (unsigned int i = 0; i < m_pTreePool->m_ActiveObjects.size(); ++i)
	{
		m_pTreePool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// CONSTRUCTION
	for (unsigned int i = 0; i < m_pConstructionPool->m_ActiveObjects.size(); ++i)
	{
		m_pConstructionPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// CRAFTER
	for (unsigned int i = 0; i < m_pCrafterPool->m_ActiveObjects.size(); ++i)
	{
		m_pCrafterPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// FORGE
	for (unsigned int i = 0; i < m_pForgePool->m_ActiveObjects.size(); ++i)
	{
		m_pForgePool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// STOCKPILE
	for (unsigned int i = 0; i < m_pStockpilePool->m_ActiveObjects.size(); ++i)
	{
		m_pStockpilePool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// CABIN
	for (unsigned int i = 0; i < m_pCabinPool->m_ActiveObjects.size(); ++i)
	{
		m_pCabinPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// HUT
	for (unsigned int i = 0; i < m_pHutPool->m_ActiveObjects.size(); ++i)
	{
		m_pHutPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// TENT
	for (unsigned int i = 0; i < m_pTentPool->m_ActiveObjects.size(); ++i)
	{
		m_pTentPool->m_ActiveObjects[i]->Draw(pRenderer);
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
			auto container = m_pGrassPool;
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
			object->Reset();
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
			auto container = m_pRockPool;
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
			auto container = m_pTreePool;
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
			auto container = m_pCrafterPool;
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
			auto container = m_pGrassPool;
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
			auto container = m_pGrassPool;
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
			auto container = m_pGrassPool;
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
			auto container = m_pGrassPool;
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
			auto container = m_pGrassPool;
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
		auto containerActive = m_pGrassPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pGrassPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Rock
	else if (objectTypeHash == typeid(Rock).hash_code())
	{
		auto polyObject = (Rock*)object;
		auto containerActive = m_pRockPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pRockPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Tree
	else if (objectTypeHash == typeid(Tree).hash_code())
	{
		auto polyObject = (Tree*)object;
		auto containerActive = m_pTreePool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pTreePool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Construction
	else if (objectTypeHash == typeid(Construction).hash_code())
	{
		auto polyObject = (Construction*)object;
		auto containerActive = m_pConstructionPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pConstructionPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Crafter
	else if (objectTypeHash == typeid(Crafter).hash_code())
	{
		auto polyObject = (Crafter*)object;
		auto containerActive = m_pCrafterPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pCrafterPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Forge
	else if (objectTypeHash == typeid(Forge).hash_code())
	{
		auto polyObject = (Forge*)object;
		auto containerActive = m_pForgePool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pForgePool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Stockpile
	else if (objectTypeHash == typeid(Stockpile).hash_code())
	{
		auto polyObject = (Stockpile*)object;
		auto containerActive = m_pStockpilePool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pStockpilePool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Cabin
	else if (objectTypeHash == typeid(Cabin).hash_code())
	{
		auto polyObject = (Cabin*)object;
		auto containerActive = m_pCabinPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pCabinPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Hut
	else if (objectTypeHash == typeid(Hut).hash_code())
	{
		auto polyObject = (Hut*)object;
		auto containerActive = m_pHutPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pHutPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}

	// Tent
	else if (objectTypeHash == typeid(Tent).hash_code())
	{
		auto polyObject = (Tent*)object;
		auto containerActive = m_pTentPool->m_ActiveObjects;

		for (unsigned int i = 0; i < containerActive.size(); ++i)
		{
			if (polyObject == containerActive[i])
			{
				polyObject->Reset();

				containerActive.erase(containerActive.begin() + i);
				m_pTentPool->m_ReserveObjects.push_back(polyObject);
			}
		}
	}
}