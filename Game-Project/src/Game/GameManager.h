#pragma once
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"
#include "Resources/FPS.h"
#include "Entity/World/Tilemap.h"

class GameManager
{
public:	
	void Run();
	GameManager();
	~GameManager();

private:
	void Init();
	void Update();
	void WindowUpdate();
	void Draw();
	void UpdateDeltaTime();

private:
	InputManager m_Input;
	Tilemap m_TileMap;
	Window m_Window;
	Player m_Player;
	Enemy m_Foe;
	sf::Clock m_Clock;

	Fps m_Fps;
	float m_DeltaTime;
};

