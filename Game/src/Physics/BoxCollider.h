#pragma once
#include "SFML/Graphics.hpp"

class BoxCollider
{
public:
	BoxCollider(sf::Sprite& sprite, float hitBoxSize);
	void CorrectPosition(float xDelta, float yDelta) { m_Sprite.move(xDelta, yDelta); }

	sf::Vector2f GetCenterPositionOfRect() { return m_Sprite.getGlobalBounds().getSize() * m_HitBox; }
	sf::Vector2f GetSpritePosition() { return m_Sprite.getPosition(); }
	bool CheckAndResolve(BoxCollider& target, float pushValue);

private:
	sf::Sprite& m_Sprite;
	float m_HitBox;
};

