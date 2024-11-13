#include "stdafx.h"
#include "PatrolBehaviour.h"

RandomGenerator PatrolBehaviour::s_Random;

PatrolBehaviour::PatrolBehaviour(Object& object, float radius /*= 100.0f*/, float updateInterval /*= 3.0f*/)
	: m_Data(object.GetComponent<C_AttributeData>())
	, m_Sprite(object.GetComponent<C_Sprite>())
	, m_PatrolRadius(radius)
	, m_PatrolTimer(updateInterval)
	
{
	if (m_Data == nullptr)
	{
		Log::Print("AI PATROL - failed INIT: Missing components (nullptr)", LogLevel::ERROR_);
		throw std::runtime_error("AI PATROL - Missing Components");
	}

	m_PatrolPoint = GetRandomPatrolPoint(Vector2f());
	
}

Vector2f PatrolBehaviour::UpdatePatrol(float deltaTime)
{
	Vector2f currentPosition = m_Sprite->GetSprite().getPosition();
	float movementSpeed = m_Data->GetMovementSpeed();

	if (m_PatrolTimer.HasTimePassed(deltaTime))
	{
		m_PatrolPoint = GetRandomPatrolPoint(currentPosition);
	}

	Vector2f toPatrol = m_PatrolPoint - currentPosition;
	
	if (toPatrol.Length() > 5.0f)
	{
		return toPatrol.Normalize() * (movementSpeed * 0.5f);
	}
	return Vector2f(0.0f, 0.0f);
}

Vector2f PatrolBehaviour::GetRandomPatrolPoint(const Vector2f& currentPosition) const
{
	float angle = s_Random.GetRandomFloat(0, 2 * PI);
	float distance = s_Random.GetRandomFloat(0, m_PatrolRadius);
	Vector2f offset
	(
		std::cos(angle) * distance,
		std::sin(angle) * distance
	);

	return currentPosition + offset;
}


