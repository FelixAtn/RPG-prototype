#pragma once

class GameInstance
{
public:
	GameInstance();
	~GameInstance() = default;

	void Run();

private:
	void InitResources();
	void InitWindow();
	void InitGameStates();

	void HandleEvent();
	void HandleInput();
	void Update();
	void Draw();

	void LoadCharacterData()
	{
		ResourceManager::Get().LoadCharacterFile("Files/data/characters/characters.data");
	}
	void LoadMusic()
	{
		ResourceManager::Get().LoadMusic("theme", "Files/assets/sounds/12sky2-theme.mp3");
		ResourceManager::Get().LoadSoundBuffer("success", "Files/assets/sounds/success.wav");
		ResourceManager::Get().LoadSoundBuffer("common_drop", "Files/assets/sounds/common_drop.wav");
		ResourceManager::Get().LoadSoundBuffer("elite_drop", "Files/assets/sounds/elite_drop.ogg");
		ResourceManager::Get().LoadSoundBuffer("roar_buff", "Files/assets/sounds/roar_buff.wav");
		ResourceManager::Get().LoadSoundBuffer("momentum_failed", "Files/assets/sounds/momentum_failed.ogg");
		ResourceManager::Get().LoadSoundBuffer("momentum", "Files/assets/sounds/momentum.ogg");
		ResourceManager::Get().LoadSoundBuffer("scared", "Files/assets/sounds/scared.wav");
		ResourceManager::Get().LoadSoundBuffer("level_up", "Files/assets/sounds/level_up.ogg");
		ResourceManager::Get().LoadSoundBuffer("cave_finish", "Files/assets/sounds/cave_finish.ogg");
		ResourceManager::Get().LoadSoundBuffer("revive", "Files/assets/sounds/revive.ogg");
		ResourceManager::Get().LoadSoundBuffer("beat", "Files/assets/sounds/beat.ogg");
		ResourceManager::Get().LoadSoundBuffer("your_blood", "Files/assets/sounds/your_blood.flac");
		ResourceManager::Get().LoadSoundBuffer("earth_quake", "Files/assets/sounds/earth_quake.ogg");
		ResourceManager::Get().LoadSoundBuffer("rare_drop4", "Files/assets/sounds/rare_drop4.ogg");
		ResourceManager::Get().LoadSoundBuffer("rare_drop2", "Files/assets/sounds/rare_drop2.ogg");
		ResourceManager::Get().LoadSoundBuffer("play_button", "Files/assets/sounds/play_button.ogg");
		ResourceManager::Get().LoadSoundBuffer("rare_drop1", "Files/assets/sounds/rare_drop1.ogg");
		ResourceManager::Get().LoadSoundBuffer("sell", "Files/assets/sounds/sell.ogg");
		ResourceManager::Get().LoadSoundBuffer("rare_drop", "Files/assets/sounds/rare_drop.ogg");
		ResourceManager::Get().LoadSoundBuffer("rare_drop3", "Files/assets/sounds/rare_drop3.ogg");
		ResourceManager::Get().LoadSoundBuffer("silver_drop", "Files/assets/sounds/silver_drop.ogg");
	}
	void LoadTextures()
	{
		ResourceManager::Get().LoadTexture("player_spritesheet", "Files/assets/textures/characters/main_actor/main_actor.png");
		ResourceManager::Get().LoadTexture("projectile", "Files/assets/textures/projectile/projectile.png");
		ResourceManager::Get().LoadTexture("bloody_rock", "Files/assets/textures/World/floor/flooring.png");
		ResourceManager::Get().LoadTexture("cursor", "Files/assets/textures/Menu/Cursor Default.png");
	}
	void LoadMap()
	{
		ResourceManager::Get().LoadMapFile("Files/data/maps/first_map/layer_0.map");
	}

private:
	Window m_Window;
	StateManager m_StateManager;
	sf::Event m_Event;
	Timer m_Timer;
	sf::Clock m_Clock;
	float m_deltaTime;    
};


