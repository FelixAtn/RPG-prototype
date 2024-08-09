#pragma once
#include "GameStates/StateMachine.h"
#include "Entity/Character/Player/Player.h"
#include "Entity/Character/Enemy/Enemy.h"
#include "Tilemap/MapLayer.h"


class PlayGame : public States
{
public:
	PlayGame(StateMachine& state, Window& window, Keyboard& keyboardInput,Cursor& cursor);
	~PlayGame() {} ;
	void Create() override;
	void Destroy() override;
	void Start() override;
	void Pause() override;

	void AddMap();
	void AddEnemy(const std::string& enemyName, const std::string& enemyType, const float& xPos, const float& yPos);
	void AddPlayer(const std::string& playerName, const std::string& playerType);

	void CheckCollision(Cursor& cursor, Keyboard& keyboard);
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void UpdatePlayer(Cursor& cursor, Keyboard& keyboard, float deltaTime);
	void UpdateEnemies(Cursor& cursor, Keyboard& keyboard, float deltaTime);

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

