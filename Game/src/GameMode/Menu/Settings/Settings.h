#pragma once
#include "GameMode/Menu/Menu.h"


class Settings : public Menu
{
public:
	Settings(StateMachine& state, Window& window);
	virtual ~Settings() {};
	void Create() override;
	void Destroy() override;
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void Render(Window& window) override;
	void CheckChosenButton(Cursor& cursor);
};