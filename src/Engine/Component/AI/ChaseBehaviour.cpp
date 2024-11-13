#include "stdafx.h"
#include "ChaseBehaviour.h"

ChaseBehaviour::ChaseBehaviour(Object& object)
	: m_Data(object.GetComponent<C_AttributeData>())
	, m_Sprite(object.GetComponent<C_Sprite>())
	, m_Movement(object.GetComponent<C_Movement>())
{
	if (m_Data == nullptr || m_Sprite == nullptr || m_Movement == nullptr)
	{
		Log::Print("AI PATROL - failed INIT: Missing components (nullptr)", LogLevel::ERROR_);
		throw std::runtime_error("AI PATROL - Missing Components");
	}
}

Vector2f ChaseBehaviour::Update(Object& other)
{
	
	C_Sprite* otherSprite = other.GetComponent<C_Sprite>();

	Vector2f spritePosition = m_Sprite->GetSprite().getPosition();
	Vector2f targetPosition = otherSprite->GetSprite().getPosition();

	Vector2f toTarget = targetPosition - spritePosition;
	float speed = m_Data->GetMovementSpeed();
	if (toTarget.Length() > 0)
	{
		return toTarget.Normalize() * speed;
	}

	return Vector2f(0.0f, 0.0f);
	
}
