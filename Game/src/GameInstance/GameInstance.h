#pragma once
#include "GameStates/StateMachine.h"
#include "Input/Keyboard.h"
#include "Input/Cursor.h"

enum class GameStates
{
	MainMenu = 0,
	Settings, 
	Play,

};
class GameInstance
{
public:
	GameInstance();
	void Run();

private:
	void Init();
	void InputUpdate();
	void Update();
	void WindowPollEventUpdate();
	void Draw();

private:
	// Rearanjare variable pentru o aliniere mai buna a memoriei, scopul find de a scapa de cache miss-uri
	Window m_Window; 
	StateMachine m_StateMachine;
//	StateMachine m_MainMenuState;
	sf::Clock m_Clock;

	Cursor m_Cursor;
	Keyboard m_KeyboardComponent;

	float m_DeltaTime;


};

