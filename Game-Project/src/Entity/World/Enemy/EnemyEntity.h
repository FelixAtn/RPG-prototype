#pragma once
#include "Entity/Character.h"
#include "Entity/Entity resources/Animator.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();
	Enemy(Window& window, InputManager& input);

	sf::Sprite& GetEnemy();
	sf::Vector2f GetEnemyPosition();
	
	void Init() override;
	void Draw(Window& window) override;
	void Update(float deltaTime) override;

protected:
	sf::Texture m_EnemyText;
	sf::Sprite m_Enemy;

	bool isInit = false;
	float m_DeltaTime;
};


