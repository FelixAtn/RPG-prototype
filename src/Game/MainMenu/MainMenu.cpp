#include "stdafx.h"
#include "MainMenu.h"

MenuState::MenuState(StateManager& stateManager)
	: m_StateManager(stateManager)
	, time(0)
{

}

void MenuState::OnInit()
{
	
}

void MenuState::OnDestroy()
{

}

void MenuState::OnStart()
{
	m_Music.PlayMusic("theme");
}

void MenuState::OnStop()
{
	m_Music.StopMusic("theme");
}

void MenuState::Update(float deltaTime)
{
	
	if (InputManager::Get().IsKeyPress(KeyBind::PAUSE))
	{
		m_Music.PlaySoundX("play_button");
		m_StateManager.Switch(PLAY_STATE_ID);
	}
}

void MenuState::Draw(Window& window)
{

}

void MenuState::HandleInput(float deltaTime)
{

}
