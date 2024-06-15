#include "SpriteManager.h"


bool SpriteManager::m_IsCreated = false;

SpriteManager::SpriteManager()
{
	if (!m_IsCreated)
	{
		CreateSprites();
		m_IsCreated = true;
	}
}
SpriteManager::~SpriteManager(){}

sf::Sprite* SpriteManager::GetSprite(size_t index)
{
	if (index < m_Sprites.size())
	{
		return m_Sprites[index].get();
	}
	return nullptr;
}

sf::Sprite* SpriteManager::GetTiles(size_t index)
{
	if (index < m_Tiles.size())
	{
		return m_Tiles[index].get();
	}
	return nullptr;
}

SpriteManager& SpriteManager::getInstance()
{
	static SpriteManager instance;
	return instance;
}
void SpriteManager::LoadTexture()
{
	m_Loader.Load(m_PlayerTexture, "Ninja-Complete.png");
	m_Loader.Load(m_EnemyTexture, "g_cast.png");

	m_Loader.Load(m_TilesTexture, "tile_0000.png");
	m_Loader.Load(m_Blocks, "blo.png");
}
void SpriteManager::CreateSprites()
{
	LoadTexture();
	sf::Sprite playerSprite;
	playerSprite.setTexture(m_PlayerTexture);

	sf::Sprite enemySprite;
	enemySprite.setTexture(m_EnemyTexture);

	m_Sprites.push_back(std::make_unique<sf::Sprite>(std::move(playerSprite)));
	m_Sprites.push_back(std::make_unique<sf::Sprite>(std::move(enemySprite)));

	sf::Sprite tiles;
	tiles.setTexture(m_TilesTexture);
	m_Tiles.push_back(std::make_unique<sf::Sprite>(std::move(tiles)));

	sf::Sprite blocks;
	blocks.setTexture(m_Blocks);
	m_Tiles.push_back(std::make_unique<sf::Sprite>(std::move(blocks)));
}
