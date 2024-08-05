#include "MainMenu.h"
#include "Resources/GameTools.h"
#include "iostream"


MainMenu::MainMenu(StateMachine& state, Window& window)
	: Menu(state, window)
{}

void MainMenu::Create()
{
	buttonWidth = 100.f;
	buttonHeight = 100.f;
	xButtonScale = 0.6f;
	yButtonScale = 0.6f;

	m_Button.reserve(5);
	m_Button[MenuOpt::Play] = std::make_unique<Button>("PLAY", buttonWidth, buttonHeight, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Settings] = std::make_unique<Button>("SETTINGS", buttonWidth, buttonHeight * 2, xButtonScale, yButtonScale);
	m_Button[MenuOpt::Exit] = std::make_unique<Button>("EXIT", buttonWidth, buttonHeight * 3, xButtonScale, yButtonScale);
}
void MainMenu::Destroy()
{ 
	m_Button.clear();
}
void MainMenu::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	UpdateButton(cursor);
	CheckChosenButton(cursor);
}
void MainMenu::Draw(Window& window)
{
	window.Render(m_Sprite);
	DrawButton();
}
void MainMenu::CheckChosenButton(Cursor& cursor)
{
	for (const auto& [MenuOpt, button] : m_Button)
	{
		if (button->IsCursorOn() && cursor.IsKeyPressed(MouseKey::LEFT_CLICK))
		{
			switch (MenuOpt)
			{
			case MenuOpt::Play:
				m_State.SwitchState(1);
				break;

			case MenuOpt::Settings:
				m_State.SwitchState(2);
				break;

			case MenuOpt::Exit:	
				m_Window.GetWindow().close();
				break;
			}
		}
	}
}

