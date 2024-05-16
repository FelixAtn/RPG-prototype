#pragma once
#include "Entity/Entity resources/SpriteManager.h"
#include "Window/Window.h"
#include "Input/InputManager.h"
#include "Physics/CollisionManager.h"

class Character
{
public:
	Character();
	Character(Window& window, InputManager& input);
virtual	~Character();

protected:
	sf::Sprite* GetEnemy();
	virtual	void Update(float deltaTime) = 0;
	virtual	void Draw(Window& window) = 0;
	virtual void Init() = 0;
	
protected:
	CollisionManager m_Check;
	SpriteManager& m_SpriteManager;
	InputManager& m_Input;
	Window& m_Window;

	sf::Sprite* m_Player;
	sf::Sprite* m_Enemy;
};