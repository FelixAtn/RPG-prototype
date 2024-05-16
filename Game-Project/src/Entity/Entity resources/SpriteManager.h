#pragma once
#include <SFML/Graphics.hpp>
#include "Resources/Loader.h"
#include <vector>

class SpriteManager
{
public:
	SpriteManager(const SpriteManager&) = delete;
	SpriteManager& operator=(const SpriteManager&) = delete;
	static SpriteManager& getInstance();

	void CreateSprites();
	sf::Sprite* GetSprite(size_t index);

	void LoadTexture();

private:
	SpriteManager();
	~SpriteManager();

private:
	std::vector<std::unique_ptr<sf::Sprite>> m_Sprites;
	sf::Texture m_PlayerTexture;
	sf::Texture m_EnemyTexture;
	Loader m_Loader;
	static bool m_IsCreated;
};

