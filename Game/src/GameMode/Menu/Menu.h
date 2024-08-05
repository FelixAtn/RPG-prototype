#pragma once
#include "GameStates/StateMachine.h"
#include <unordered_map>
#include <vector>
#include "Input/Mouse.h"
#include "GameMode/Menu/UI/button.h"

enum class MenuOpt
{
	Play,
	Settings,
	Game,
	Display,
	Audio,
	Keybinds,
	Resolution,
	MaxFPS,
	vSync,
	Back,
	Exit
};

class Menu : public States
{
public:
	Menu(StateMachine& state, Window& window) : m_State(state), m_Window(window) {};
	virtual ~Menu() {};
	void Create() override {};
	void Destroy() override {};

	void UpdateButton(Cursor& cursor) 
	{
		for (const auto& option : m_Button)
		{
			option.second->Update(cursor.GetSprite());
		}
	};

	void DrawButton()
	{
		for (const auto& it : m_Button)
		{
			it.second->Draw(m_Window);
		}
	}

protected:
	sf::Sprite m_Sprite;
	std::unordered_map<MenuOpt, std::unique_ptr<Button>> m_Button;
	sf::Texture m_Texture;
	StateMachine& m_State;
	Window& m_Window;

	float buttonWidth = 0;
	float buttonHeight = 0;
	float xButtonScale = 0;
	float yButtonScale = 0;

};


