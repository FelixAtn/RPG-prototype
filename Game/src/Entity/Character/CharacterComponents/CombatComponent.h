#pragma once
class Character;

class CombatComponent
{
public:

	int GetDamage() const;
	float GetAttackSpeed() const;
	int GetDamageMultiplier() const;
	void SetDamage(int damageAmount);
	void SetDamageMultiplier(int level);

	void SetAttackSpeed(float attackSpeed);
	void Attack(Character& target);

private:
	int m_Damage;
	float m_DamageMultiplier;
	float m_Attackspeed;

};

