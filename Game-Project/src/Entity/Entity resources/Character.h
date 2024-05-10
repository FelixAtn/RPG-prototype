#pragma once
#include "Physics/CollisionManager.h"
#include "SFML/Graphics.hpp"
#include "Input/InputManager.h"
#include "Resources/Window/Window.h"
#include "Resources/Loader.h"
#include "iostream"
#include <vector>

class Character
{
public:
	Character();
	Character(sf::Texture& texture);


private:
	sf::Texture m_PlayerText;
	sf::Texture m_EnemyText;

	sf::Sprite m_Player;
	sf::Sprite m_Enemy;
	
protected:
	virtual void Init() = 0;
	virtual	void Update(float deltaTime) = 0;
	virtual	void Draw(Window& window) = 0;

protected:
	Loader m_Loader;
};