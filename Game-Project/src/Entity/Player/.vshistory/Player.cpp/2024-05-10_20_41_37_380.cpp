#include "Player.h"

Player::Player(Window& window, InputManager& inputManager) :Character(m_PlayerText), m_Input(inputManager), m_Window(window), m_DeltaTime(m_DeltaTime)
{

}
Player::~Player()
{

}

void Player::Init()
{
	isInit = true;
	if (isInit)
	{
		m_Loader.Load(m_PlayerText, "mobss.png");
		m_Player.setTexture(m_PlayerText);
		m_Player.setPosition(600, 600);
		m_Player.setTextureRect(sf::IntRect(0, 0, 80, 80));
		m_Player.setScale(1, 1);
	}
}

void Player::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}

void Player::Draw(Window& window)
{
	window.Draw(m_Player);
}

void Player::Input()
{
	m_Input.Update();
	m_Move.x = 0.f;
	m_Move.y = 0.f;
	m_WalkSpeed = 500;

	m_CurrentPosition = m_Player.getPosition();
	// Control Player X / Y axis 
	if (m_Input.IsKeyPressed(Key::Right))
	{
		m_Move.x = +m_WalkSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Left))
	{
		m_Move.x = -m_WalkSpeed;
	}
	if (m_Input.IsKeyPressed(Key::Down))
	{
		m_Move.y = +m_WalkSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Up))
	{
		m_Move.y = -m_WalkSpeed;
	}

	m_Move *= m_DeltaTime;
	m_NewPosition = m_CurrentPosition + sf::Vector2f(m_Move);
	m_Player.setPosition(m_NewPosition);

	ValidateMove();
//	m_Input.Clear();
}

void Player::ValidateMove()
{
	
//	&& (!m_Check.IsColliding(m_Player, m_Foe) &&
	//		(!m_Check.IsColliding(m_Player, m_Foe)))

	// Collision
	sf::Vector2f enemyPosition = m_Enemy.GetEnemyPosition();
	sf::Sprite enemy = m_Enemy.GetEnemy();
	if (m_Check.IsColliding(m_Player, enemy) )
	{
		m_Player.setPosition(m_NewPosition);
	}
	else
	{
		m_Player.setPosition(m_NewPosition - m_Move);
	}
	
}



