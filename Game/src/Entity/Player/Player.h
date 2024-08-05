#pragma once
#include "Entity/Character.h"
#include "Entity/Player/Components/PlayerMovementComponent.h"

class Player : public Character
{
public:
	Player(const std::string& playerName, const std::string& playerType);
	~Player() final;

	void UpdateInput(Keyboard& keyboardInput, Mouse& mouseInput, float deltaTime);
	void UpdateAnimation(float deltaTime);
	void UpdateData(Keyboard& input, float deltaTime) final;
	void Render(Window& window) final;
	void SetVelocity(sf::Vector2f velocity);

private:
	PlayerMovementComponent m_Component;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_PlayerPosition{ 0.f, 0.f };
};
