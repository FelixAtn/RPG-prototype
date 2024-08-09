#pragma once

class CharacterBehaviour
{
public:
	virtual void IncreaseHealth();
	virtual void IncreaseDamage();
	virtual void IncreaseExperience();
	virtual void IncreaseLevel();

	virtual void OnLevelUp();
	virtual void OnAttack();
	virtual void OnDeath();
	virtual void OnHeal();

private:

};

