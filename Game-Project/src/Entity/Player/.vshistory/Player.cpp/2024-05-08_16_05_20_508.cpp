#include "PlayerEntity.h"

PlayerEntity::PlayerEntity(Window& window, InputManager& m_Input) : m_Input(m_Input), m_Window(window), m_Character(m_Character)
{ 
	m_Foe.setTexture(*playerText);
	m_Foe.setTextureRect(sf::IntRect(0, 0, 80, 80));
	m_Foe.setPosition(sf::Vector2f(300, 300));
	m_Foe.scale(1, 1);
}

PlayerEntity::~PlayerEntity(){}

void PlayerEntity::Init()
{
	
}

void PlayerEntity::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}
void PlayerEntity::Draw(Window& window)
{
//	window.Draw(m_Globe);
	window.Draw(m_Foe);
}
void PlayerEntity::Input()
{/*
	m_Input.Update();
	m_WalkSpeed = 800.f;
	m_CurrentPosition = m_Player.getPosition();
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
	*/
}


void PlayerEntity::ValidateMove()
{
	/*
	sf::Vector2f m_NewPosition = m_CurrentPosition + sf::Vector2f(m_Move);
	m_Player.setPosition(m_NewPosition);
	// Collision
	if (!m_Check.IsColliding(m_Player, m_Friend) &&
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
