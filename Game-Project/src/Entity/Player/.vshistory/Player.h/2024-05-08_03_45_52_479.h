#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class PlayerEntity : public Characters
{
public:
	PlayerEntity(Window& window, InputManager& input);
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	void Init() override;
	void Input();
	void ValidateMove();

private:
	Window& m_Window;
	InputManager& m_Input;
	Characters Character;
	CollisionManager m_Check;


	sf::Vector2f m_CurrentPosition;
	sf::Vector2f m_Move;
	sf::Vector2f m_NewPosition;
	sf::IntRect pl;

	float m_WalkSpeed;
	float m_DeltaTime;
};

