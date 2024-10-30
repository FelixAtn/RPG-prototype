#pragma once

class C_AttributeData : public I_Component
{
public:
	C_AttributeData(const std::string& objectName);

	inline void SetName(const std::string& name) { m_Name = name; }
	inline void SetDamage(float damage) { m_Damage = damage; }
	inline void SetHealth(float health) { m_Health = health; }
	inline void SetMovementSpeed(float speed) { m_MovementSpeed = speed; }
	inline void SetLevel(int level) { m_Level = level; }
	inline void SetExperience(float experience) { m_Experience = experience; }
	inline void SetCooldown(float cooldown) { m_Cooldown = cooldown; }
	inline void SetAttackRange(float attackRange) { m_AttackRange = attackRange; }

	inline const std::string& GetName() const { return m_Name; }
	inline float GetDamage() const { return m_Damage; }
	inline float GetHealth() const { return m_Health; }
	inline float GetCooldown() const { return m_Cooldown; }
	inline float GetMovementSpeed() const { return m_MovementSpeed; }
	inline float GetLuck() const { return m_Luck; }
	inline float GetExperience() const { return m_Experience; }
	inline float GetAttackRange() const { return m_AttackRange; }
	inline int GetLevel() const { return m_Level; }

	const bool IsDead() const { return m_Health <= 0; }

private:
	std::string m_Name;
	float m_Damage;
	float m_Health;
	float m_Cooldown;
	float m_MovementSpeed;
	float m_Luck;
	float m_Experience;
	float m_AttackRange;
	int m_Level;
};