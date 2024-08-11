#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <Window/Window.h>
#include <Physics/BoxCollider.h>

namespace TileSize
{
	// The tile range 32-128 - ADD MORE IF NEEDED.
	constexpr int VERYSMALL = 24;
	constexpr int SMALL = 32;
	constexpr int MEDIUM = 64;
	constexpr int LARGE = 128;
}

class MapLayer
{
public:
	MapLayer(const std::string& textureLocation, const sf::Vector2i& tileDimension);
	struct Tile
	{
		int m_ID = 0;
		const float m_HitBox = 0.25f;
		sf::Sprite m_Sprite;
		BoxCollider m_Collider;
		Tile(int id, const sf::Sprite& sprite)
			: m_ID(id), m_Sprite(sprite), m_Collider(m_Sprite, m_HitBox) {}
	};
	std::vector<Tile> GetTiles() const { return m_Tiles; }

	void Load(const std::string& fileLocation);
	void Draw(Window& window);
	void CheckForErrors();

private:
	sf::Texture m_Texture;
	std::vector<Tile> m_Tiles;
	sf::Vector2i m_TileDimension;
	sf::Vector2i m_TilesCount;
	int m_MaxTileID;
	bool m_IsInitialized;
};
