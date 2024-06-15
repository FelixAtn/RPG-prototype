#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct AnimationFrame
{
	sf::IntRect m_IntRect;
	float m_Duration; // seconds
};

class Animator
{
public:
	Animator(sf::Sprite* sprite);
	virtual ~Animator(); 

	void Update(float deltaTime);
	void AddIntRect(AnimationFrame&& m_IntRect);
	const double GetTime() const;

private:

	std::vector<AnimationFrame> m_AnimationRect; // 1
	float m_Timer; // 2
	float m_IntRectLenght; // 3
	sf::Sprite& m_Sprite; // 4
};









