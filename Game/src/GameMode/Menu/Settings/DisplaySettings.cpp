#include "DisplaySettings.h"

DisplaySettings::DisplaySettings(StateMachine& state, Window& window)
	: Menu(state, window)
{}

void DisplaySettings::Create()
{
	buttonWidth = 100.f;
	buttonHeight = 100.f;
	xButtonScale = 0.6f;
	yButtonScale = 0.6f;

	m_Button.reserve(5);
	m_Button[MenuOpt::Resolution] = std::make_unique<Button>("RESOLUTION ", buttonWidth, buttonHeight, xButtonScale, yButtonScale);
	m_Button[MenuOpt::MaxFPS] = std::make_unique<Button>("MAX FPS ", buttonWidth, buttonHeight * 2, xButtonScale, yButtonScale);
	m_Button[MenuOpt::vSync] = std::make_unique<Button>("vSYNC ", buttonWidth, buttonHeight * 3, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Back] = std::make_unique<Button>("Back ", buttonWidth, buttonHeight * 7, xButtonScale, yButtonScale);
}

void DisplaySettings::Destroy()
{
	m_Button.clear();
}

void DisplaySettings::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	UpdateButton(cursor);
	CheckChosenButton(cursor);
}

void DisplaySettings::Draw(Window& window)
{
	for (const auto& id : m_Button)
	{
		id.second->Draw(window);
	}
}

void DisplaySettings::CheckChosenButton(Cursor& cursor)
{
	for (const auto& [MenuOpt, button] : m_Button)
	{
		if (button->IsCursorOn() && cursor.IsKeyPressed(MouseKey::LEFT_CLICK))
		{
			switch (MenuOpt)
			{
			case MenuOpt::Back:
				m_State.SwitchState(2);
				break;
			}
		}
	}
}
