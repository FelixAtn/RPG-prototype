#pragma once
#include "Physics/Collision.h"
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"
#include "Tilemap/MapLayer.h"


class GameMode
{
public:
	GameMode(InputManager& input);
	~GameMode();
	void InitEntityObjects();
	void InitMap();
	void InitSprites();
	void InitAttributes();

	void Update(InputManager& input, float deltaTime);
	void Draw(Window& window);

	void UpdateGamePlay();

	void UpdateGamePlay(InputManager& input);
	void CheckCollision();

private:
	CollisionManager::Rectangles m_Rects;
	std::unique_ptr<MapLayer> m_GroundLayer;
	std::unique_ptr<MapLayer> m_SolidLayer;
	std::unique_ptr<Player> m_PlayerOne;

	std::unique_ptr<Enemy> m_Enemy1;
	std::unique_ptr<Enemy> m_Enemy;

	sf::Text text;
	sf::Font fontsss;

};
