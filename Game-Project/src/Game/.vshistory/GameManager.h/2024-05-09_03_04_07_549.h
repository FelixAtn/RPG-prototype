#pragma once
#include "Entity/Entity resources/Animator.h"
#include "Entity/Entity resources/Character.h"
#include "Entity/Player/PlayerEntity.h"
#include "Entity/Enemy/EnemyEntity.h"
#include "Entity/Friend/FriendlyEntity.h"
#include "Entity/World/World.h"

class GameManager
{
public:	
	void Run();
	GameManager();
	~GameManager();

private:
	void Update();
	void WindowUpdate();
	void Draw();
	void UpdateDeltaTime();

public:
	float m_DeltaTime;

private:
	sf::Clock m_Clock;
	InputManager m_Input;
	Window m_Window;
	Playerm_Player;


};

