#pragma once
#include "Entity/Character.h"
#include "Entity/Entity resources/SpriteManager.h"
class Player : public Character
{
public:
	Player(Window& window, InputManager& input);
	Player();
	~Player() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void Init() override;
	sf::Sprite* GetPlayer();

private:
	void Input();
	void ValidateMove();
	void Load();

private:
	sf::Vector2f m_NewPosition;
	float m_WalkSpeed;
	float m_DeltaTime;
};

