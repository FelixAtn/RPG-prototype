#include "Game/GameManager.h"

GameManager::GameManager() : m_Player(m_Window, m_Input, m_Character), m_Enemy(m_Window, m_Character), m_Friend(m_Window, m_Character), m_World(m_Window, m_Character), m_Character(m_Character){}
GameManager::~GameManager(){}

void GameManager::Run()
{
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
	m_Friend.Draw(m_Window);
	m_Enemy.Draw(m_Window);
	m_World.Draw(m_Window);
	m_Window.EndDraw();
}







