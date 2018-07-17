#pragma once
#include "Renderer2D.h"
#include "vector"
#include "Vector2.h"
#include "ObjectContainer.h"
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

	ObjectContainer<Grass>*			m_pGrassContainer;
	ObjectContainer<Rock>*			m_pRockContainer;
	ObjectContainer<Tree>*			m_pTreeContainer;
	ObjectContainer<Construction>*	m_pConstructionContainer;
	ObjectContainer<Crafter>*		m_pCrafterContainer;
	ObjectContainer<Forge>*			m_pForgeContainer;
	ObjectContainer<Stockpile>*		m_pStockpileContainer;
	ObjectContainer<Cabin>*			m_pCabinContainer;
	ObjectContainer<Hut>*			m_pHutContainer;
	ObjectContainer<Tent>*			m_pTentContainer;
};

