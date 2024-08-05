#pragma once
#include "Entity/Npc.h"

class Blacksmith : public Npc
{
public:
	void UpdateData(Keyboard& input, float deltaTime) override {};
	void Render(Window& window) override {};
};

