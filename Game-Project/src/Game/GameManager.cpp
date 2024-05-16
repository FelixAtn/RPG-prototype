#include "Game/GameManager.h"


GameManager::GameManager() : m_Player(m_Window, m_Input), m_Foe(m_Window, m_Input), m_Fps(m_Window) { Init(); }
GameManager::~GameManager() {}

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
void GameManager::Init()
{
	m_Player.Init();
	m_Foe.Init();
	//m_Ability.Init();
}
void GameManager::Update()
{
	m_Input.Update();
	m_Player.Update(m_DeltaTime);
	m_Foe.Update(m_DeltaTime);
	//m_Ability.Update(m_DeltaTime);
	m_Input.Clear();
	m_Fps.Update(m_DeltaTime);
	
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
	//m_Ability.Draw(m_Window);
	m_Fps.Draw(m_Window); // *** FPS TO BE SEPARED LATER *** 
	m_Window.EndDraw();
}







