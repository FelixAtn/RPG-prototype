#include "PlayerEntity.h"

PlayerEntity::PlayerEntity(Window& window, InputManager& m_Input) : Character(Character), m_Input(m_Input), m_Window(window)
{
	Init();
}
void PlayerEntity::Init()
{
	m_Loader.Load(m_PlayerText, "Idle-64X128.png");
	m_Init.SetSpriteTexture(m_PlayerText, m_Player);
	m_Init.SetSpriteRect(m_Player, 0, 0, 64, 128);
	m_Init.SetSpriteDefaultPosition(m_Player, 200, 200);
	m_Init.SetSpriteScale(m_Player, 2, 2);
}

void PlayerEntity::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}
void PlayerEntity::Draw(Window& window)
{
	window.Draw(m_Globe);
	window.Draw(m_Player);
}
void PlayerEntity::Input()
{
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
}
void PlayerEntity::ValidateMove()
{
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
	
}

