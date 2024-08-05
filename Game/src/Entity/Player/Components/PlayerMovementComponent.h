#pragma once
#include "SFML/Graphics.hpp"
#include "Input/Keyboard.h"
#include "Entity/Animation/AnimationManager.h"
#include <unordered_map>

enum class AnimationState
{
	none = 0,
	WalkUp, WalkDown, WalkLeft, WalkRight,
	IdleUp, IdleDown, IdleLeft, IdleRight,
	AttackUp, AttackDown, AttackLeft, AttackRight

};

enum AnimationType
{
	WalkUp, WalkDown, WalkLeft, WalkRight,
	IdleUp, IdleDown, IdleLeft, IdleRight,
	AttackUp, AttackDown, AttackLeft, AttackRight
};


class PlayerMovementComponent
{
public:
	PlayerMovementComponent(sf::Sprite& target);
	void UpdateInput(Keyboard& input, sf::Vector2f& velocity, float movementSpeed, float deltaTime);
	void UpdateAnimation(float deltaTime);

private:
	void InitStateVector(sf::Sprite& target);
	void AddAnimations();

private:
	std::vector<AnimationManager> m_AnimationStates;
	AnimationState m_AnimationState;
	AnimationState m_AnimationType;
	sf::Sprite& m_Sprite;
};