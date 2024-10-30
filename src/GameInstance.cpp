#include "stdafx.h"
#include "GameInstance.h"
#include "Game/InGame/InGame.h"
#include "Game/MainMenu/MainMenu.h"

GameInstance::GameInstance()
	: m_deltaTime(0.0f)
	, m_Camera(m_Window, Vector2f(800.f, 600.f))
	, m_Minimap(Vector2f(600.f, 200.f), sf::FloatRect(0.75f, 0.75f, 0.2f, 0.2f))
{

}


void GameInstance::Init()
{
	m_Window.Create(DEFAULT_RESOLUTION_WIDTH, DEFAULT_RESOLUTION_HEIGHT);

	std::shared_ptr<MenuState> menuState = std::make_shared<MenuState>(m_StateManager);
	std::shared_ptr<PlayState> playState = std::make_shared<PlayState>(m_StateManager);
	
	m_StateManager.Add(menuState, MAIN_MENU_STATE_ID);
	m_StateManager.Add(playState, PLAY_STATE_ID);
	m_StateManager.Switch(PLAY_STATE_ID);

	Cursor::Get().SetTexture("cursor");

}

void GameInstance::HandleInput()
{
	InputManager::Get().Update(m_deltaTime);
	m_StateManager.HandleInput(m_deltaTime);
}

void GameInstance::Run()
{
	while (m_Window.IsOpen())
	{
		HandleInput();
		Update();
		Draw(); 
		m_deltaTime = m_Clock.restart().asSeconds();
	}
}

void GameInstance::Update()
{
	m_Window.HandleEvents();
	Cursor::Get().Update(m_Window);
	InputManager::Get().ReceiveEvent(m_Window.GetEvent());
	m_StateManager.Update(m_deltaTime);
}

void GameInstance::Draw()
{
	m_Window.Clear();
	m_StateManager.Draw(m_Window);
	Cursor::Get().Draw(m_Window);
	m_Window.Display();
}
