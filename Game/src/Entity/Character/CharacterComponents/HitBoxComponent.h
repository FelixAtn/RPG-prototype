#pragma once
#include "SFML/Graphics.hpp"
#include "Window/Window.h"

enum class BoxType
{
	Circle,
	Square
};

class HitBoxComponent
{
public:
	HitBoxComponent(sf::Sprite& characterSprite, BoxType type, float circleRadius);
	HitBoxComponent(sf::Sprite& characterSprite, BoxType type);
	void Init();
	void Update();
	void Render(Window& window);
	
	sf::RectangleShape& GetRectangle();
	sf::Vector2f GetHitBoxSquareSize() const;
	float GetHitBoxRadius() const;

	void SetHitBoxRadius(const float& radius);
	void SetHitBoxSquareSize(sf::Vector2f& rectSize);
	void SetHitBoxBounds(sf::FloatRect& rect);

	bool IsHitBoxDisplayed() const;
	void ShouldHitBoxRender(bool isDisplayed);

private:
	BoxType m_HitBoxType;
	sf::Sprite& m_CharacterSprite;
	sf::CircleShape m_CircleHitBox;
	sf::RectangleShape m_SquareHitBox;
	sf::Vector2f m_RectSize;
	sf::FloatRect m_RectBounds;
	float m_Radius;
	bool m_IsDisplayed;
};

