#include "stdafx.h"
#include "HostileAI.h"

HostileAI::HostileAI(float detectionRange /*= 200.0f*/, float attackRange /*= 50.0f*/)
	: m_CurrentState(HostileEntityState::IDLE)
	, m_DetectionRange(detectionRange)
	, m_AttackRange(attackRange)
	, m_HasTarget(false)
{}

void HostileAI::UpdateTarget(const Vector2f& currentPosition, const Vector2f targetPosition)
{
	m_HasTarget = false;
	float nearestDistance = m_DetectionRange;

	Vector2f characterPosition(targetPosition);
	float distance = (characterPosition - currentPosition).Length();

	if (distance < nearestDistance)
	{
		m_HasTarget = true;
		m_TargetPosition = characterPosition;
		nearestDistance = distance;
	}
}

void HostileAI::UpdateState(const Vector2f& currentPosition)
{
	if (!m_HasTarget)
	{
		m_CurrentState = HostileEntityState::PATROL;
		return;
	}

	float distanceToTarget = (m_TargetPosition - currentPosition).Length();
	if (distanceToTarget <= m_AttackRange)
	{
		m_CurrentState = HostileEntityState::ATTACK;
	}
	else if (distanceToTarget <= m_DetectionRange)
	{
		m_CurrentState = HostileEntityState::CHASE;
	}
	else
	{
		m_CurrentState = HostileEntityState::PATROL;
	}
}
