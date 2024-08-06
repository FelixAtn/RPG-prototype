#pragma once
#include "Entity/Character.h"
#include "Entity/Player/Components/AnimationComponent.h"

class Player : public Character
{
public:
	Player(const std::string& playerName, const std::string& playerType);
	~Player() final {};

	void UpdateData(Keyboard& input, float deltaTime) final;
	void Render(Window& window) final;

	void Movement(InputManager& input, float deltaTime);
	void Animations(Keyboard& input, float deltaTime);
private:
	AnimationComponent m_Animation;
};
