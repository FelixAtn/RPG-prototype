#pragma once
#include "SFML/Graphics.hpp"
#include "Resources/Window/Window.h"
#include "Resources/Loader.h"
#include <vector>

class Character
{
public:
	Character(sf::Texture& texture);
	~Character();
	virtual void Init();
	virtual	void Update(float deltaTime);
	virtual	void Draw(Window& window);

	
public:
	Loader m_Loader;
private:

protected:
	sf::Sprite m_Player;
	
};