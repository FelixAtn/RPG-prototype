#include "stdafx.h"
#include "Player.h"



Player::Player()
{
	m_Sprite = AddComponent<C_Sprite>("player_spritesheet");
	m_Data = AddComponent<C_AttributeData>("PLAYER");
	m_Movement = AddComponent<C_Movement>(*this);
	m_Animation = AddComponent<C_Animation>(*this);
	m_Input = AddComponent<C_InputHandler>(*this);
	m_Collider = AddComponent<C_BoxCollider>();
	m_Collider->Init(m_Sprite->GetSprite(), Vector2f(32, 32));
	m_Data->SetAttackRange(50);
	m_Shoot = AddComponent<C_Shoot>("projectile");
}

void Player::Update(float deltaTime)
{
	m_Input->Update(*this, deltaTime);
	m_Movement->Update(deltaTime);
	m_Animation->Update(deltaTime);
	m_Collider->Update();
	m_Shoot->Update(deltaTime);
}

void Player::HandleCollision(Object& other, float pushValue)
{
	bool isCollidingWithOther = m_Collider->CheckAndResolve(*other.GetComponent<C_BoxCollider>(), pushValue);

	if (!isCollidingWithOther)
	{
		return;
	}
}

void Player::HandleObjectInteractions(Object& other, float deltaTime)
{
	if (InputManager::Get().IsKeyPress(KeyBind::LEFT_CLICK))
	{
		m_Shoot->Shoot(*this, other, deltaTime);
	}
}

void Player::Draw(Window& window)
{
	m_Collider->Draw(window);
	m_Shoot->DrawProjectile(window);
}
