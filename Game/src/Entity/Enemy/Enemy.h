#pragma once
#include "Entity/Character.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

class Enemy : public Character
{
public:
	Enemy(const std::string& Name, const std::string& type, float xPos, float yPos);
	void UpdateData(Keyboard& input, float deltaTime) override;
	void Render(Window& window) override;

private:
	sf::RectangleShape m_Hitbox;
};

