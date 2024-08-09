#pragma once
#include "Entity/Entity.h"

class Npc : public Entity
{
public:
	void Update(Cursor& cursor, Keyboard& input, float deltaTime) override {};
	void Render(Window& window) override {};

};

