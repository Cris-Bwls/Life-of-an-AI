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

	inline std::vector<Grass*> GetGrassActiveList() { return m_pGrassContainer->m_ActiveObjects; };
	inline std::vector<Rock*> GetRockActiveList() { return m_pRockContainer->m_ActiveObjects; };
	inline std::vector<Tree*> GetTreeActiveList() { return m_pTreeContainer->m_ActiveObjects; };
	inline std::vector<Construction*> GetConstructionActiveList() { return m_pConstructionContainer->m_ActiveObjects; };
	inline std::vector<Crafter*> GetCrafterActiveList() { return m_pCrafterContainer->m_ActiveObjects; };
	inline std::vector<Forge*> GetForgeActiveList() { return m_pForgeContainer->m_ActiveObjects; };
	inline std::vector<Stockpile*> GetStockpileActiveList() { return m_pStockpileContainer->m_ActiveObjects; };
	inline std::vector<Cabin*> GetCabinActiveList() { return m_pCabinContainer->m_ActiveObjects; };
	inline std::vector<Hut*> GetHutActiveList() { return m_pHutContainer->m_ActiveObjects; };
	inline std::vector<Tent*> GetTentActiveList() { return m_pTentContainer->m_ActiveObjects; };

private:
	StaticObjectManager();
	~StaticObjectManager();

	static StaticObjectManager* m_pInstance;

	void RemoveObject(StaticObject* object);

	ObjectPool<Grass>*			m_pGrassContainer;
	ObjectPool<Rock>*			m_pRockContainer;
	ObjectPool<Tree>*			m_pTreeContainer;
	ObjectPool<Construction>*	m_pConstructionContainer;
	ObjectPool<Crafter>*		m_pCrafterContainer;
	ObjectPool<Forge>*			m_pForgeContainer;
	ObjectPool<Stockpile>*		m_pStockpileContainer;
	ObjectPool<Cabin>*			m_pCabinContainer;
	ObjectPool<Hut>*			m_pHutContainer;
	ObjectPool<Tent>*			m_pTentContainer;
};

