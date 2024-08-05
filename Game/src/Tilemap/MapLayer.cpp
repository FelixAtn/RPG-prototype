#include "MapLayer.h"
#include <iostream>
#include "Resources/GameTools.h"
#include "resources/FileLoader.h"

MapLayer::MapLayer()
	: m_TileDimension(0, 0)
	, m_TilesCount(0, 0)
	, m_MaxTileID(0)
	, m_IsInitialized(false)
{

}

void MapLayer::Init(const std::string& textureLocation, const sf::Vector2i& tileDimension)
{
	if (!Tools::Texture::Load(m_Texture, textureLocation))
	{
		std::cerr << "Failed to load texture !\n";
		return;
	}

	m_IsInitialized = true;
	m_TileDimension = tileDimension;
	m_TilesCount.x = m_Texture.getSize().x / tileDimension.x;
	m_TilesCount.y = m_Texture.getSize().y / tileDimension.y;
	m_MaxTileID = m_TilesCount.x + m_TilesCount.y;
}


void MapLayer::Load(const std::string& fileLocation)
{
	if (!m_IsInitialized)
	{
		std::cerr << "Invalid initialization !\n";
		return;
	}

	if (!m_Tiles.empty())
	{
		std::cerr << "I was stupid enough to call LoadMap twice !\n";
		return;
	}

	FileLoader::Matrix matrix;
	if (!FileLoader::LoadFile(fileLocation, matrix))
	{
		std::cerr << "Failed to load map data from file: " << fileLocation << "\n";
		return;
	}

	const int mapSize = static_cast<int>(matrix[0].size()) * static_cast<int>(matrix.size());
	m_Tiles.reserve(mapSize);

	sf::Vector2f position(0.f, 0.f);
	for (const std::vector<int>& row : matrix)
	{
		for (int ID : row)
		{
			if (ID > m_MaxTileID)
			{
				std::cerr << "Wrong fkin ID !\n";
				continue;
			}

			if (ID == -1)
			{
				position.x += m_TileDimension.x;
				continue;
			}


			const int columnID = ID % m_TilesCount.x;
			const int rowID = ID / m_TilesCount.y;
			const sf::IntRect textureRect(columnID * m_TileDimension.x, rowID * m_TileDimension.y, m_TileDimension.x, m_TileDimension.y);

			sf::Sprite sprite;
			sprite.setTexture(m_Texture);
			sprite.setTextureRect(textureRect);
		//	sprite.setOrigin(sprite.getGlobalBounds().getSize() * 0.5f);
			sprite.setPosition(position);
			sprite.scale(1.0f, 1.0f);

			position.x += m_TileDimension.x;
			m_Tiles.emplace_back(ID, sprite);

		
		}
		// Go to the next row
		position = sf::Vector2f(0.f, position.y + m_TileDimension.y);
	}
}

void MapLayer::Draw(Window& window)
{
	for (const Tile& tile : m_Tiles)
	{
		//hitBox.setPosition(tile.m_Sprite.getPosition());
		window.Render(tile.m_Sprite);
	}
}

