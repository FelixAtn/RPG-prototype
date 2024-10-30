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
	std::unique_ptr<TileLayer> m_Flooring;

	CharactersManager m_Characters;
	Player m_Player;
	StateManager& m_StateManager;
	AudioManager m_Sound;
	RandomGenerator m_Random;

	RenderingSystem m_RenderingManager;

};