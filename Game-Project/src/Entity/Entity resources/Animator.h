#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Entity/Character.h>

struct AnimationFrame
{
	sf::IntRect m_IntRect;
	float m_Duration; // seconds
};
class Animation 
{
public:
	Animation(sf::Sprite* sprite);
	virtual ~Animation(); 

	void Update(float deltaTime);
	void AddIntRect(AnimationFrame&& m_IntRect);
	const double GetTime() const;

private:

	std::vector<AnimationFrame> m_AnimationRect; // 1
	float m_Timer; // 2
	float m_IntRectLenght; // 3
	sf::Sprite& m_Sprite; // 4
};









