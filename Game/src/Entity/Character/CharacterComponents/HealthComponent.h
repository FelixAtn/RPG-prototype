#pragma once

class HealthComponent
{
public:
	void SetHealth(int health);
	int GetHealth() const;

	void IncreaseHealth(int amount);
	void DecreaseHealth(int amount);

	bool IsAlive() const;

private:
	int m_Health;
	bool m_IsAlive;
};

