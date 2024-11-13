#include "stdafx.h"
#include "TileLayer.h"

TileLayer::TileLayer(const std::string& texture, const std::string& mapName, RenderingSystem& renderingManager)
	: m_RenderSystem(renderingManager)
{
	if (!IsLoaded(texture, mapName))
	{
		return;
	}
}

TileLayer::~TileLayer()
{
	for (auto& tile : m_Tiles)
	{
		tile->UnregisterFromRendering(m_RenderSystem);
	}
}

void TileLayer::Init()
{
	for (auto& tile : m_Tiles)
	{
		if (C_BoxCollider* collider = tile->GetComponent<C_BoxCollider>())
		{
			collider->Update();
		}
		if (tile->GetTileType() != TileTypeID::TERRAIN)
		{
			tile->RegisterToRendering(m_RenderSystem);
		}
	}
}

void TileLayer::Update(float deltaTime)
{
	for (auto& tile : m_Tiles)
	{
		tile->Update(deltaTime);
	}
}

bool TileLayer::IsLoaded(const std::string& texture, const std::string& mapName)
{
	YAML::Node& mapData = ResourceManager::Get().GetMapFile();
	const sf::Texture* spriteTexture = &ResourceManager::Get().GetTexture(texture);

	if (spriteTexture == nullptr) 
	{
		Log::Print("texture is NULL", LogLevel::ERROR_);
		return false;
	}

	if (!IsMapNameValid(mapData, mapName)) 
	{
		Log::Print("Invalid map name | node", LogLevel::ERROR_);
		return false;
	}

	YAML::Node gameMap = mapData[mapName];
	m_MatrixMap = gameMap["map_data"].as<std::vector<std::vector<int>>>();
	unsigned int width = gameMap["tile_width"].as<unsigned int>();
	unsigned int height = gameMap["tile_height"].as<unsigned int>();
	Vector2u totalTiles(spriteTexture->getSize().x / width, spriteTexture->getSize().y / height);
	Vector2f position(0.0f, 0.0f);
	int maxTileID(totalTiles.x * totalTiles.y);

	for (const std::vector<int>& row : m_MatrixMap)
	{
		for (int ID : row) 
		{
			if (ID > maxTileID)
			{
				Log::Print("Wrong TileID, bigger than the existing tile number in the tilesheet. \nThe max ID in this tilesheet is:", maxTileID, LogLevel::ERROR_);
				continue;
			}

			if (ID == -1) {
				position.x += width;
				continue;
			}

			if (totalTiles.x <= 0) 
			{
				Log::Print("total tiles on X is <= 0 ", totalTiles.x, LogLevel::ERROR_);
				assert(totalTiles.x);
			}

			const int rowID = ID / totalTiles.x;
			const int columnID = ID - (rowID * totalTiles.x);
			const int xOffsetTile = columnID * width;
			const int yOffsetTile = rowID * height;
			const sf::IntRect textureRect(xOffsetTile, yOffsetTile, width, height);

			sf::Sprite sprite;
			sprite.setTexture(*spriteTexture);
			sprite.setTextureRect(textureRect);
			sprite.setPosition(position);

			m_Tiles.emplace_back(std::make_unique<Tile>(
				TileTypeID::TERRAIN,
				sprite,
				Vector2f(64, 64)
			));

			position.x += width;
		}
		position = Vector2f(0.0f, position.y + height);
	}
	return true;
}
bool TileLayer::IsMapNameValid(const YAML::Node& mapData, const std::string& mapName)
{
	if (!mapData[mapName])
	{
		Log::Print("Invalid map name | node", LogLevel::ERROR_);
		return false;
	}
	return true;
}

