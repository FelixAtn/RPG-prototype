#pragma once
#include "Entity/Entity resources/Animator.h"
#include "Entity/Entity resources/Characters.h"
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

	Characters m_Obj;
	PlayerEntity m_Player;
	EnemyEntity m_Enemy;
	FriendlyEntity m_Friend;
	World m_World;
};

