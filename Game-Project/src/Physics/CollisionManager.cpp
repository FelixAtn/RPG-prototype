#include "CollisionManager.h"

bool CollisionManager::IsColliding(sf::Sprite& sprite, sf::Sprite& otherSprite)
{
	sf::Vector2f spritePosition = sprite.getPosition();
	sf::Vector2f spriteSize = sprite.getGlobalBounds().getSize() / 2.f;

	sf::Vector2f otherSpritePosition = otherSprite.getPosition();
	sf::Vector2f otherSpriteSize = otherSprite.getGlobalBounds().getSize() / 2.f;

	sf::Vector2f delta = otherSpritePosition - spritePosition;

	sf::Vector2f intersect = sf::Vector2f(std::abs(delta.x) - 
		(spriteSize.x + otherSpriteSize.x), std::abs(delta.y) -
		(spriteSize.y + otherSpriteSize.y));


	return (intersect.x <= 0 && intersect.y <= 0);
}


