#pragma once
#include "Entity/Character/Character.h"
#include "Entity/Character/Player/Components/AnimationComponent.h"
#include "GameStates/StateMachine.h"

class Player : public Character
{
public:
	Player(const std::string& playerName, const std::string& playerType);
	~Player() final {};
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;

private:
	void InitSprite(const std::string& playerType);
	void InitAttributes(const std::string& playerName);
	void Movement(InputManager& input, float deltaTime);
	void Animations(Keyboard& input, float deltaTime);

private:
	AnimationComponent m_Animation;
	StateMachine m_StateMachine;
};
