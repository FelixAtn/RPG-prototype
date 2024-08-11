#include "GameInstance.h"
#include "GameMode/Menu/MainMenu.h"
#include "GameMode/Menu/Settings/Settings.h"
#include "GameMode/Menu//Settings/DisplaySettings.h"
#include "GameMode/Play/PlayGame.h"

GameInstance::GameInstance()
	: m_DeltaTime(0)
{
	Init();
}

void GameInstance::Run()
{
	while (m_Window.IsOpen())
	{
		InputUpdate();
		Update();
		WindowPollEventUpdate();
		Draw();

		m_DeltaTime = m_Clock.restart().asSeconds();
		m_Cursor.Clear();
		m_KeyboardComponent.Clear();
	}
}

void GameInstance::Init()
{
	std::shared_ptr<MainMenu> Menu = std::make_shared<MainMenu>(m_StateMachine, m_Window);
	std::shared_ptr<PlayGame> Play = std::make_shared<PlayGame>(m_StateMachine, m_Window, m_KeyboardComponent, m_Cursor);
	std::shared_ptr<Settings> gameSettings = std::make_shared<Settings>(m_StateMachine, m_Window);
 	std::shared_ptr<DisplaySettings> DisplaySetting = std::make_shared<DisplaySettings>(m_StateMachine, m_Window);

	unsigned int MenuID = m_StateMachine.AddState(Menu);
	unsigned int PlayID = m_StateMachine.AddState(Play);
	unsigned int SettingsID = m_StateMachine.AddState(gameSettings);
	unsigned int DisplaySettingsID = m_StateMachine.AddState(DisplaySetting);

	//Menu->SetState(SettingsID);
	m_StateMachine.SwitchState(MenuID);
}


void GameInstance::InputUpdate()
{
	m_Cursor.Update();
	m_Cursor.UpdateCursor(m_Window);
}

void GameInstance::Update()
{
	m_StateMachine.Update(m_Cursor, m_KeyboardComponent, m_DeltaTime);
}

void GameInstance::WindowPollEventUpdate()
{
	m_Window.Update();
}

void GameInstance::Draw()
{
	m_Window.Clear();
	m_StateMachine.Draw(m_Window);
	m_Cursor.Draw(m_Window);
	m_Window.Display();
}
