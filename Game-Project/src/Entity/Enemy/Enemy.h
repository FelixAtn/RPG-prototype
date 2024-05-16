#pragma once
#include "Entity/Character.h"
#include "Entity/Entity resources/Animator.h"

class Enemy : public Character
{
public:
	Enemy(Window& window, InputManager& input);
	~Enemy() override;
	sf::Sprite* GetEnemy();


	void Init() override;
	void Draw(Window& window) override;
	void Update(float deltaTime) override;

private:
	float m_DeltaTime;
};


