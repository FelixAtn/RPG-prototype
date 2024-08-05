#pragma once
#include "Entity.h"

class Npc : public Entity
{
public:
	void UpdateData(Keyboard& input, float deltaTime) override {};
	void Render(Window& window) override {};

};

