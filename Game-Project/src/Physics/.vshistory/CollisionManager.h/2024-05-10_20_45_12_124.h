#pragma once
#include "SFML/Graphics.hpp"
#include "Entity/Player/Player.h"
#include "Entity/World/Enemy/EnemyEntity.h"

class CollisionManager
{
public:
	bool IsColliding(sf::Sprite& sprite, sf::Sprite& otherSprite);

private:
	Player m_Player;
	Enemy m_Enemy;
};

