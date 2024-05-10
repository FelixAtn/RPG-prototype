#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class Player : public Character
{
public:
	Player(Window& window, InputManager& input);
	~Player();
	
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void Init() override;

private:
	void Input();
	void ValidateMove();


private:
	Window& m_Window;
	InputManager& m_Input;
	CollisionManager m_Check;
	Character _Character();
	sf::Vector2f m_CurrentPosition;
	sf::Vector2f m_NewPosition;
	sf::Vector2f m_Move;

	sf::Texture m_PlayerText;
	sf::Sprite& m_Player;
	bool isInit = false;
	float m_WalkSpeed = 200;
	float m_DeltaTime;
};

