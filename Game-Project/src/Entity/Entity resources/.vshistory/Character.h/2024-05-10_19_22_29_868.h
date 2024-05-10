#pragma once
#include "SFML/Graphics.hpp"
#include "Resources/Window/Window.h"
#include "Resources/Loader.h"
#include "iostream"
#include <vector>

class Character
{
public:
	Character(sf::Sprite* sprite); 
	Character();
	~Character();
	virtual void Init() = 0;
	virtual	void Update(float deltaTime) = 0;
	virtual	void Draw(Window& window) = 0;

	void InitPlayer();
	void InitEnemy();
	
	
public:
	Loader m_Loader;
private:
	sf::Texture m_PlayerText;
	sf::Texture m_EnemyText;

	sf::Sprite* m_Player;
	sf::Sprite m_Enemy;
	
	bool m_IsInit;
protected:
	
};