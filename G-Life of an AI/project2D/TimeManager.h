#pragma once
class TimeManager
{
public:
	static void Create();
	static void Destroy();
	static TimeManager* GetInstance();

	void SetTime(float fDeltaTime);
	void ResetGameTime();

	float GetDeltaTime();
	float GetGameTime();

private:
	TimeManager();
	~TimeManager();

	static TimeManager* m_pInstance;

	float m_fdeltaTime;
	float m_fGameTime;
};

