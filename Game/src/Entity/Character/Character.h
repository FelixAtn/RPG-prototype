#pragma once
#include "Entity/Entity.h"
#include "Entity/Character/CharacterComponents/HitBoxComponent.h"
#include "Entity/Character/CharacterComponents/HealthComponent.h"
#include "Entity/Character/CharacterComponents/CombatComponent.h"
#include "Entity/Character/CharacterComponents/MovementComponent.h"
#include "Entity/Character/CharacterComponents/LevelingComponent.h"

class Character : public Entity
{
public:
	Character();
	~Character() override;

	void SetName(const std::string& name);
	void SetCooldown(float coolDown);
	void SetHitBox(float hitBoxRadius);

	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override {};
	void Render(Window& window) override;
	void SecondUpdate();



	std::string GetName() const;

	HitBoxComponent& GetHitBoxComponent();
	HealthComponent& GetHealthComponent();
	CombatComponent& GetCombatComponent();
	MovementComponent& GetMovementComponent();
	LevelingComponent& GetLevelComponent();

	float GetCooldown() const; 


	float GetHitBoxRadius() const;

	template <typename T> static void RemoveCharacter(std::vector<std::unique_ptr<T>>& characters);

protected:
	HitBoxComponent m_HitBoxComponent;
	HealthComponent m_HealthComponent;
	CombatComponent m_CombatComponent;
	MovementComponent m_MovementComponent;
	LevelingComponent m_LevelComponent;

	float m_Cooldown;
	float m_HitBoxRadius;
};

template <typename T>
bool IsDead(const std::unique_ptr<T>& character)
{
	return !character->GetHealthComponent().IsAlive();
}

template <typename T>
void Character::RemoveCharacter(std::vector<std::unique_ptr<T>>& characters)
{
	characters.erase(
		std::remove_if(characters.begin(), characters.end(), IsDead<T>),
		characters.end()
	);
}