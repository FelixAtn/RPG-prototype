#include "Character.h"
#include "Physics/Math.h"

Character::Character()
	: m_Collider(m_Sprite, 0.2f)
{
	m_Cooldown = 0.f;
}

Character::~Character()
{}

void Character::SetName(const std::string& name)
{
	m_Name = name;
}

void Character::Render(Window& window)
{
	window.Draw(m_Sprite);
}

void Character::SecondUpdate()
{

}

void Character::SetCooldown(float coolDown)
{
	m_Cooldown = coolDown;
}

std::string Character::GetName() const
{
	return m_Name;
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


BoxCollider& Character::GetCollider()
{
	return m_Collider;
}

float Character::GetCooldown() const
{
	return m_Cooldown;
}


