#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class PlayerEntity : public Characters
{
public:
	PlayerEntity(Window& window, InputManager& input);
	~PlayerEntity();

	void Init() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	void Input();
	void ValidateMove();

private:
	Window& m_Window;
	InputManager& m_Input;
	Characters m_Character;
	CollisionManager m_Check;

	sf::Vector2f m_CurrentPosition;
	sf::Vector2f m_Move;
	sf::Vector2f m_NewPosition;

	float m_WalkSpeed;
	float m_DeltaTime;

	sf::Texture* text = m_Character.playerText;
	sf::Sprite pla = m_Character.m_Player;
};

