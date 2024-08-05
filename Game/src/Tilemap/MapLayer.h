#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <Window/Window.h>


enum class MapKey
{
	GROUND = 0,
	SOLID,
};

class MapLayer
{
public:
	MapLayer();

	struct Tile
	{
		int m_ID = 0;
		sf::Sprite m_Sprite;
	};

	void Init(const std::string& textureLocation, const sf::Vector2i& tileDimension);
	void Load(const std::string& fileLocation);
	void Draw(Window& window);

	const std::vector<Tile>& GetTiles() const { return m_Tiles; }

private:
	sf::Texture m_Texture;
	std::vector<Tile> m_Tiles;
	sf::Vector2i m_TileDimension;
	sf::Vector2i m_TilesCount;
	int m_MaxTileID;
	bool m_IsInitialized;

};
