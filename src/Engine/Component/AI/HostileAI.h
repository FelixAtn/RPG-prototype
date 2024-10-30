#pragma once

enum class HostileEntityState
{
	IDLE,
	PATROL,
	CHASE,
	ATTACK
};

class HostileAI : public I_Component
{
public:
	HostileAI(float detectionRange = 200.0f, float attackRange = 50.0f);
	void UpdateTarget(const Vector2f& currentPosition, const Vector2f targetPosition);
	void UpdateState(const Vector2f& currentPosition);
	HostileEntityState GetState() const { return m_CurrentState; }
	bool HasTarget() const { return m_HasTarget; }
	const Vector2f& GetTargetPosition() const { return m_TargetPosition; }

private:
	HostileEntityState m_CurrentState;
	float m_DetectionRange;
	float m_AttackRange;
	bool m_HasTarget;
	Vector2f m_TargetPosition;
};

