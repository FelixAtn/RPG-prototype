#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class Player : Character
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

	sf::Texture m_PlayerText;
	sf::Sprite m_Player;


	int m_WalkSpeed;
	float m_DeltaTime;
};

