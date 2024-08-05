#include "GameMode.h"
#include "iostream"
#include "Resources/GameTools.h"

GameMode::GameMode(InputManager& input)
{
	InitMap();
	InitEntityObjects();
	InitSprites();
	InitAttributes();
}

GameMode::~GameMode()
{
}

void GameMode::InitEntityObjects()
{
// 	m_PlayerOne = std::make_unique<Player>("Felix", "reaper");
// 	m_Enemy1 = std::make_unique<Enemy>("Ghost", "ghost");
// 	m_Enemy = std::make_unique<Enemy>("Wolf", "wolf");
}
void GameMode::InitMap()
{
	m_GroundLayer = std::make_unique<MapLayer>();
	m_SolidLayer = std::make_unique<MapLayer>();

	m_GroundLayer->Init(Paths::assets + Files::TextureFiles::ground, sf::Vector2i(32, 32));
	m_SolidLayer->Init(Paths::assets + Files::TextureFiles::worldObjects, sf::Vector2i(64, 64));

	m_GroundLayer->Load(Paths::maps + Files::MapFiles::ground);
	m_SolidLayer->Load(Paths::objects + Files::SolidObjectsFiles::object);
}
void GameMode::InitSprites()
{

	m_PlayerOne->InitSprite(sf::Vector2f(64, 64), sf::IntRect(0, 0, 64, 64), sf::Vector2f(1, 1), sf::Vector2f(600, 600));
	m_Enemy1->InitSprite(sf::Vector2f(32, 32), sf::IntRect(0, 0, 32, 32), sf::Vector2f(1, 1), sf::Vector2f(400, 200));
	m_Enemy->InitSprite(sf::Vector2f(64, 64), sf::IntRect(0, 0, 64, 64), sf::Vector2f(1, 1), sf::Vector2f(300, 300));
}
void GameMode::InitAttributes()
{
	m_Enemy->SetSpritePosition(sf::Vector2f(200, 200));
	m_Enemy->SetHp(500);

	m_PlayerOne->SetDamage(15);
}
void GameMode::Update(InputManager& input, float deltaTime)
{
	m_Rects.Reset();
	m_PlayerOne->Updates(input, deltaTime);
	m_Enemy1->Update(deltaTime);
	m_Enemy->Update(deltaTime);
	CheckCollision();
	UpdateGamePlay(input);
}


void GameMode::Draw(Window& window)
{
	m_GroundLayer->Draw(window);
	m_SolidLayer->Draw(window);
	m_PlayerOne->Draw(window);

	if (m_Enemy != nullptr)
	{
		m_Enemy->Draw(window);
	}

	if (m_Enemy1 != nullptr)
	{
		m_Enemy1->Draw(window);
	}
	window.Render(text);
}

void GameMode::UpdateGamePlay(InputManager& input)
{

	Tools::Font::Set(fontsss, Paths::fonts, Files::Fonts::fpsFont);

	text.setFont(fontsss);
	std::string enemyHP = std::to_string(m_Enemy->GetHp());
	text.setString(enemyHP);
	text.setFillColor(sf::Color::Black);
	text.setPosition(m_Enemy->GetSpritePosition().x - 25, m_Enemy->GetSpritePosition().y - 50);

	if (m_Rects.IsColliding(m_PlayerOne->GetSprite(), m_Enemy->GetSprite()))
	{
		if(input.IsKeyPressed(Key::LeftClick))
		{
			m_Enemy->SetHp(m_Enemy->GetHp() - m_PlayerOne->GetDamage());
			std::cout << m_Enemy->GetHp();
			if(m_Enemy->GetHp() <= 0)
			{
				m_Enemy->SetSpritePosition(sf::Vector2f(200, 300));
				m_Enemy->SetHp(500);
			}
		}
	}
}

void GameMode::CheckCollision()
{
	if (m_Rects.IsColliding(m_PlayerOne->GetSprite(), m_Enemy->GetSprite()))
	{
		m_PlayerOne->SetVelocity(m_Rects.GetVelocity());
	}

	for(const MapLayer::Tile& tile : m_SolidLayer->GetTiles())
	{
		if(m_Rects.IsColliding(m_PlayerOne->GetSprite(), tile.m_Sprite))
		{
			m_PlayerOne->SetVelocity(m_Rects.GetVelocity());
		}
	}

}

