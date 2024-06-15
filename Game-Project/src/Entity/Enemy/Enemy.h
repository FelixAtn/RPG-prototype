#pragma once
#include "Entity/Character.h"


class Enemy : public Character
{
public:
	Enemy(Window& window, InputManager& input);
	~Enemy() override;

	void Init() override;
	void Draw(Window& window) override;
	void Update(float deltaTime) override;

private:
	EnemyAnimation m_Idle;

	float m_DeltaTime;

};


