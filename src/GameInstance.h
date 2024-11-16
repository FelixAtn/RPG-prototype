#pragma once

constexpr const char* WINDOW_CONFIG = "Files/data/configs/window.init";

class GameInstance
{
public:
	GameInstance();
	~GameInstance() = default;

	void Run();

private:
	// Initialization functions
	void InitResources();
	void InitWindow();
	void InitGameStates();

	// Load functions
	void LoadCharacterData(ResourceManager& rs);
	void LoadMusic(ResourceManager& rs);
	void LoadTextures(ResourceManager& rs);
	void LoadMap(ResourceManager&);

	// Game loop functions
	void HandleEvent();
	void HandleInput();
	void Update();
	void Draw();

private:
	Window m_Window; // SFML window
	StateManager m_StateManager; // Game state manager
	sf::Event m_Event; // SFML event
	Timer m_Timer; // Game timer
	sf::Clock m_Clock; // SFML clock 
	float m_deltaTime; // Time between frames
};


