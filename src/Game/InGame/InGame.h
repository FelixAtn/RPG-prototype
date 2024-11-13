#pragma once
#include "Engine/Tilemap/TileLayer.h" 
#include "Game/InGame/CharactersManager.h"

class PlayState : public I_GameState
{
public:
	PlayState(StateManager& stateManager);

	void OnInit() override {};
	void OnDestroy() override {};
	void OnStart() override {};
	void OnStop() override {};

	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void HandleInput(float deltaTime) override;

private:
	StateManager& m_StateManager;

	CharactersManager m_Characters;
	Player m_Player;
	AudioManager m_Sound;
	std::unique_ptr<TileLayer> m_Flooring;
	RandomGenerator m_Random;

	RenderingSystem m_RenderingManager;

};