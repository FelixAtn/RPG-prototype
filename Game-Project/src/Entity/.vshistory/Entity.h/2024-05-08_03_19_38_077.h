#pragma once
#include <Resources/Window/Window.h>
#include <SFML/Graphics.hpp>
#include "Physics/CollisionManager.h"
#include "Entity/Entity resources/Character.h"

class Entity
{
public:
	~Entity();

private:
	void InitCharacters();

protected:
	virtual void Init() = 0;
	virtual	void Update(float deltaTime) = 0;
	virtual void Draw(Window& window) = 0;

private:



protected:
	int a = 1;
};

