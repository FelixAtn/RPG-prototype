#include "Player.h"

Player::Player(Window& window, InputManager& inputManager) : Character(window, inputManager)
, m_MovementSpeed(400), m_DeltaTime(0), m_Animate(m_Player), m_IsColliding(false) {}
Player::~Player(){}

// Initializers
void Player::Init()
{
	if (m_Player)
	{
		m_Player->setPosition(700, 700);
		m_Player->scale(1, 1);
	}
}


// Player Engine
void Player::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	m_Animate.Idle(deltaTime);

	CheckColission();
	ValidateMove();
	Input();
}
void Player::Draw(Window& window)
{
	if(m_Player)
	{
	window.Draw(*m_Player);
	}
}
void Player::CheckColission()
{
	std::vector<sf::Sprite*> sprites;
	sprites.push_back(m_Enemy);
	sprites.push_back(m_Blocks);
	sprites.push_back(m_Tiles);

	for (auto& sprite : sprites)
	{
		if (m_Check.IsColliding(*m_Player, *sprite))
		{
			m_IsColliding = true;
			m_Clamp = m_Check.GetClampValue();
		}
	}
}
void Player::ValidateMove()
{
	if(m_IsColliding)
	{
		m_Player->setPosition(m_NewPosition + m_Clamp);
	}
	else 
	{
		m_Player->setPosition(m_NewPosition);
	}
	m_Clamp = { 0,0 };
}
void Player::Input()
{
	sf::Vector2f move(0.f, 0.f);
	sf::Vector2f currentPosition = m_Player->getPosition();


	// Movement
	if (m_Input.IsKeyPressed(Key::Right))
	{
		m_Animate.WalkRight(m_DeltaTime);
		move.x += m_MovementSpeed;	
	}
	else if (m_Input.IsKeyPressed(Key::Left))
	{
		m_Animate.WalkLeft(m_DeltaTime);
		move.x -= m_MovementSpeed;
	}
	if (m_Input.IsKeyPressed(Key::Down))
	{
		m_Animate.WalkDown(m_DeltaTime);
		move.y += m_MovementSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Up))
	{
		m_Animate.WalkUp(m_DeltaTime);
		move.y -= m_MovementSpeed;
	}


	// Actions
	if (m_Input.IsKeyPressed(Key::Click))
	{
		m_Animate.Attack(m_DeltaTime);
	}

	// Calculus
	move *= m_DeltaTime;
	m_NewPosition = currentPosition + move;
}

// Getters, setters
sf::Sprite* Player::GetPlayer()
{
	return m_Player;
}


