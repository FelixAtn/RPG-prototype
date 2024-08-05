#pragma once
#include "GameStates/StateMachine.h"
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"
#include "Tilemap/MapLayer.h"
#include <vector>

#pragma region TEMPLATE_HELPERS
template <typename EntityContainer>
void AddBots(EntityContainer& entityContainer, int botNumber, const std::string& botName, const std::string& botType, float xPos, float yPos)
{
	for (int i = 0; i < botNumber; ++i)
	{
		entityContainer.emplace_back(botName + std::to_string(i), botType, xPos * i, yPos);
	}
}

template <typename EntityContainer, typename Window>
void UpdateBots(EntityContainer& entityContainer, float deltaTime)
{
	if (!entityContainer.empty())
	{
		for (auto& entity : entityContainer)
		{
			entity.Update(deltaTime);
		}
	}
}

template <typename EntityContainer, typename Window>
void DrawBots(EntityContainer& entityContainer, Window& window)
{
	if(!entityContainer.empty())
	{
		for (auto& entity : entityContainer)
		{
			entity.Render(window);
		}
	}
}
#pragma endregion

class PlayGame : public States
{
public:
	PlayGame(StateMachine& state, Window& window, Keyboard& keyboardInput,Cursor& cursor);
	~PlayGame() {} ;
	void Create() override;
	void Destroy() override;
	void Start() override;
	void Pause() override;
	void SetState(unsigned int ID);

	void Init();
	void AddMap();
	void AddPlayer(const std::string& playerName, const std::string& playerType);

	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void Draw(Window& window) override;
	void DrawTiles(Window& window);

	void UpdatePlayer(float deltaTime);
	void UpdateEnemies(float deltaTime);
	void UpdateOther(float deltaTime);
	void CheckCollision();

private:
	StateMachine& m_StateMachine;
	Window& m_Window;

	Keyboard& m_KeyboardInput;
	Mouse& m_MouseInput;

	MapLayer m_GroundLayer;
	MapLayer m_SolidLayer;

	std::vector<Player> m_Players;
	std::vector<Enemy> m_Enemies;

	sf::Text text;
	sf::Font fontsss;

	unsigned int m_SwitchToState;
};

