#pragma once
#include "World.h"

class LevelEditor : public I_GameState
{
public:
	LevelEditor(StateManager& stateManager)
		: m_StateManager(stateManager)
	{}

	void OnInit() override;
	void OnDestroy();
	void OnStart();
	void OnStop();
	void Update(float deltaTime);
	void Draw(Window& window);
	void HandleInput(float deltaTime) {};

private:
	StateManager& m_StateManager;
	World m_World;

};

