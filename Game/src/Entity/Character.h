#pragma once
#include "Entity.h"

class Character : public Entity
{
public:
	Character();
	~Character() override;

	void UpdateData(Keyboard& input, float deltaTime) override {};
	void Render(Window& window) override {};

	void SetName(const std::string& name); 
	void SetDamage(int damage); 
	void SetHp(int health); 
	void SetLevel(int level); 
	void SetExp(float experience);
	void SetCooldown(float coolDown); 
	void SetAttackSpeed(float attackSpeed); 
	void SetMovementSpeed(float movementSpeed); 

	std::string GetName() const; 
	int GetDamage() const; 
	int GetHp() const; 
	int GetLevel() const;
	float GetExp() const; 
	float GetCooldown() const; 
	float GetAttackSpeed() const;
	float GetMovementSpeed() const;

protected:
	sf::Vector2f m_Velocity;
	float m_Exp;
	float m_Cooldown;
	float m_Attackspeed;
	float m_MovementSpeed;
	int m_Level;
	int m_Hp;
	int m_Damage;
};
