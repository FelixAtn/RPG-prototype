#pragma once
#include "SFML/Graphics.hpp"

namespace Collision
{
	// AABB COLLISION 
	class Rectangles
	{
	public:
		void Reset();
		bool IsColliding(const sf::Sprite& player, const sf::Sprite& target);
		sf::Vector2f GetVelocity();

	private:
		sf::Vector2f m_Distance;
		sf::Vector2f m_Velocity{ 0.f,0.f };
		sf::Vector2f m_Overlap;
	};

	// CIRCLE COLLISION
	class Circles
	{
	public:
		void Reset();
		bool IsColliding(const sf::Sprite& player, const sf::Sprite& target);
		const float GetRadius(sf::FloatRect player, sf::FloatRect target) const;
		sf::Vector2f GetVelocity();

	private:
		sf::Vector2f m_Distance;
		sf::Vector2f m_Velocity{ 0.f,0.f };
		sf::Vector2f m_Overlap;
	};
};