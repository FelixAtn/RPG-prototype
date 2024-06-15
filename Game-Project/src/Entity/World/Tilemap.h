#pragma once
#include "Entity/Character.h"
#include "Entity/Player/Player.h"

class Tilemap : Character
{
public:
	Tilemap(Window& window, InputManager& input);
	~Tilemap() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void Init() override;

	float y = 0;
	float x = 0;
};

