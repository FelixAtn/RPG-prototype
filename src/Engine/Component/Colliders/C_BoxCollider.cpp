#include "stdafx.h"
#include "C_BoxCollider.h"


void C_BoxCollider::Init(sf::Sprite& sprite, const Vector2f& hitboxSize, const Vector2f hitboxOffset /*= Vector2f(0.0f, 0.0f)*/)
{
	m_Sprite = &sprite;
	m_HitBox.setSize(hitboxSize);
	m_HitBox.setFillColor(sf::Color::Transparent);
	m_HitBox.setOutlineColor(sf::Color::Red);
	m_HitBox.setOutlineThickness(1.f);
	m_HitBox.setOrigin(hitboxSize * 0.5f);
}


void C_BoxCollider::Update()
{
	// Position the hitbox at the center of the sprite with any offset
	Vector2f spritePos = m_Sprite->getPosition();
	m_HitBox.setPosition(spritePos + Vector2f(m_Sprite->getGlobalBounds().width * 0.5f, m_Sprite->getGlobalBounds().height * 0.5f) + m_Offset);
}

sf::Vector2f C_BoxCollider::GetCenterRect()
{
	return m_HitBox.getSize() * 0.5f;
}

sf::Vector2f C_BoxCollider::GetPosition()
{
	return m_HitBox.getPosition();
}

bool C_BoxCollider::CheckAndResolve(C_BoxCollider& target, float pushValue)
{
	Vector2f mainMidPoint = GetCenterRect();
	Vector2f mainRectPosition = GetPosition();

	Vector2f targetMidPoint = target.GetCenterRect();
	Vector2f targetPosition = target.GetPosition();

	// Calculate distance between entities(R1 and R2)
	Vector2f delta = targetPosition - mainRectPosition;


	/*
	- Calculate the overlapping by adding the midPoints between entities(R1 and R2),
	- If Delta is a negative number, transform delta into a positive number or 0,
	- Get the total overlap by substracting delta from entities(R1,2).midpoint - SUM
	*/
	float xOverlap = std::abs(delta.x) - (targetMidPoint.x + mainMidPoint.x);
	float yOverlap = std::abs(delta.y) - (targetMidPoint.y + mainMidPoint.y);

	// Check if the entities(R1 and R2) collide by verifying if the overlap is less than 0 - Outcome: True = Collides, False = Not
	if (xOverlap < 0.f && yOverlap < 0.f)
	{
		// the pushValue must be equal to the minimum of the two - X (maximum of pushValue, 0.f) or Y(1.f)
		pushValue = std::min(std::max(pushValue, 0.f), 1.f);

		// Deduct if the collision happens on X OR Y 
		if (xOverlap > yOverlap)
		{
			// Deduct if the collision happens on xMin or xMax of R1
			if (delta.x > 0.f)
			{
				// If the condition -IS- met - The collision happens on xMax of R1 and xMin of R2
				constexpr float unit = 1.f;
				float xMain = xOverlap * (unit - pushValue); // and we push R1 by 
				float yMain = 0.f;
				m_Sprite->move(xMain, yMain);

				// the R2 can be pushed in the opposite direction by R1 if we simply inverse 
				float xTargetPush = -xOverlap * pushValue;
				float yTargetPush = 0.f;
				target.m_Sprite->move(xTargetPush * pushValue, yTargetPush);
			}
			else
			{
				// If the condition -IS NOT- met - The collision happens on xMin of R1 and xMax of R2
				m_Sprite->move(-xOverlap * (1.f - pushValue), 0.f); // and we push R1 by a negative value
				target.m_Sprite->move(xOverlap * pushValue, 0.f);
			}
		}

		// Check if yDelta is positive or negative
		else
		{
			if (delta.y > 0.f)
			{
				m_Sprite->move(0.f, yOverlap * (1.f - pushValue));
				target.m_Sprite->move(0.f, -yOverlap * pushValue);
			}
			else
			{
				m_Sprite->move(0.f, -yOverlap * (1.f - pushValue));
				target.m_Sprite->move(0.f, yOverlap * pushValue);
			}
		}
		return true;
	}
	return false;
}

