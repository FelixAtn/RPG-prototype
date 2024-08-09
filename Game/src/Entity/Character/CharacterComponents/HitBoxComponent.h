#pragma once
#include "SFML/Graphics.hpp"
#include "Window/Window.h"

class HitBoxComponent
{
public:
	HitBoxComponent();
	void Init(const float& radius);
	void Update(const sf::Vector2f& position);
	void Render(Window& window);
	float GetHitBoxRadius() const;
	bool IsHitBoxDisplayed() const;
	void SetHitBoxRadius(const float& radius);
	void ShouldHitBoxRender(bool isDisplayed);

private:
	sf::CircleShape m_HitBox;
	float m_Radius;
	bool m_IsDisplayed;
};

