#include "Player.h"
#include "iostream"
#include "Resources/GameTools.h"

Player::Player(const std::string& playerName, const std::string& playerType)
	: m_Animation(GetSprite())
{
	InitSprite(playerType);
	InitAttributes(playerName);
}

void Player::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	Movement(keyboard, deltaTime);
	Animations(keyboard, deltaTime);
	SecondUpdate();
}

void Player::InitSprite(const std::string& playerType)
{
	SetTexture(playerType);
	SetRect(0, 0, 64, 64);
	SetPosition(200, 300);
	SetOrigin(GetSpriteCenter().x, GetSpriteCenter().y);
}

void Player::InitAttributes(const std::string& playerName)
{
	std::cout << "Init: " << playerName << "\n";
	SetName(playerName);
	GetLevelComponent().SetLevel(3);
	GetMovementComponent().SetMovementSpeed(100.f);
	GetCombatComponent().SetDamage(10);
	GetCombatComponent().SetDamageMultiplier(GetLevelComponent().GetLevel());
	GetHealthComponent().SetHealth(100);
}

void Player::Movement(InputManager& input, float deltaTime)
{
	GetMovementComponent().SetMovementDirection(sf::Vector2f(0,0));
	sf::Vector2f move = { 0.f, 0.f };

	if (input.IsKeyDown(Key::W))
	{
		move.y -= 1.f;
	}

	if (input.IsKeyDown(Key::S))
	{
		move.y += 1.f;
	}

	if (input.IsKeyDown(Key::D))
	{
		move.x += 1.f;
	}

	if (input.IsKeyDown(Key::A))
	{
		move.x -= 1.f;
	}

	if (move.x == 0.f && move.y == 0.f)
	{
		return;
	}

	GetMovementComponent().SetMovementDirection(move);
	GetMovementComponent().Move(GetSprite(), deltaTime);
}
void Player::Animations(Keyboard& input, float deltaTime)
{
	bool isAttacking = input.IsKeyPressed(Key::E);
	sf::Vector2f direction = GetMovementComponent().GetMovementDirection();
	m_Animation.MovementAnimation(direction, deltaTime);
	m_Animation.AttackAnimation(isAttacking, deltaTime);
}

