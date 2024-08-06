#include "Player.h"
#include "iostream"
#include "Resources/GameTools.h"
#include "Physics/VectorMath.h"


Player::Player(const std::string& playerName, const std::string& playerType)
	: m_Animation(GetSprite())
{
	std::cout << "Init: " << playerName << "\n";
	SetName(playerName);
	SetTexture(playerType);
	SetScale(1, 1);
	SetRect(0, 0, 64, 64);
	SetMovementSpeed(80.f);
	SetPosition(200, 500);
}

void Player::UpdateData(Keyboard& input, float deltaTime)
{
	Movement(input, deltaTime);
	Animations(input, deltaTime);
}

void Player::Render(Window& window)
{
	window.Render(m_Sprite); 
}

void Player::Movement(InputManager& input, float deltaTime)
{
	input.Update();
	m_MovementDirection = sf::Vector2f(0.f, 0.f);

	if (input.IsKeyDown(Key::W))
	{
		m_MovementDirection.y -= 1.f;
	}

	if (input.IsKeyDown(Key::S))
	{
		m_MovementDirection.y += 1.f;
	}

	if (input.IsKeyDown(Key::D))
	{
		m_MovementDirection.x += 1.f;
	}

	if (input.IsKeyDown(Key::A))
	{
		m_MovementDirection.x -= 1.f;
	}

	if (m_MovementDirection.x == 0.f && m_MovementDirection.y == 0.f)
	{
		return;
	}

	m_MovementDirection = VectorMath::Math::GetNormalizedVector(m_MovementDirection);
	sf::Vector2f m_PlayerPosition = GetSpritePosition();

	m_PlayerPosition += m_MovementDirection * m_MovementSpeed * deltaTime;
	sf::Vector2f positionAfterMoving = m_PlayerPosition + m_Velocity;

	m_Sprite.setPosition(positionAfterMoving);
	m_Velocity = { 0,0 };
}

void Player::Animations(Keyboard& input, float deltaTime)
{
	bool isAttacking = input.IsKeyPressed(Key::E);
	sf::Vector2f direction = m_MovementDirection;

	m_Animation.MovementAnimation(direction, deltaTime);
	m_Animation.AttackAnimation(isAttacking, deltaTime);
}
