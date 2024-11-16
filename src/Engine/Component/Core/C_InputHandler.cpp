#include "stdafx.h"
#include "C_InputHandler.h"

C_InputHandler::C_InputHandler(Object& object)
	: m_Data(object.GetComponent<C_AttributeData>())
	, m_Movement(object.GetComponent<C_Movement>())
	, m_Animation(object.GetComponent<C_Animation>()) 
{
	if (m_Animation == nullptr || m_Movement == nullptr || m_Data == nullptr)
	{
		Log::Print("InputHandler - failed INIT: Missing components (nullptr)", LogLevel::ERROR_);
		throw std::runtime_error("Input Handler - Missing Components");
	}
}

void C_InputHandler::Update(Object& other, float deltaTime)
{
	Vector2f velocity(0.0f, 0.0f);
	bool isMoving = false;


	if (InputManager::Get().IsKeyDown(KeyBind::A))
	{
		velocity.x -= 1.0f;
		isMoving = true;
	}
	if (InputManager::Get().IsKeyDown(KeyBind::D))
	{
		velocity.x += 1.0f;
		isMoving = true;
	}
	if (InputManager::Get().IsKeyDown(KeyBind::W))
	{
		velocity.y -= 1.0f;
		isMoving = true;
	}
	if (InputManager::Get().IsKeyDown(KeyBind::S))
	{
		velocity.y += 1.0f;
		isMoving = true;
	}

	// Handle action inputs

	if (InputManager::Get().IsKeyPress(KeyBind::RIGHT_CLICK))
	{
		m_Animation->PlayAction(AnimationID::SPELL_ATTACK_RIGHT);
	}
	if (InputManager::Get().IsKeyDown(KeyBind::R))
	{
		m_Animation->PlayAction(AnimationID::BUFF_CAST);
	}

	if (velocity.Length() > 0.0f)
	{
		velocity.Normalize();
		velocity *= m_Data->GetMovementSpeed();
	}

	m_Movement->SetVelocity(velocity);

	// Update animation state based on movement
	m_Animation->UpdateMovementState(isMoving);
}
