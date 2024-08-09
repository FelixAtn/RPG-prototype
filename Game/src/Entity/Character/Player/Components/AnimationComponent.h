#pragma once
#include "Entity/Animation/AnimationManager.h"
#include "Input/Keyboard.h"
#include <unordered_map>

enum class PlayAnimation
{
	none = 0,
	WalkUp, WalkDown, WalkLeft, WalkRight,
	IdleUp, IdleDown, IdleLeft, IdleRight,
	AttackUp, AttackDown, AttackLeft, AttackRight,
	END
};

class AnimationComponent
{
public:
	AnimationComponent(sf::Sprite& target);
	PlayAnimation MapDirection(const sf::Vector2f direction) const;
	void MovementAnimation(const sf::Vector2f& movementDirection, float deltaTime);
	void AttackAnimation(bool isAttacking, float deltaTime);

private:
	void Init(sf::Sprite& target);
	void AddAnimations();

private:
	std::unordered_map<PlayAnimation, std::shared_ptr<AnimationManager>> m_Animation;
	sf::Vector2f m_PreviousDirection;
	PlayAnimation m_AnimationState;
	sf::Sprite& m_Sprite;
};