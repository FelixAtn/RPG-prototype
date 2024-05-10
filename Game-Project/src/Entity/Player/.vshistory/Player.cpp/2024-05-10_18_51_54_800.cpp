#include "Player.h"

Player::Player(Window& window, InputManager& m_Input) : m_Input(m_Input), m_Window(window), Character(*m_Player), m_DeltaTime(m_DeltaTime)
{
	Character::Init();
}

Player::~Player()
	{}


void Player::Init()
{
	
}

void Player::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}

void Player::Draw(Window& window)
{
	window.Draw(*m_Player);
}

void Player::Input()
{
	m_Move.x = 0.f;
	m_Move.y = 0.f;
	// Control Player X / Y axis 
	m_WalkSpeed = 500;
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
	sf::Vector2f m_NewPosition = m_CurrentPosition + sf::Vector2f(m_Move);
	this->m_Player->setPosition(m_NewPosition);

	//ValidateMove();
//	m_Input.Clear();
}

void Player::ValidateMove()
{

/*
	// Collision
	if (!m_Check.IsColliding(m_Play, m_Friend) &&
		(!m_Check.IsColliding(m_Player, m_Foe) &&
			(!m_Check.IsColliding(m_Player, m_Foe))))
	{
		m_Player.setPosition(m_NewPosition);
	}
	else
	{
		m_Player.setPosition(m_NewPosition - m_Move);
	}
	*/
}



