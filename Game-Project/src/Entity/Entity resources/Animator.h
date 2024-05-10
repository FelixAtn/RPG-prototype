#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Entity/Entity resources/Character.h>

enum class CharacterState
{
	// currently capacity of 16 bits. -> see m_Frames in 
	Idle = 0,
	WalkRight,
	WalkLeft,
	WalkDown,
	WalkUp,
	Roll,
	Crouch
};

class Animation 
{
public:
	Animation(int x, int y, int width, int height);
	void ApplyAnimationToSprite();
	void Update(float deltaTime);

private:
	void Advance();
public:

private:
	int nFrame;
	float holdTime = 0.1f;
//	sf::IntRect frames[size];
	int iFrame = 0;
	float time = 0.0f;

};









// class Animator
// {
// public:
// 	Animator();
// 	~Animator();
// 	void UpdateAnimation(float deltaTime, sf::Sprite& sprite);
// 
// private:
// 	void InitAnimations();
// 	void GetCurrentState();
// 	void ResetState();
// 
// public:
// 	bool isIdle = true;
// private:
// 	CharacterState currentCharacter;
// 
// 	uint8_t m_CurrentCharacterState;
// 	uint8_t m_NewCharacterState;
// 	std::vector<sf::IntRect> m_IdleState;
// 
// 	float m_Duration;
// 	int m_CurrentFrame = 0;
// };

