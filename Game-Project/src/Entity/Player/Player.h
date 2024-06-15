#pragma once
#include "Entity/Character.h"

class Player : public Character
{
public:
	Player(Window& window, InputManager& input);
	~Player() override;
	sf::Sprite* GetPlayer();

	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void Init() override;

private:
	void Input();
	void ValidateMove();
	void CheckColission();

private:
	sf::Vector2f m_NewPosition;
	PlayerAnimation m_Animate;
	sf::Vector2f m_Clamp;

	float m_MovementSpeed;
	float m_DeltaTime;
	bool m_IsColliding;
};

