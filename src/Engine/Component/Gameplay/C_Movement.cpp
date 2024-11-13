#include "stdafx.h"
#include "C_Movement.h"

C_Movement::C_Movement(Object& object)
	: m_Sprite(object.GetComponent<C_Sprite>())
	, m_Data(object.GetComponent<C_AttributeData>())
	, m_DirectionOffset(0,0)
	, m_Velocity(0,0)
	, m_PreviousVelocity(0,0)
	, m_TargetVelocity(0,0)
	, m_CurrentDirection(Direction::DOWN)
	, m_PreviousDirection(Direction::DOWN)
	, m_MaxSpeed(0)
{
	if (m_Sprite == nullptr || m_Data == nullptr)
	{
		Log::Print("Movement - failed INIT: Missing components (nullptr)", LogLevel::ERROR_);
		throw std::runtime_error("Movement - Missing Components");
	}
	m_MaxSpeed = m_Data->GetMovementSpeed();
}

void C_Movement::Update(float deltaTime)
{
		Vector2f currentPosition = m_Sprite->GetSprite().getPosition(); // Get the current position

		if (m_Velocity.Length() > m_MaxSpeed) // Clamp velocity to max speed
		{
			m_Velocity = m_Velocity.Normalize() * m_MaxSpeed;
		}

		Vector2f newPosition = currentPosition + (m_Velocity * deltaTime);
		m_DirectionOffset = newPosition - currentPosition;
		m_Sprite->GetSprite().setPosition(newPosition);
		UpdateDirection();
}

void C_Movement::UpdateDirection()
{
	if (m_Velocity.Length() > 0.0f)
	{
		m_PreviousDirection = m_CurrentDirection;

		float angle = std::atan2(m_Velocity.y, m_Velocity.x) * 180.0f / PI;

		if (angle >= -45.0f && angle < 45.0f)
		{
			m_CurrentDirection = Direction::RIGHT;
		}
		else if (angle >= 45.0f && angle < 135.0f)
		{
			m_CurrentDirection = Direction::DOWN;
		}
		else if (angle >= -135.0f && angle < -45.0f)
		{
			m_CurrentDirection = Direction::UP;
		}
		else
		{
			m_CurrentDirection = Direction::LEFT;
		}
	}
}

void C_Movement::SetVelocity(Vector2f velocity)
{
	m_PreviousVelocity = m_Velocity;
	m_Velocity = velocity;

	if (m_Velocity.Length() > m_MaxSpeed)
	{
		m_Velocity = m_Velocity.Normalize() * m_MaxSpeed;
	}

	UpdateDirection();
}
