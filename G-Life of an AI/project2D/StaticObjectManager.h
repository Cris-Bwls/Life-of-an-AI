#pragma once
#include "Renderer2D.h"
#include "vector"
#include "Vector2.h"
#include "ObjectPool.h"
#include "EStaticObjectType.h"

class StaticObject;
class Grass;
class Rock;
class Tree;
class Construction;
class Crafter;
class Forge;
class Stockpile;
class Cabin;
class Hut;
class Tent;

class StaticObjectManager
{
public:
	static void Create();
	static void Destroy();
	static StaticObjectManager* GetInstance();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	StaticObject* PlaceObject(EStaticObjectType eObjectType, Vector2 v2Pos);

	inline std::vector<Grass*> GetGrassActiveList() { return m_pGrassPool->m_ActiveObjects; };
	inline std::vector<Rock*> GetRockActiveList() { return m_pRockPool->m_ActiveObjects; };
	inline std::vector<Tree*> GetTreeActiveList() { return m_pTreePool->m_ActiveObjects; };
	inline std::vector<Construction*> GetConstructionActiveList() { return m_pConstructionPool->m_ActiveObjects; };
	inline std::vector<Crafter*> GetCrafterActiveList() { return m_pCrafterPool->m_ActiveObjects; };
	inline std::vector<Forge*> GetForgeActiveList() { return m_pForgePool->m_ActiveObjects; };
	inline std::vector<Stockpile*> GetStockpileActiveList() { return m_pStockpilePool->m_ActiveObjects; };
	inline std::vector<Cabin*> GetCabinActiveList() { return m_pCabinPool->m_ActiveObjects; };
	inline std::vector<Hut*> GetHutActiveList() { return m_pHutPool->m_ActiveObjects; };
	inline std::vector<Tent*> GetTentActiveList() { return m_pTentPool->m_ActiveObjects; };

	//DEBUG
	bool bFireExists = false;

private:
	StaticObjectManager();
	~StaticObjectManager();

	static StaticObjectManager* m_pInstance;

	void RemoveObject(StaticObject* object);

	ObjectPool<Grass>*			m_pGrassPool;
	ObjectPool<Rock>*			m_pRockPool;
	ObjectPool<Tree>*			m_pTreePool;
	ObjectPool<Construction>*	m_pConstructionPool;
	ObjectPool<Crafter>*		m_pCrafterPool;
	ObjectPool<Forge>*			m_pForgePool;
	ObjectPool<Stockpile>*		m_pStockpilePool;
	ObjectPool<Cabin>*			m_pCabinPool;
	ObjectPool<Hut>*			m_pHutPool;
	ObjectPool<Tent>*			m_pTentPool;
};

