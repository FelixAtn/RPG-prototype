#include "stdafx.h"
#include "GameInstance.h"
#include "Game/InGame/InGame.h"
#include "Game/MainMenu/MainMenu.h"

GameInstance::GameInstance()
	: m_deltaTime(0.0f)
{
	InitResources();
	InitWindow();
	InitGameStates();
	Cursor::Get().SetTexture("cursor");
}

void GameInstance::InitResources()
{
	LoadCharacterData();
	LoadMusic();
	LoadTextures();
	LoadMap();
}
void GameInstance::InitWindow()
{
	m_Window.Init("Files/data/configs/window.init");
	ImGui::SFML::Init(m_Window);
}
void GameInstance::InitGameStates()
{
	std::shared_ptr<MenuState> menuState = std::make_shared<MenuState>(m_StateManager);
	std::shared_ptr<PlayState> playState = std::make_shared<PlayState>(m_StateManager);

	m_StateManager.Add(menuState, MAIN_MENU_STATE_ID);
	m_StateManager.Add(playState, PLAY_STATE_ID);
	m_StateManager.Switch(PLAY_STATE_ID);

}

void GameInstance::HandleEvent()
{
	while (m_Window.PollEvent(m_Event))
	{
		switch (m_Event.type)
		{
		case sf::Event::Closed:
			m_Window.Close();
			break;

		default:
			break;
		}
	}
}

void GameInstance::HandleInput()
{
	m_StateManager.HandleInput(m_deltaTime);
}

void GameInstance::Run()
{
	while (m_Window.IsOpen())
	{
		HandleInput();
		HandleEvent();
		Update();
		Draw(); 
		m_deltaTime = m_Clock.restart().asSeconds();
	}
}

void GameInstance::Update()
{
	ImGui::SFML::Update(m_Window, sf::seconds(m_deltaTime));
	m_StateManager.Update(m_deltaTime);
}

void GameInstance::Draw()
{
	m_Window.Clear();
	m_StateManager.Draw(m_Window);
	ImGui::SFML::Render(m_Window);
	Cursor::Get().Draw(m_Window);
	m_Window.Display();
}
