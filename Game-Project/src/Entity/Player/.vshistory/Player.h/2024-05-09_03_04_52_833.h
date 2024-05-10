#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class Player
{
public:
	Player(Window& window, InputManager& input);
	~Player();

	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	void Input();
	void ValidateMove();

private:
	Window& m_Window;
	InputManager& m_Input;
	CollisionManager m_Check;

	sf::Vector2f m_CurrentPosition;
	sf::Vector2f m_NewPosition;
	sf::Vector2f m_Move;

	float m_DeltaTime;
};

