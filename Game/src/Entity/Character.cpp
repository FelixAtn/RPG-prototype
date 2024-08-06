#include "Character.h"


Character::Character()
{
	m_MovementDirection = { 0.f, 0.f };
	m_Velocity = { 0.f, 0.f };
	m_Exp =0.f;
	m_Cooldown = 0.f;
	m_Attackspeed = 0.f;
	m_MovementSpeed = 0.f;
	m_Level = 0;
	m_Hp = 0;
	m_Damage = 0;
}

Character::~Character()
{}

#pragma region SETTER

void Character::SetVelocity(sf::Vector2f vel)
{
	m_Velocity = vel;
}

void Character::SetName(const std::string& name)
{
	m_Name = name; 
}
void Character::SetDamage(int damage)
{
	m_Damage = damage;
}
void Character::SetHp(int health)
{
	m_Hp = health;
}

void Character::SetLevel(int level)
{
	m_Level = level;
}

void Character::SetExp(float experience)
{
	m_Exp = experience;
}

void Character::SetCooldown(float coolDown)
{
	m_Cooldown = coolDown;
}

void Character::SetMovementSpeed(float movementSpeed)
{
	m_MovementSpeed = movementSpeed;
}

sf::Vector2f Character::Getvelocity() const
{
	return m_Velocity;
}

void Character::SetAttackSpeed(float attackSpeed)
{
	m_Attackspeed = attackSpeed;
}
#pragma endregion
#pragma region GETTER
std::string Character::GetName() const
{
	return m_Name;
}

int Character::GetDamage() const
{
	return m_Damage;
}

int Character::GetHp() const
{
	return m_Hp;
}

int Character::GetLevel() const
{
	return m_Level;
}

float Character::GetExp() const
{
	return m_Exp;
}

float Character::GetCooldown() const
{
	return m_Cooldown;
}


float Character::GetAttackSpeed() const
{
	return m_Attackspeed;
}

float Character::GetMovementSpeed() const
{
	return m_MovementSpeed;
}
#pragma endregion
