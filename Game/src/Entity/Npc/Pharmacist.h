#pragma once
#include "Entity/Npc.h"

class Pharmacist : public Npc
{
public:
	void UpdateData(Keyboard& input, float deltaTime) override {};
	void Render(Window& window) override {};
};

