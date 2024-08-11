#include "CombatComponent.h"
#include "Entity/Character/Character.h"

void CombatComponent::SetDamage(int damageAmount)
{
	m_Damage = damageAmount;
}

void CombatComponent::SetDamageMultiplier(int level)
{
	m_DamageMultiplier = 1.25f * level;
}

void CombatComponent::SetAttackSpeed(float attackSpeed)
{
	m_Attackspeed = attackSpeed;
}

void CombatComponent::Attack(Character& target) const 
{
	// TODO: CHARACTERS WILL EVENTUALLY HAVE DEFENSE, THEREFORE,  damage - defense.
	float damage = m_Damage * m_DamageMultiplier;
	std::cout << "\n\n MY LEVEL IS: " <<  " " << " AND MY DAMAGE IS: " << damage;
	target.GetHealthComponent().DecreaseHealth(damage);
}

int CombatComponent::GetDamage() const
{
	return m_Damage;
}

float CombatComponent::GetAttackSpeed() const
{
	return m_Attackspeed;
}

int CombatComponent::GetDamageMultiplier() const
{
	return static_cast<int>(m_DamageMultiplier);
}
