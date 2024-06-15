#pragma once
#include "Entity/Entity resources/Animator.h"

struct PlayerAnimation
{
	PlayerAnimation(sf::Sprite* sprite);
	~PlayerAnimation();

	void Idle(float deltaTime);
	void Attack(float deltaTime);
	void WalkLeft(float deltaTime);
	void WalkRight(float deltaTime);
	void WalkDown(float deltaTime);
	void WalkUp(float deltaTime);

	Animator m_Idle;
 	Animator m_Attack;
 	Animator m_Left;

 	Animator m_Right;
 	Animator m_Up;
 	Animator m_Down;

	float deltaTime;
};

struct EnemyAnimation
{
	EnemyAnimation(sf::Sprite* sprite);
	~EnemyAnimation();

	void Idle(float deltaTime);

	Animator m_Idle;
};