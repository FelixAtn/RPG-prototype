#pragma once
#include "GameMode/Menu/Menu.h"

class GameSettings : public Menu
{
public:
	GameSettings(StateMachine& state, Window& window);
	virtual ~GameSettings() {};
	void Create() override;
	void Destroy() override;
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void Draw(Window& window) override;
	void CheckChosenButton(Cursor& cursor);
};