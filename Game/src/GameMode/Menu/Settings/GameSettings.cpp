#include "GameMode/Menu/Settings/GameSettings.h"

GameSettings::GameSettings(StateMachine& state, Window& window) : Menu(state, window)
{}

void GameSettings::Create()
{
	buttonWidth = 100.f;
	buttonHeight = 100.f;
	xButtonScale = 0.6f;
	yButtonScale = 0.6f;

	m_Button.reserve(5);
	m_Button[MenuOpt::Game] = std::make_unique<Button>("GAME", buttonWidth, buttonHeight, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Display] = std::make_unique<Button>("DISPLAY", buttonWidth, buttonHeight * 2, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Audio] = std::make_unique<Button>("AUDIO", buttonWidth, buttonHeight * 3, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Keybinds] = std::make_unique<Button>("KEYBINDS", buttonWidth, buttonHeight * 4, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Back] = std::make_unique<Button>("BACK", buttonWidth, buttonHeight * 7, xButtonScale, yButtonScale);
}

void GameSettings::Destroy()
{
	m_Button.clear();
}

void GameSettings::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	UpdateButton(cursor);
	CheckChosenButton(cursor);
}

void GameSettings::Draw(Window& window)
{
	window.Render(m_Sprite);
	DrawButton();
}

void GameSettings::CheckChosenButton(Cursor& cursor)
{
	for (const auto& [MenuOpt, button] : m_Button)
	{
		if (button->IsCursorOn() && cursor.IsKeyPressed(MouseKey::LEFT_CLICK))
		{
			switch (MenuOpt)
			{
			case MenuOpt::Game:
				break;
			case MenuOpt::Display:
				m_State.SwitchState(3);
				break;
			case MenuOpt::Audio:
				break;
			case MenuOpt::Keybinds:
				break;
			case MenuOpt::Back:
				m_State.SwitchState(0);
				break;
			}
		}
	}
}