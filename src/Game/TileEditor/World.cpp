#include "stdafx.h"
#include "World.h"

// Q: What is the purpose of this function?
	// A: This function initializes the world by creating a grid of tiles.
	// 
	// Q: What is the purpose of the TileGrid struct?
	// A: The TileGrid struct is used to store information about a single tile in the grid.
	// 
	// Q: What is the purpose of the for loop?
	// A: The for loop is used to create a grid of tiles.
	// 
	// Q: What is the purpose of the if statement?
	// A: The if statement checks if the mouse is over a tile and if the left mouse button is pressed.
	// 
	// Q: What is the purpose of the else if statement?
	// A: The else if statement checks if the mouse is over a tile and if the right mouse button is pressed.
	// 
	// Q: What is the purpose of the m_TileGrids vector?
	// A: The m_TileGrids vector is used to store all the tiles in the grid.
	// 
	// Q: What is the purpose of the gridSizeX and gridSizeY variables?
	// A: The gridSizeX and gridSizeY variables are used to determine the size of the grid.
// 	int gridSizeX = DEFAULT_RESOLUTION_WIDTH / 32;
// 	int gridSizeY = DEFAULT_RESOLUTION_HEIGHT / 32;
// 
// 	for (int y = 0; y < gridSizeY; y++)
// 	{
// 		for (int x = 0; x < gridSizeX; x++)
// 		{
// 			tileGrid.position = sf::Vector2f(x * 32.f, y * 32.f);
// 			tileGrid.shape.setPosition(tileGrid.position);
// 			tileGrid.index = x + y * gridSizeX;
// 			m_TileGrids.push_back(tileGrid);
// 		}
// 	}

void World::Init(const Vector2f& gridSize, const Vector2f& squareSize /*= Vector2f(32,32)*/)
{
	GridSquare square;
	square.square.setSize(squareSize);
	square.square.setFillColor(sf::Color::Transparent);
	square.square.setOutlineThickness(1);
	square.square.setOutlineColor(sf::Color::Green);

	Vector2f worldGridSize = gridSize / squareSize;

	for (int y = 0; y < worldGridSize.y; y++)
	{
		for (int x = 0; x < worldGridSize.x; x++)
		{
			square.index = x + y * worldGridSize.x;
			square.square.setPosition(x * squareSize.x, y * squareSize.y);
			m_Grids.emplace_back(square);
		}
	}
}

void World::Update(float deltaTime)
{
	for (const auto& tile : m_Grids)
	{
		if (tile.square.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Log::Print("Tile number: ", tile.index);
			}
		}
	}
}

void World::Draw(Window& window)
{
	ImGui::SFML::Render(window);
	DrawGrid(window);
	Cursor::Get().Draw(window);
}

void World::DrawGrid(Window& window)
{
	for (auto& tile : m_Grids)
	{
		window.Draw(tile.square);
	}
}
