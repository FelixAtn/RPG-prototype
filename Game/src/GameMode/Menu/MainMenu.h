#pragma once
#include "GameStates/StateMachine.h"
#include <unordered_map>
#include <vector>
#include "Input/Mouse.h"
#include "UI/button.h"
#include "GameMode/Menu/Menu.h"

class MainMenu : public Menu
{
public:
	MainMenu(StateMachine& state, Window& window);
	
	void Create() override;
	void Destroy() override;
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void Draw(Window& window) override;
	void CheckChosenButton(Cursor& cursor);
};

