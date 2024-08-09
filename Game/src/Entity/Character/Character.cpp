#include "Character.h"


Character::Character()
{
	m_Cooldown = 0.f;
	m_HitBoxRadius = 0;
}

Character::~Character()
{}

void Character::SetName(const std::string& name)
{
	m_Name = name;
}

void Character::Render(Window& window)
{
	window.Render(m_Sprite);
	m_HitBoxComponent.Render(window);
}

void Character::SecondUpdate()
{
	m_HitBoxComponent.Update(GetSpritePosition());
}

void Character::SetCooldown(float coolDown)
{
	m_Cooldown = coolDown;
}

void Character::SetHitBox(float hitBoxRadius)
{
	if (GetHitBoxComponent().IsHitBoxDisplayed())
	{
		m_HitBoxRadius = hitBoxRadius;
		m_HitBoxComponent.Init(m_HitBoxRadius);
	}
}


std::string Character::GetName() const
{
	return m_Name;
}

HitBoxComponent& Character::GetHitBoxComponent()
{
	return m_HitBoxComponent;
}

HealthComponent& Character::GetHealthComponent()
{
	return m_HealthComponent;
}

CombatComponent& Character::GetCombatComponent()
{
	return m_CombatComponent;
}

MovementComponent& Character::GetMovementComponent()
{
	return m_MovementComponent;
}

LevelingComponent& Character::GetLevelComponent()
{
	return m_LevelComponent;
}

float Character::GetCooldown() const
{
	return m_Cooldown;
}

float Character::GetHitBoxRadius() const
{
	return m_HitBoxRadius;
}

