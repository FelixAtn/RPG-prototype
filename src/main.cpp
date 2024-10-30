#include "stdafx.h"
#include "GameInstance.h"

// Loading assets before the program starts, the maps IDs to be replaced later with enum classes for each asset type
void LoadCharacterData()
{
	ResourceManager::Get().LoadCharacterFile("config.yaml");
}
void LoadMusic()
{
	ResourceManager::Get().LoadMusic("theme", "Files/sounds/12sky2-theme.mp3");
	ResourceManager::Get().LoadSoundBuffer("success", "Files/sounds/success.wav");
	ResourceManager::Get().LoadSoundBuffer("common_drop", "Files/sounds/common_drop.wav");
	ResourceManager::Get().LoadSoundBuffer("elite_drop", "Files/sounds/elite_drop.ogg");
	ResourceManager::Get().LoadSoundBuffer("roar_buff", "Files/sounds/roar_buff.wav");
	ResourceManager::Get().LoadSoundBuffer("momentum_failed", "Files/sounds/momentum_failed.ogg");
	ResourceManager::Get().LoadSoundBuffer("momentum", "Files/sounds/momentum.ogg");
	ResourceManager::Get().LoadSoundBuffer("scared", "Files/sounds/scared.wav");
	ResourceManager::Get().LoadSoundBuffer("level_up", "Files/sounds/level_up.ogg");
	ResourceManager::Get().LoadSoundBuffer("cave_finish", "Files/sounds/cave_finish.ogg");
	ResourceManager::Get().LoadSoundBuffer("revive", "Files/sounds/revive.ogg");
	ResourceManager::Get().LoadSoundBuffer("beat", "Files/sounds/beat.ogg");
	ResourceManager::Get().LoadSoundBuffer("your_blood", "Files/sounds/your_blood.flac");
	ResourceManager::Get().LoadSoundBuffer("earth_quake", "Files/sounds/earth_quake.ogg");
	ResourceManager::Get().LoadSoundBuffer("rare_drop4", "Files/sounds/rare_drop4.ogg");
	ResourceManager::Get().LoadSoundBuffer("rare_drop2", "Files/sounds/rare_drop2.ogg");
	ResourceManager::Get().LoadSoundBuffer("play_button", "Files/sounds/play_button.ogg");
	ResourceManager::Get().LoadSoundBuffer("rare_drop1", "Files/sounds/rare_drop1.ogg");
	ResourceManager::Get().LoadSoundBuffer("sell", "Files/sounds/sell.ogg");
	ResourceManager::Get().LoadSoundBuffer("rare_drop", "Files/sounds/rare_drop.ogg");
	ResourceManager::Get().LoadSoundBuffer("rare_drop3", "Files/sounds/rare_drop3.ogg");
	ResourceManager::Get().LoadSoundBuffer("silver_drop", "Files/sounds/silver_drop.ogg");
}
void LoadTextures()
{
	ResourceManager::Get().LoadTexture("player_spritesheet", "Files/assets/characters/main_actor/main_actor.png");
	ResourceManager::Get().LoadTexture("projectile", "Files/assets/projectile/projectile.png");
	ResourceManager::Get().LoadTexture("bloody_rock", "Files/assets/World/floor/flooring.png");
	ResourceManager::Get().LoadTexture("cursor", "Files/assets/Menu/Cursor Default.png");
}
void LoadMap()
{
	ResourceManager::Get().LoadMapFile("maps.yaml");
}

int main()
{
	LoadMap();
	LoadCharacterData();
	LoadTextures();
	LoadMusic();



	GameInstance gameInstance;
	gameInstance.Init();
	gameInstance.Run();
}
