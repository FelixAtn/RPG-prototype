#pragma once
#include "Entity/Entity resources/Character.h"
#include "Entity/Entity resources/Animator.h"

class Enemy : public Character
{
public:
	Enemy(Window& window, InputManager& input);

	void Init() override;
	void Draw(Window& window) override;
private:
	sf::Texture m_EnemyText;
	sf::Sprite m_Enemy;
};


