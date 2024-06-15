#include "Game/GameManager.h"


GameManager::GameManager() : m_Player(m_Window, m_Input), m_Foe(m_Window, m_Input), m_Fps(m_Window), m_TileMap(m_Window,m_Input) { Init(); }
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
	m_TileMap.Init();
	m_Foe.Init();
}
void GameManager::Update()
{
	m_Input.Update();
	m_Player.Update(m_DeltaTime);
	m_Foe.Update(m_DeltaTime);
	m_TileMap.Update(m_DeltaTime);
	m_Input.Clear();
	m_Fps.Update(m_DeltaTime);
}
void GameManager::WindowUpdate()
{
	sf::View view;
	view.setCenter(m_Player.GetPlayer()->getPosition());
	m_Window.setWindowView(view);
	m_Window.Update();
}
void GameManager::UpdateDeltaTime()
{
	m_DeltaTime = m_Clock.restart().asSeconds();
}
void GameManager::Draw()
{
	m_Window.Clear();
	m_TileMap.Draw(m_Window);
	m_Foe.Draw(m_Window);
	m_Player.Draw(m_Window);

	m_Fps.Draw(m_Window); // *** FPS TO BE SEPARED LATER *** 
	m_Window.EndDraw();
}







