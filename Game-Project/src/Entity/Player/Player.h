#pragma once
#include "Entity/Character.h"
#include "Entity/Entity resources/SpriteManager.h"

class Player : public Character
{
public:
	Player(Window& window, InputManager& input);
	Player();
	~Player() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void Init() override;
	sf::Sprite* GetPlayer();

private:
	void Input();
	void ValidateMove();
	void Load();

	void AnimateIdle();
	void AnimateAttack();
	void AnimateRight();
	void AnimateLeft();
	void AnimateUp();
	void AnimateDown();
	

	
private:
	Animation m_Idle;
	Animation m_Attack;
	Animation m_Left;
	Animation m_Right;
	Animation m_Up;
	Animation m_Down;

	sf::Vector2f m_NewPosition;
	float m_WalkSpeed;
	float m_DeltaTime;
	float m_Timer;
	float m_DrawPerFrame;


	int leftDefault;
	int xLeft;
	sf::IntRect m_IdleRect;
};

