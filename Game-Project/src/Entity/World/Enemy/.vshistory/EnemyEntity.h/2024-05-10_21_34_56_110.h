#pragma once
#include "Entity/Entity resources/Character.h"
#include "Entity/Entity resources/Animator.h"

class Enemy : public Character
{
public:
	Enemy();
	Enemy(Window& window, InputManager& input);
	~Enemy();
	void Init() override;
	void Draw(Window& window) override;
	void Update(float deltaTime) override;

protected:
	sf::Vector2f GetEnemyPosition();
	sf::Sprite& GetEnemy();

protected:
	sf::Texture m_EnemyText;
	sf::Sprite m_Enemy;

	float m_DeltaTime;
};


