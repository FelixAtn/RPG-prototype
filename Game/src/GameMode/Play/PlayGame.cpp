#include "PlayGame.h"
#include "Resources/GameTools.h"
#include "Physics/Collision.h"
#include "iostream"

PlayGame::PlayGame(StateMachine& state, Window& window, Keyboard& keyboardInput, Cursor& cursor)
	: m_StateMachine(state)
	, m_GroundLayer(Paths::assets + Files::TextureFiles::ground, sf::Vector2i(TileSize::SMALL, TileSize::SMALL))
	, m_SolidLayer(Paths::assets + Files::TextureFiles::worldObjects, sf::Vector2i(TileSize::MEDIUM, TileSize::MEDIUM))
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
	m_GroundLayer.Load(Paths::maps + Files::MapFiles::ground);
	m_SolidLayer.Load(Paths::objects + Files::SolidObjectsFiles::object);
	m_Player = std::make_unique<Player>(GameData::PLAYER_NAME, GameData::PLAYER_TYPE);

	m_Enemies.reserve(10);
	AddEnemy("Monster1", "wolf", 200, 300);
	AddEnemy("Monster2", "wolf", 100, 400);
	AddEnemy("Monster3", "wolf", 250, 500);
}
#pragma endregion

void PlayGame::CheckCollision()
{
	for (auto& enemy : m_Enemies)
	{
		m_Player->GetCollider().CheckAndResolve(enemy->GetCollider(), 0.f);
	}

	for (MapLayer::Tile& tile : m_SolidLayer.GetTiles())
	{
		auto s = tile.m_Collider;

		m_Player->GetCollider().CheckAndResolve(tile.m_Collider, 0.f);
	}

	/*	for (auto& Enemies : m_Enemies)
	{
		bool isPlayerCollidingWithEnemy = m_Player->GetCollider().CheckCollision(Enemies->GetCollider(), 0.f);
		bool isCursorIntersectingWithEnemy = cursor.GetSprite().getGlobalBounds().intersects(Enemies->GetBounds());

		bool isAttackPressed = cursor.IsKeyPressed(MouseKey::LEFT_CLICK);
		bool isKeyAttackPressedE = keyboard.IsKeyPressed(Key::E);

		bool isAttackConditionMet = isCursorIntersectingWithEnemy && isAttackPressed;

		// ########## Combat Logic #################
		sf::Vector2f rangeBetween = Enemies->GetSpritePosition() - m_Player->GetSpritePosition();
		sf::Vector2f attackRange = m_Player->GetSpritePosition() * 0.10f;
		if (isAttackConditionMet)
		{
			if (attackRange.x >= rangeBetween.x && attackRange.y >= rangeBetween.y)
			{
				m_Player->GetCombatComponent().Attack(*Enemies);
				std::cout << "\n\n ATTACKING:: " << Enemies->GetName() << " " << Enemies->GetHealthComponent().GetHealth();
			}
		}
		// ########## Combat Logic #################
	} */
}
void PlayGame::AddEnemy(const std::string& enemyName, const std::string& enemyType, const float& xPos, const float& yPos)
{
	m_Enemies.push_back(std::make_unique<Enemy>(enemyName, enemyType, xPos, yPos));
}

void PlayGame::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	keyboard.Update();
#pragma region PLAYER_UPDATE
	if (m_Player != nullptr)
	{
		m_Player->Update(cursor, keyboard, deltaTime);
	}
#pragma endregion
#pragma region ENEMY_UPDATE
	for (const auto& enemy : m_Enemies)
	{
		if (enemy != nullptr)
		{
			enemy->Update(cursor, keyboard, deltaTime);
		}
	}
#pragma endregion
	Character::RemoveCharacter(m_Enemies);
	CheckCollision();
}	



void PlayGame::Render(Window& window)
{
	m_GroundLayer.Draw(window);

	std::vector<DrawableEntity> entitySprite;
	entitySprite.reserve(3000);

	if(m_Player != nullptr)
	{
		entitySprite.emplace_back(m_Player->GetSprite(), m_Player->GetSprite().getPosition());
	}

	for(const auto& enemy : m_Enemies)
	{
		if(enemy != nullptr)
		{
			entitySprite.emplace_back(enemy->GetSprite(), enemy->GetSprite().getPosition());
		}
	}
	
	for (const MapLayer::Tile& tile : m_SolidLayer.GetTiles())
	{
		entitySprite.emplace_back(tile.m_Sprite, tile.m_Sprite.getPosition());
	}
	
	auto compareYaxis = [](const DrawableEntity& firstSprite, const DrawableEntity& secondSprite)
		{
			return firstSprite.m_Position.y < secondSprite.m_Position.y;
		};
	std::sort(entitySprite.begin(), entitySprite.end(), compareYaxis);

	for (const auto& entity : entitySprite)
	{
		window.Draw(entity.m_Entity);
	}
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