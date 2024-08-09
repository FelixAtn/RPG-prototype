#include "PlayGame.h"
#include "Resources/GameTools.h"
#include "Physics/Collision.h"
#include "iostream"

PlayGame::PlayGame(StateMachine& state, Window& window, Keyboard& keyboardInput, Cursor& cursor)
	: m_StateMachine(state)
{
}

#pragma region STATEMACHINE
void PlayGame::Create()
{

}
void PlayGame::Destroy()
{
	m_Enemies.clear();
}
void PlayGame::Start()
{
	m_Enemies.reserve(10);
	AddMap();
	AddPlayer("Yuumi", "reaper");
	AddEnemy("Monster1", "wolf", 300, 300);
	AddEnemy("Monster2", "wolf", 300, 400);
	AddEnemy("Monster3", "wolf", 300, 500);
}
void PlayGame::Pause()
{

}
#pragma endregion
void PlayGame::AddMap()
{
	m_GroundLayer.Init(Paths::assets + Files::TextureFiles::ground, sf::Vector2i(32, 32));
	m_GroundLayer.Load(Paths::maps + Files::MapFiles::ground);

	m_SolidLayer.Init(Paths::assets + Files::TextureFiles::worldObjects, sf::Vector2i(64, 64));
	m_SolidLayer.Load(Paths::objects + Files::SolidObjectsFiles::object);
}
void PlayGame::AddEnemy(const std::string& enemyName, const std::string& enemyType, const float& xPos, const float& yPos)
{
	m_Enemies.push_back(std::make_unique<Enemy>(enemyName, enemyType, xPos, yPos));
}
void PlayGame::AddPlayer(const std::string& playerName, const std::string& playerType)
{
	m_Player = std::make_unique<Player>(playerName, playerType);
}
 
void PlayGame::CheckCollision(Cursor& cursor, Keyboard& keyboard)
{
	Collision::Rectangles AABB;

	for (auto& Enemies : m_Enemies)
	{
		bool isPlayerCollidingWithEnemy = AABB.IsColliding(m_Player->GetSprite(), Enemies->GetSprite());
		bool isCursorIntersectingWithEnemy = cursor.GetSprite().getGlobalBounds().intersects(Enemies->GetBounds());
		bool isAttackPressed = cursor.IsKeyPressed(MouseKey::LEFT_CLICK);
		bool isKeyAttackPressedE = keyboard.IsKeyPressed(Key::E);

		bool isAttackConditionMet = isPlayerCollidingWithEnemy && isCursorIntersectingWithEnemy && isAttackPressed;

		if (isAttackConditionMet)
		{
			m_Player->GetCombatComponent().Attack(*Enemies);
			std::cout << "\n\n ATTACKING:: " << Enemies->GetName() << " " << Enemies->GetHealthComponent().GetHealth();
		}

		if (isPlayerCollidingWithEnemy)
		{
			m_Player->GetMovementComponent().SetVelocity(AABB.GetVelocity());
		}
	}

	/*
	for (auto& Player : m_Player)
	{
		for (const MapLayer::Tile& tile : m_SolidLayer.GetTiles())
		{
			if (AABB.IsColliding(Player.GetSprite(), tile.m_Sprite))
			{
				Player.SetVelocity(AABB.GetVelocity());
			}
		}
	}*/
}
void PlayGame::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	CheckCollision(cursor, keyboard);
	UpdatePlayer(cursor, keyboard, deltaTime);
	UpdateEnemies(cursor, keyboard, deltaTime);
}	
void PlayGame::UpdatePlayer(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	if (m_Player != nullptr)
	{
		m_Player->Update(cursor, keyboard, deltaTime);
	}
}
void PlayGame::UpdateEnemies(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	for(const auto& enemy : m_Enemies)
	{
		if(enemy != nullptr)
		{
			enemy->Update(cursor, keyboard, deltaTime);
		}
	}
	Character::RemoveCharacter(m_Enemies);
}

void PlayGame::Render(Window& window)
{
	DrawTiles(window);
	DrawPlayer(window);
	DrawEnemies(window);
}
void PlayGame::DrawTiles(Window& window)
{
	m_GroundLayer.Draw(window);
	m_SolidLayer.Draw(window);
}
void PlayGame::DrawPlayer(Window& window)
{
	if (m_Player != nullptr)
	{
		m_Player->Render(window);
	}
}
void PlayGame::DrawEnemies(Window& window)
{
	for (const auto& enem : m_Enemies)
	{
		if (enem != nullptr)
		{
			enem->Render(window);
		}
	}
}


