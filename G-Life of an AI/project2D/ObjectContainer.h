#pragma once
#include<vector>

template<typename T>
struct ObjectContainer
{
	ObjectContainer() {};

	~ObjectContainer()
	{
		while (m_ActiveObjects.size() > 0)
		{
			delete m_ActiveObjects.back();
			m_ActiveObjects.pop_back();
		}

		while (m_ReserveObjects.size() > 0)
		{
			delete m_ReserveObjects.back();
			m_ReserveObjects.pop_back();
		}
	};

	inline int TotalObjects() { return m_ActiveObjects.size() + m_ReserveObjects.size(); };

	std::vector<T*> m_ActiveObjects;
	std::vector<T*> m_ReserveObjects;
};