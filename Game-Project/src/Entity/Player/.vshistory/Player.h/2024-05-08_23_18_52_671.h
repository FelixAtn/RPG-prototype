#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class PlayerEntity : public Characters
{
public:
	PlayerEntity(Window& window, InputManager& input);
	~PlayerEntity();
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
	sf::Vector2f m_Move;
	sf::Vector2f m_NewPosition;

	sf::Sprite* m_LocalPlayer;

	float m_WalkSpeed;
	float m_DeltaTime;

	Characters Character;

};

