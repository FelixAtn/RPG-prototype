#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent()
	: m_IsDisplayed(false)
	, m_Radius(0)
{}

void HitBoxComponent::Init(const float& radius)
{
	m_Radius = radius;
	m_HitBox.setFillColor(sf::Color::Transparent);
	m_HitBox.setOutlineColor(sf::Color::Red);
	m_HitBox.setRadius(m_Radius);
	m_HitBox.setOrigin(GetHitBoxRadius(), GetHitBoxRadius());
	m_HitBox.setOutlineThickness(3);
}

void HitBoxComponent::Update(const sf::Vector2f& position)
{
	m_HitBox.setPosition(position);
}

void HitBoxComponent::Render(Window& window)
{
	if(m_IsDisplayed)
	{
		window.Render(m_HitBox);
	}
}

float HitBoxComponent::GetHitBoxRadius() const
{
	return m_Radius;
}

bool HitBoxComponent::IsHitBoxDisplayed() const
{
	return m_IsDisplayed;
}

void HitBoxComponent::SetHitBoxRadius(const float& radius)
{
	m_Radius = radius;
}

void HitBoxComponent::ShouldHitBoxRender(bool isDisplayed)
{
	m_IsDisplayed = isDisplayed;
}
