#pragma once


class AttackBehaviour : public I_Component
{
public:
	AttackBehaviour(float attackInterval = 1.0f)
		: m_AttackTimer(attackInterval)
	{}

	bool CanAttack(float deltaTime) { return m_AttackTimer.HasTimePassed(deltaTime); }

private:
	Timer m_AttackTimer;
};

