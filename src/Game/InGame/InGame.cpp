#include "stdafx.h"
#include "InGame.h"


PlayState::PlayState(StateManager& stateManager)
	: m_StateManager(stateManager)
	, m_Characters(m_RenderingManager)
{
	m_Characters.InitPlayer(Vector2f(500.f, 500.f));
	m_Characters.SpawnHostilesInArea(Vector2f(100.f, 100.f), Vector2f(500.f, 500.f), 5);

	
	m_Flooring = std::make_unique<TileLayer>("bloody_rock", "MAP_ONE", m_RenderingManager);
	m_Flooring->Init();
}

void PlayState::Update(float deltaTime)
{
	m_Flooring->Update(deltaTime);
	m_Characters.Update(deltaTime);


	/*if (InputManager::Get().IsKeyPress(KeyBind::DODGE))
	{

		int roll = m_Random.GetRandomInt(1, 100);
		if (roll <= 60)
		{
			m_Sound.PlaySoundX("silver_drop");
			m_Sound.PlaySoundX("common_drop");
			Debug::Print("DROP: common");
		}
		else if (roll <= 85)
		{
			m_Sound.PlaySoundX("unique_drop");
			Debug::Print("DROP: unique");
		}
		else if (roll <= 99)
		{
			m_Sound.PlaySoundX("rare_drop");
			Debug::Print("DROP: rare");
		}
		else
		{
			m_Sound.PlaySoundX("elite_drop");
			Debug::Print("DROP: elite");
		}
	}*/
}

void PlayState::Draw(Window& window)
{
 	for (auto& tile : m_Flooring->GetTiles())
 	{
 		tile->GetComponent<C_BoxCollider>()->Draw(window);
 		window.Draw(tile->GetComponent<C_Sprite>()->GetSprite());
 	}

	m_Characters.Draw(window);
	m_RenderingManager.Draw(window);
	/*
	std::vector<DrawingOrder> entitySprite;
	entitySprite.reserve(3000);

	C_Sprite* playerSprite = m_Player.GetComponent<C_Sprite>();
	entitySprite.emplace_back(playerSprite->m_Sprite, playerSprite->m_Sprite.getPosition());

	for (const auto& monster : m_HostileEntities)
	{
		if (monster != nullptr)
		{
			C_Sprite* sprite = monster->GetComponent<C_Sprite>();

			entitySprite.emplace_back(sprite->m_Sprite, sprite->m_Sprite.getPosition());
		}
	}

// 	for (const auto& tile : m_Layer.GetTiles())
// 	{
// 		entitySprite.emplace_back(tile.sprite, tile.sprite.getPosition());
// 	}

	auto compareYaxis = [](const DrawingOrder& firstSprite, const DrawingOrder& secondSprite)
		{
			return firstSprite.m_Position.y < secondSprite.m_Position.y;
		};

	std::sort(entitySprite.begin(), entitySprite.end(), compareYaxis);


	for (auto& entity : entitySprite)
	{
		window.Draw(entity.m_Entity);
		m_Player.GetComponent<C_BoxCollider>()->Draw(window);
	}

	for (auto& proj : m_Player.m_Projectile)
	{
		window.Draw(proj.m_Sprite);
	}
	*/
}

void PlayState::HandleInput(float deltaTime)
{

}
