#include "HitBoxComponent.h"
#include "Physics/Math.h"

HitBoxComponent::HitBoxComponent(sf::Sprite& characterSprite, BoxType type)
    : m_CharacterSprite(characterSprite)
	, m_HitBoxType(type)
	, m_IsDisplayed(true)
	, m_Radius(0)
	, m_RectSize(0.f, 0.f)
{
	Init();
}


HitBoxComponent::HitBoxComponent(sf::Sprite& characterSprite, BoxType type /*= BoxType::Square*/, float circleRadius)
	: m_CharacterSprite(characterSprite)
	, m_HitBoxType(type)
	, m_IsDisplayed(true)
	, m_Radius(0)
	, m_RectSize(0.f, 0.f)
{

}

void HitBoxComponent::Init()
{
	if (m_HitBoxType == BoxType::Circle)
	{
		m_CircleHitBox.setFillColor(sf::Color::Transparent);
		m_CircleHitBox.setOutlineColor(sf::Color::Red);
		m_CircleHitBox.setRadius(m_Radius);
		m_CircleHitBox.setOrigin(m_Radius, m_Radius);
		m_CircleHitBox.setOutlineThickness(1);
	}

	else if(m_HitBoxType == BoxType::Square)
	{
		m_SquareHitBox.setFillColor(sf::Color::Transparent);
		m_SquareHitBox.setOutlineColor(sf::Color::Blue);
		m_SquareHitBox.setOutlineThickness(3);
	}
};

void HitBoxComponent::Update()
{
	if(m_HitBoxType == BoxType::Circle)
	{
		m_CircleHitBox.setPosition(m_CharacterSprite.getPosition());
	}

	if(m_HitBoxType == BoxType::Square)
	{
		m_SquareHitBox.setSize(m_RectSize);
		m_SquareHitBox.setPosition(m_CharacterSprite.getPosition());
		m_SquareHitBox.setOrigin(m_RectSize * 0.5f);
	}
}

void HitBoxComponent::Render(Window& window)
{
	if(m_IsDisplayed && m_HitBoxType == BoxType::Circle)
	{
		window.Draw(m_CircleHitBox);
	}
	window.Draw(m_SquareHitBox);
}


sf::RectangleShape& HitBoxComponent::GetRectangle()
{
	return m_SquareHitBox;
}

float HitBoxComponent::GetHitBoxRadius() const
{
	return m_Radius;
}

sf::Vector2f HitBoxComponent::GetHitBoxSquareSize() const
{
	return m_RectSize;
}

bool HitBoxComponent::IsHitBoxDisplayed() const
{
	return m_IsDisplayed;
}

void HitBoxComponent::SetHitBoxRadius(const float& radius)
{
	m_Radius = radius;
}

void HitBoxComponent::SetHitBoxSquareSize(sf::Vector2f& rectSize)
{
	m_RectSize = rectSize;
}


void HitBoxComponent::SetHitBoxBounds(sf::FloatRect& rect)
{
	m_RectBounds = rect;
}

void HitBoxComponent::ShouldHitBoxRender(bool isDisplayed)
{
	m_IsDisplayed = isDisplayed;
}
