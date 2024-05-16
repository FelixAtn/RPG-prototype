#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Resources/Loader.h"
#include "Window/Window.h"

//Parent class
class Ability
{
public:
	Ability();
	Ability(sf::Texture& texture);

	virtual void Init() = 0;
	virtual void Update(float& deltaTime) = 0;
	virtual void Draw(Window& window) = 0;

	sf::Sprite& GetAbility();

protected:
	Loader m_Loader;
	sf::Texture m_AbilityText;
	sf::Sprite m_AbilitySprite;

	bool isInit = false;
	float m_WalkSpeed = 200;
	float m_DeltaTime;
};

