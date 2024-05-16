#include "PlayerInput.h"
// 
// void PlayerInput::Input(float deltaTime, sf::Sprite* sprite)
// {
// 	sf::Vector2f m_CurrentPosition = sprite->getPosition();
// 	sf::Vector2f move;
// 	move.x = 0.f;
// 	move.y = 0.f;
// 	sf::Vector2f newPosition;
// 
// 	float m_WalkSpeed = 500.f;
// 
// 	
// 	// Control Player X / Y axis 
// 	if (m_Input.IsKeyPressed(Key::Right))
// 	{
// 		move.x = +m_WalkSpeed;
// 	}
// 	else if (m_Input.IsKeyPressed(Key::Left))
// 	{
// 		move.x = -m_WalkSpeed;
// 	}
// 	if (m_Input.IsKeyPressed(Key::Down))
// 	{
// 		move.y = +m_WalkSpeed;
// 	}
// 	else if (m_Input.IsKeyPressed(Key::Up))
// 	{
// 		move.y = -m_WalkSpeed;
// 	}
// 
// 	move *= deltaTime;
// 	newPosition = m_CurrentPosition + sf::Vector2f(move);
// 	m_Player->setPosition(m_NewPosition);
// 	m_Input.Clear();
// }
