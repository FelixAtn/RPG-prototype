#pragma once
#include "Entity/Entity resources/SpriteManager.h"
#include "Window/Window.h"
#include "Input/InputManager.h"
#include "Physics/CollisionManager.h"
#include "Entity/Entity resources/SpriteAnimation.h"

class Character
{
public:
	Character(Window& window, InputManager& input);
	virtual	~Character();

protected:
	virtual	void Update(float deltaTime) = 0;
	virtual	void Draw(Window& window) = 0;
	virtual void Init() = 0;
	
protected:
	SpriteManager& m_SpriteManager;
	CollisionManager m_Check;
	InputManager& m_Input;
	Window& m_Window;

	sf::Sprite* m_Player;
	sf::Sprite* m_Enemy;

	sf::Sprite* m_Tiles;
	sf::Sprite* m_Blocks;

	std::vector<sf::Sprite*> m_TileTest;
};