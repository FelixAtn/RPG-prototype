#pragma once

// 	bool isWall;
// 	bool isDoor;
// 	bool isLocked;
// 	bool isSecret;
// 	bool isHidden;
// 	bool isBreakable;
// 	bool isClimbable;
// 	bool isLadder;
// 	bool isStairs;
// 	bool isBridge;
// 	bool isWater;
// 	bool isLava;
// 	bool isAcid;
// 	bool isIce;
// 	bool isMud;
// 	bool isSand;
// 	bool isGrass;


struct GridSquare
{
	sf::RectangleShape square;
	int index = -1;
};

class World
{
public:
	void Init(const Vector2f& gridSize, const Vector2f& squareSize = Vector2f(32, 32));
	void Update(float deltaTime);
	void Draw(Window& window);

private:
	void DrawGrid(Window& window);

private:
	std::vector<GridSquare> m_Grids;
};

