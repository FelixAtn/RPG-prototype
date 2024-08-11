#include "BoxCollider.h"

BoxCollider::BoxCollider(sf::Sprite& sprite, float hitBoxSize)
	: m_Sprite(sprite)
	, m_HitBox(hitBoxSize)
{

}

bool BoxCollider::CheckAndResolve(BoxCollider& target, float pushValue)
{
	sf::Vector2f mainMidPoint = GetCenterPositionOfRect();
	sf::Vector2f mainRectPosition = GetSpritePosition();

	sf::Vector2f targetMidPoint = target.GetCenterPositionOfRect();
	sf::Vector2f targetPosition = target.GetSpritePosition();

	// Calculate distance between entities(R1 and R2)
	float xDelta = targetPosition.x - mainRectPosition.x;
	float yDelta = targetPosition.y - mainRectPosition.y;

	// Calculate the overlapping by adding the midPoints between entities(R1 and R2), 
	// If Delta is a negative number, transform xDelta into a positive number or 0,
	// Get the total overlap by substracting delta from entities(R1,2).midpoint - SUM
	float xOverlap = std::abs(xDelta) - (targetMidPoint.x + mainMidPoint.x);
	float yOverlap = std::abs(yDelta) - (targetMidPoint.y + mainMidPoint.y);

	// Check if the entities(R1 and R2) collide by verifying if the overlap is less than 0 - Outcome: True = Collides, False = Not
	if (xOverlap < 0.f && yOverlap < 0.f)
	{
		// the pushValue must be equal to the minimum of the two - X (maximum of pushValue, 0.f) or Y(1.f)
		pushValue = std::min(std::max(pushValue, 0.f), 1.f);

		// Deduct if the collision happens on X OR Y 
		if (xOverlap > yOverlap)
		{
			// Deduct if the collision happens on xMin or xMax of R1
			if (xDelta > 0.f)
			{
				// If the condition -IS- met - The collision happens on xMax of R1 and xMin of R2
				constexpr float unit = 1.f;
				float xMain = xOverlap * (unit - pushValue); // and we push R1 by 
				float yMain = 0.f;
				CorrectPosition(xMain, yMain); 

				// the R2 can be pushed in the opposite direction by R1 if we simply inverse 
				float xTargetPush = -xOverlap * pushValue;
				float yTargetPush = 0.f;
				target.CorrectPosition(xTargetPush * pushValue, yTargetPush);
			}
			else
			{
				// If the condition -IS NOT- met - The collision happens on xMin of R1 and xMax of R2
				CorrectPosition(-xOverlap * (1.f - pushValue), 0.f); // and we push R1 by a negative value
				target.CorrectPosition(xOverlap * pushValue, 0.f);
			}
		}

		// Check if yDelta is positive or negative
		else
		{
			if (yDelta > 0.f)
			{
				CorrectPosition(0.f, yOverlap * (1.f - pushValue));
				target.CorrectPosition(0.f, -yOverlap * pushValue);
			}
			else
			{
				CorrectPosition(0.f, -yOverlap * (1.f - pushValue));
				target.CorrectPosition(0.f, yOverlap * pushValue);
			}
		}
		return true;
	}
	return false;
}