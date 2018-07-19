#include "AgentManager.h"

#include "Agent.h"
#include "AI.h"
#include "Deer.h"

#define RADIUS 16
#define RADIUS_SQR (RADIUS * RADIUS)

AgentManager* AgentManager::m_pInstance = nullptr;

AgentManager::AgentManager()
{
	m_pAIPool = new ObjectPool<AI>;
	m_pDeerPool = new ObjectPool<Deer>;
}


AgentManager::~AgentManager()
{
	delete m_pAIPool;
	delete m_pDeerPool;
}

void AgentManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new AgentManager();
	}
}

void AgentManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

AgentManager* AgentManager::GetInstance()
{
	return m_pInstance;
}

void AgentManager::Update(float fDeltaTime)
{
	// AI
	for (int i = 0; i < m_pAIPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pAIPool->m_ActiveObjects[i];

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
			auto begin = m_pAIPool->m_ActiveObjects.begin();
			m_pAIPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pAIPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}

	// Deer
	for (int i = 0; i < m_pDeerPool->m_ActiveObjects.size(); ++i)
	{
		auto current = m_pDeerPool->m_ActiveObjects[i];

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
			auto begin = m_pDeerPool->m_ActiveObjects.begin();
			m_pDeerPool->m_ActiveObjects.erase(begin + i);
			// current is added to reserve list
			m_pDeerPool->m_ReserveObjects.push_back(current);

			// current is reset
			current->Reset();
		}
	}
}

void AgentManager::Draw(aie::Renderer2D* pRenderer)
{
	// Draw AI
	for (int i = 0; i < m_pAIPool->m_ActiveObjects.size(); ++i)
	{
		m_pAIPool->m_ActiveObjects[i]->Draw(pRenderer);
	}

	// Draw Deer
	for (int i = 0; i < m_pDeerPool->m_ActiveObjects.size(); ++i)
	{
		m_pDeerPool->m_ActiveObjects[i]->Draw(pRenderer);
	}
}

Agent* AgentManager::GetAgentByPos(Vector2 v2Pos, int fRadius)
{
	// Set Default Radius Sqr
	int fRadiusSQR = RADIUS_SQR;

	// Use alternative radius if given
	if (fRadius != 0)
		fRadiusSQR = fRadius * fRadius;

	// Check alive AI
	for (int i = 0; i < m_pAIPool->m_ActiveObjects.size(); ++i)
	{
		Vector2 v2new = v2Pos - m_pAIPool->m_ActiveObjects[i]->GetPos();
		// check distance is within given radius
		if (v2new.magnitudeSqr() < fRadiusSQR)
			// Return Object Found
			return m_pAIPool->m_ActiveObjects[i];
	}

	// Check alive Deer
	for (int i = 0; i < m_pAIPool->m_ActiveObjects.size(); ++i)
	{
		Vector2 v2new = v2Pos - m_pAIPool->m_ActiveObjects[i]->GetPos();
		// check distance is within given radius
		if (v2new.magnitudeSqr() < fRadiusSQR)
			// Return Object Found
			return m_pAIPool->m_ActiveObjects[i];
	}

	// No Agent found near Pos
	return nullptr;
}

AI* AgentManager::AddAI(Vector2 v2Pos)
{
	AI* object;
	auto container = m_pAIPool;
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
		object = new AI;
	}

	// Setup object
	object->SetIsAlive(true);
	object->SetPos(v2Pos);

	// Add to active list
	container->m_ActiveObjects.push_back(object);

	return object;
}

Deer* AgentManager::AddDeer(Vector2 v2Pos)
{
	Deer* object;
	auto container = m_pDeerPool;
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
		object = new Deer;
	}

	// Setup object
	object->SetIsAlive(true);
	object->SetPos(v2Pos);

	// Add to active list
	container->m_ActiveObjects.push_back(object);

	return object;
}
