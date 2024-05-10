#pragma once
#include <Resources/Window/Window.h>
#include <SFML/Graphics.hpp>
#include "Physics/CollisionManager.h"
#include "Entity/Entity resources/Characters.h"

class Entity
{
public:
	Entity(Characters* m_Obj);
	~Entity();

private:
	void InitCharacters();

protected:
	virtual void Init() = 0;
	virtual	void Update(float deltaTime) = 0;
	virtual void Draw(Window& window) = 0;

private:
	Characters* m_Obj;

protected:
	std::vector<sf::Sprite> m_Character;
	std::vector<sf::Sprite> m_Projectile;

	sf::Sprite World1;
	sf::Sprite Player;
	sf::Sprite Friend;
	sf::Sprite Enemy;
	sf::Sprite m_Globe;
};

