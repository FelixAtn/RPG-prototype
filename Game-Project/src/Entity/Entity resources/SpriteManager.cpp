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
SpriteManager& SpriteManager::getInstance()
{
	static SpriteManager instance;
	return instance;
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
}
void SpriteManager::LoadTexture()
{
	m_Loader.Load(m_PlayerTexture, "idle.png");
	m_Loader.Load(m_EnemyTexture, "480.png");
}
