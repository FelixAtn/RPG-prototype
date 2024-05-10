#include "PlayerEntity.h"

PlayerEntity::PlayerEntity(Window& window, InputManager& m_Input) : m_Input(m_Input), m_Window(window)
{
	Character.InitPlayer();
	std::cout << "    sdf " << &m_Player;
		
}

PlayerEntity::~PlayerEntity()
	{}


void PlayerEntity::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}

void PlayerEntity::Draw(Window& window)
{
	window.Draw(m_Player);
	//window.Draw(*vec[0]);
}

void PlayerEntity::Input()
{
	m_Move.x = 0.f;
	m_Move.y = 0.f;

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
	m_Input.Clear();

	ValidateMove();
}

void PlayerEntity::ValidateMove()
{
	sf::Vector2f m_NewPosition = m_CurrentPosition + sf::Vector2f(m_Move);
	m_Play.setPosition(m_NewPosition);
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


