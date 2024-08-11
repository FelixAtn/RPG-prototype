#pragma once
#include "GameStates/StateMachine.h"
#include "Entity/Character/Player/Player.h"
#include "Entity/Character/Enemy/Enemy.h"
#include "Tilemap/MapLayer.h"

namespace GameData
{
	const std::string PLAYER_NAME = "YUUMI";
	const std::string PLAYER_TYPE = "reaper";
}

struct DrawableEntity
{
	sf::Sprite m_Entity;
	sf::Vector2f m_Position;

	DrawableEntity(const sf::Sprite& entitySprite, const sf::Vector2f& entityPosition)
		: m_Entity(entitySprite), m_Position(entityPosition) {}
};
class PlayGame : public States
{
public:
	PlayGame(StateMachine& state, Window& window, Keyboard& keyboardInput,Cursor& cursor);
	~PlayGame() {} ;
	void Create() override;
	void Destroy() override;
	void Start() override;
	void Pause() override {};

	void CheckCollision();

	void AddEnemy(const std::string& enemyName, const std::string& enemyType, const float& xPos, const float& yPos);
	void AddPlayer(const std::string& playerName, const std::string& playerType);
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;


	void Render(Window& window) override;
	void DrawTiles(Window& window);
	void DrawPlayer(Window& window);
	void DrawEnemies(Window& window);

private:
	StateMachine& m_StateMachine;
	MapLayer m_GroundLayer;
	MapLayer m_SolidLayer;
	std::unique_ptr<Player> m_Player;
	std::vector<std::unique_ptr<Enemy>> m_Enemies;
	std::vector<std::unique_ptr<Button>> m_HealthBar;
};

