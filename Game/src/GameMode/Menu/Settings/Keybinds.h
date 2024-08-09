#pragma once
#include "GameMode/Menu/Menu.h"
enum class KeybindsMenu
{

};

class Keybinds : Menu
{
public:
	Keybinds(StateMachine& state, Window& window);
	virtual ~Keybinds();

	void Create() override;
	void Destroy() override;
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void Render(Window& window) override;
	void CheckChosenButton(Cursor& cursor);
};

