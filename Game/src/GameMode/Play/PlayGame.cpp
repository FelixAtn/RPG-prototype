#include "PlayGame.h"
#include "Resources/GameTools.h"
#include "Physics/Collision.h"
#include "iostream"

PlayGame::PlayGame(StateMachine& state, Window& window, Keyboard& keyboardInput, Cursor& cursor)
	: m_StateMachine(state)
	, m_Window(window)
	, m_KeyboardInput(keyboardInput)
	, m_MouseInput(cursor)
	, m_SwitchToState(0)
{

}

#pragma region STATEMACHINE
void PlayGame::Create()
{
	Init();
}

void PlayGame::Destroy()
{
	m_Enemies.clear();
	m_Players.clear();
}

void PlayGame::Start()
{

}

void PlayGame::Pause()
{

}

void PlayGame::SetState(unsigned int ID)
{
	m_SwitchToState = ID;
}

#pragma endregion

#pragma region INIT
void PlayGame::Init()
{
	m_Enemies.reserve(10);
	AddPlayer("Yuumi", "reaper");
	AddBots(m_Enemies, 2, "Enemy", "wolf", 200, 200);
	AddMap();
}
void PlayGame::AddMap()
{
	m_GroundLayer.Init(Paths::assets + Files::TextureFiles::ground, sf::Vector2i(32, 32));
	m_GroundLayer.Load(Paths::maps + Files::MapFiles::ground);

	m_SolidLayer.Init(Paths::assets + Files::TextureFiles::worldObjects, sf::Vector2i(64, 64));
	m_SolidLayer.Load(Paths::objects + Files::SolidObjectsFiles::object);
}
void PlayGame::AddPlayer(const std::string& playerName, const std::string& playerType)
{
	m_Players.emplace_back(playerName, playerType);
}
#pragma endregion 

#pragma region TO_GAME_LOOP
void PlayGame::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	CheckCollision();
	UpdatePlayer(deltaTime);
	UpdateEnemies(deltaTime);

	if(keyboard.IsKeyPressed(Key::ESC))
	{
		m_StateMachine.SwitchState(0);
	}
}

void PlayGame::Draw(Window& window)
{
	DrawTiles(window);
	DrawBots(m_Players, window);
	DrawBots(m_Enemies, window);
}
#pragma endregion


#pragma region CHARACTERS_UPDATE

void PlayGame::UpdatePlayer(float deltaTime)
{
	if (!m_Players.empty())
	{
		for (auto & player : m_Players)
		{
			player.UpdateData(m_KeyboardInput, deltaTime);
		}
	}
}
void PlayGame::UpdateEnemies(float deltaTime)
{
	if (!m_Enemies.empty())
	{
		for (auto& enemy : m_Players)
		{
			enemy.UpdateData(m_KeyboardInput, deltaTime);
		}
	}
}
void PlayGame::UpdateOther(float deltaTime)
{

}
void PlayGame::DrawTiles(Window& window)
{
	m_GroundLayer.Draw(window);
	m_SolidLayer.Draw(window);
}
void PlayGame::CheckCollision()
{
	Collision::Rectangles AABB;
	for (auto& Player : m_Players)
	{
		for (auto& Enemies : m_Enemies)
		{
			if (AABB.IsColliding(Player.GetSprite(), Enemies.GetSprite()))
			{
				Player.SetVelocity(AABB.GetVelocity());
				std::cout << AABB.GetVelocity().x;
			}
		}
	}

	for (auto& Player : m_Players)
	{
		for (const MapLayer::Tile& tile : m_SolidLayer.GetTiles())
		{
			if (AABB.IsColliding(Player.GetSprite(), tile.m_Sprite))
			{
				Player.SetVelocity(AABB.GetVelocity());
			}
		}
	}
}

#pragma endregion
