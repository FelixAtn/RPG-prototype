#include "MapLayer.h"
#include <iostream>
#include "Resources/GameTools.h"
#include "resources/FileLoader.h"

MapLayer::MapLayer(const std::string& textureLocation, const sf::Vector2i& tileDimension)
	: m_TileDimension(0, 0)
	, m_TilesCount(0, 0)
	, m_MaxTileID(0)
	, m_IsInitialized(false)
{
	if (!Tools::Texture::Load(m_Texture, textureLocation))
	{
		std::cerr << "Failed to load texture !\n";
		return;
	}

	m_IsInitialized = true;
	m_TileDimension = tileDimension;
	m_TilesCount.x = m_Texture.getSize().x / tileDimension.x; // the number of tiles horizontally
	m_TilesCount.y = m_Texture.getSize().y / tileDimension.y; // the number of tiles vertically
	m_MaxTileID = m_TilesCount.x * m_TilesCount.y ; // maximum amount of tile IDS from a spriteSheet
}

void MapLayer::Load(const std::string& fileLocation)
{
	CheckForErrors();
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
				std::cerr << "Wrong ID - Bigger than Max Tile ID !\n";
				continue;
			}

			if (ID == -1)
			{
				position.x += m_TileDimension.x;
				continue;
			}

			const int rowID = ID / m_TilesCount.x; // Calculate the ID in grid row
			const int columnID = ID - (rowID * m_TilesCount.x); // Calculate the ID in the grid column
			const int xOffsetTile = columnID * m_TileDimension.x; // X Position in the SpriteSheet
			const int yOffsetTile = rowID * m_TileDimension.y;// Y Position in the SpriteSheet
			const sf::IntRect textureRect(xOffsetTile, yOffsetTile, m_TileDimension.x, m_TileDimension.y); 

			sf::Sprite sprite;
			sprite.setTexture(m_Texture);
			sprite.setTextureRect(textureRect);
			sprite.setPosition(position);
			sf::Vector2f midPoint = sprite.getGlobalBounds().getSize() * 0.5f;
			sprite.setOrigin(midPoint);

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
		window.Draw(tile.m_Sprite);
	}
}

void MapLayer::CheckForErrors()
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
}

