#include "Game/GameManager.h"

GameManager::GameManager() : m_Player(m_Window, m_Input), m_Foe(m_Window, m_Input) {}
GameManager::~GameManager() {}

void GameManager::Run()
{ 
	//m_Player.Init();
	while(m_Window.IsRunning ())
	{
		Update();
		WindowUpdate();
		Draw();
		UpdateDeltaTime();
	}
}

void GameManager::Update()
{
	m_Player.Update(m_DeltaTime);
}
void GameManager::WindowUpdate()
{
	m_Window.Update();
}
void GameManager::UpdateDeltaTime()
{
	m_DeltaTime = m_Clock.restart().asSeconds();
}
void GameManager::Draw()
{
	m_Window.Clear();
	m_Player.Draw(m_Window);
	m_Foe.Draw(m_Window);
	m_Window.EndDraw();
}







