#include "stdafx.h"
#include "GameInstance.h"
#include "Game/InGame/InGame.h"
#include "Game/MainMenu/MainMenu.h"
#include "Game/TileEditor/LevelEditor.h"

GameInstance::GameInstance()
	: m_deltaTime(0.0f)
{
	InitResources(); // Load all resources
	InitWindow(); // Initialize window
	InitGameStates(); // Initialize game states
	Cursor::Get().SetTexture("cursor"); // Set cursor texture
}

void GameInstance::InitResources()
{
	auto& resourceManager = ResourceManager::Get(); 
	LoadCharacterData(resourceManager); 
	LoadMusic(resourceManager); 
	LoadTextures(resourceManager); 
	LoadMap(resourceManager); 
}

void GameInstance::InitWindow()
{
	m_Window.Init(WINDOW_CONFIG);
	ImGui::SFML::Init(m_Window);
}

void GameInstance::InitGameStates()
{
	// Create game states
	std::shared_ptr<MenuState> menuState = std::make_shared<MenuState>(m_StateManager);
	std::shared_ptr<PlayState> playState = std::make_shared<PlayState>(m_StateManager);
	std::shared_ptr<LevelEditor> levelEditor = std::make_shared<LevelEditor>(m_StateManager);
	 
	// Add game states to state manager
	m_StateManager.Add(menuState, MAIN_MENU_STATE_ID);
	m_StateManager.Add(playState, PLAY_STATE_ID);
	m_StateManager.Add(levelEditor, LEVEL_EDITOR_STATE_ID);

	// Switch to main menu state
	m_StateManager.Switch(LEVEL_EDITOR_STATE_ID);
}

void GameInstance::HandleEvent()
{
	// Handle events
	while (m_Window.pollEvent(m_Event))
	{
		ImGui::SFML::ProcessEvent(m_Event);
		
		switch (m_Event.type)
		{
		case sf::Event::Closed:
			m_Window.close();
			break;

		default:
			break;
		}
	}
}

void GameInstance::HandleInput()
{
	m_StateManager.HandleInput(m_deltaTime);
}

void GameInstance::Run()
{
	// Game loop
	while (m_Window.isOpen())
	{
		HandleInput();
		HandleEvent();
		Update();
		Draw(); 
		m_deltaTime = m_Clock.restart().asSeconds();
	}
}

void GameInstance::Update()
{
	// Hide cursor
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange; 

	// Update ImGui
	ImGui::SFML::Update(m_Window, sf::seconds(m_deltaTime)); 

	// Update game states
	m_StateManager.Update(m_deltaTime); 
}

void GameInstance::Draw()
{
	// Clear window
	m_Window.clear();

	// Draw game states
	m_StateManager.Draw(m_Window);

	// Draw ImGui
	ImGui::SFML::Render(m_Window);

	// Display window
	m_Window.display();
}

void GameInstance::LoadCharacterData(ResourceManager& rs)
{
	rs.LoadCharacterFile("Files/data/characters/characters.data");
}

void GameInstance::LoadMusic(ResourceManager& rs)
{
	rs.LoadMusic("theme", "Files/assets/sounds/12sky2-theme.mp3");
	rs.LoadSoundBuffer("success", "Files/assets/sounds/success.wav");
	rs.LoadSoundBuffer("common_drop", "Files/assets/sounds/common_drop.wav");
	rs.LoadSoundBuffer("elite_drop", "Files/assets/sounds/elite_drop.ogg");
	rs.LoadSoundBuffer("roar_buff", "Files/assets/sounds/roar_buff.wav");
	rs.LoadSoundBuffer("momentum_failed", "Files/assets/sounds/momentum_failed.ogg");
	rs.LoadSoundBuffer("momentum", "Files/assets/sounds/momentum.ogg");
	rs.LoadSoundBuffer("scared", "Files/assets/sounds/scared.wav");
	rs.LoadSoundBuffer("level_up", "Files/assets/sounds/level_up.ogg");
	rs.LoadSoundBuffer("cave_finish", "Files/assets/sounds/cave_finish.ogg");
	rs.LoadSoundBuffer("revive", "Files/assets/sounds/revive.ogg");
	rs.LoadSoundBuffer("beat", "Files/assets/sounds/beat.ogg");
	rs.LoadSoundBuffer("your_blood", "Files/assets/sounds/your_blood.flac");
	rs.LoadSoundBuffer("earth_quake", "Files/assets/sounds/earth_quake.ogg");
	rs.LoadSoundBuffer("rare_drop4", "Files/assets/sounds/rare_drop4.ogg");
	rs.LoadSoundBuffer("rare_drop2", "Files/assets/sounds/rare_drop2.ogg");
	rs.LoadSoundBuffer("play_button", "Files/assets/sounds/play_button.ogg");
	rs.LoadSoundBuffer("rare_drop1", "Files/assets/sounds/rare_drop1.ogg");
	rs.LoadSoundBuffer("sell", "Files/assets/sounds/sell.ogg");
	rs.LoadSoundBuffer("rare_drop", "Files/assets/sounds/rare_drop.ogg");
	rs.LoadSoundBuffer("rare_drop3", "Files/assets/sounds/rare_drop3.ogg");
	rs.LoadSoundBuffer("silver_drop", "Files/assets/sounds/silver_drop.ogg");
}

void GameInstance::LoadTextures(ResourceManager& rs)
{
	rs.LoadTexture("player_spritesheet", "Files/assets/textures/characters/main_actor/main_actor.png");
	rs.LoadTexture("projectile", "Files/assets/textures/projectile/projectile.png");
	rs.LoadTexture("bloody_rock", "Files/assets/textures/World/floor/flooring.png");
	rs.LoadTexture("cursor", "Files/assets/textures/Menu/Cursor Default.png");
}

void GameInstance::LoadMap(ResourceManager& rs)
{
	rs.LoadMapFile("Files/data/maps/first_map/layer_0.map");
}
