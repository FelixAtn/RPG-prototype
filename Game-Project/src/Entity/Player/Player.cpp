#include "Player.h"
#include <math.h>

Player::Player(Window& window, InputManager& inputManager) : Character(window, inputManager){}
Player::~Player()
{

}

void Player::Init()
{
	Load();
}
void Player::Update(float deltaTime)
{
	Character::Update(deltaTime);
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}
void Player::Draw(Window& window)
{
	if(m_Player)
	{
	window.Draw(*m_Player);
	}
}
void Player::Input()
{
	sf::Vector2f move(0.f, 0.f);
	sf::Vector2f currentPosition = m_Player->getPosition();

	m_WalkSpeed = 500;
	if (m_Input.IsKeyPressed(Key::Right))
		move.x = +m_WalkSpeed;
	else if (m_Input.IsKeyPressed(Key::Left))
		move.x = -m_WalkSpeed;
	if (m_Input.IsKeyPressed(Key::Down))
		move.y = +m_WalkSpeed;
	else if (m_Input.IsKeyPressed(Key::Up))
		move.y = -m_WalkSpeed;
	
	move *= m_DeltaTime;
	m_NewPosition = currentPosition + move;
}
void Player::ValidateMove()
{
	if (!m_Check.IsColliding(*m_Player, *m_Enemy))
	{ 
		m_Player->setPosition(m_NewPosition);
	}
	else
	{
		{
			--m_NewPosition.x;
			--m_NewPosition.y;
		}
		sf::Vector2f currentPosition = m_Player->getPosition();
 		sf::Vector2f collisionDirection = m_NewPosition - m_Enemy->getPosition();
		sf::Vector2f PushPosition = m_NewPosition;
		m_Player->setPosition(m_NewPosition);
	}
}
void Player::Load()
{
	if (m_Player)
	{
		m_Player->setPosition(700, 700);
		m_Player->setTextureRect(sf::IntRect(0, 0, 80, 80));
		m_Player->setScale(1, 1);
	}
}
sf::Sprite* Player::GetPlayer()
{
	return m_Player;
}


