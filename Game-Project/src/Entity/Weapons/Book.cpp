#include "Book.h"
Book::Book(Window& window, InputManager& input) :m_Window(window), m_Input(input), 
Ability(m_AbyssalBookText), m_DeltaTime(0), 
m_Player(m_Window, m_Input), m_Enemy(m_Window, m_Input), i(m_AbilitySprite.size() - 1)
{
}

void Book::Update(float& deltaTime)
{
	m_DeltaTime = deltaTime;
	m_Input.Update();

	Input();
	m_Enemy.Update(m_DeltaTime);
	m_Player.Update(m_DeltaTime);
}

void Book::Draw(Window& window)
{
	for (size_t i = 0; i < m_AbilitySprite.size(); i++)
	{
		window.Draw(m_AbilitySprite[i]);
	}
}

void Book::Input()
{
// 	sf::Vector2i pixelPosition = sf::Mouse::getPosition(m_Window.m_WindowRenderer);
// 	sf::Vector2f pixelPos;
// 	pixelPos.x = pixelPosition.x;
// 	pixelPos.y = pixelPosition.y;
// 
// 	sf::Vector2f worldPosition = m_Window.m_WindowRenderer.mapPixelToCoords(pixelPosition);
// 
// 	sf::Sprite* player = m_Player.GetPlayer();
// 	sf::Sprite target = *m_Enemy.GetEnemy();
// 	sf::Vector2f startingPosition = player->getPosition();
// 	sf::Vector2f targetPosition = target.getPosition();
// 
// 	sf::Vector2u windowSize = m_Window.m_WindowRenderer.getSize();
// 	sf::Vector2f windowSizeFloat;
// 	windowSizeFloat.x = windowSize.x;
// 	windowSizeFloat.y = windowSize.y;
// 
// 	
// 	if (m_Input.IsKeyPressed(Key::Click) && m_AbilitySprite.size() <= 0)
// 	{
// 		m_AbilitySprite.push_back(m_FireBall);
// 		i = m_AbilitySprite.size() - 1 ;		
// 		m_AbilitySprite[i].setPosition(player->getPosition());
// 		std::cout << player->getPosition().x;
// 		std::cout << "\nsize: " << m_AbilitySprite.size();
// 	}
// 	sf::Vector2f windowMax;
// 	windowMax.x = 1920;
// 	windowMax.y = 1080;
// 
// 	sf::Vector2f toThe;
// 	toThe.x *= m_DeltaTime;
// 	toThe.y *= m_DeltaTime;
// 	toThe.x = toThe.x + 1.f;
// 	toThe.y = toThe.y + 1.f;
// 	
// 	for (size_t i = m_AbilitySprite.size() - 1; i < m_AbilitySprite.size(); i++)
// 	{
// 			m_AbilitySprite[i].setTextureRect(sf::IntRect(0, 0, 128, 128));
// 			m_Direction = m_Unit.GetUnit(startingPosition, worldPosition);
// 			toThe = (worldPosition - m_AbilitySprite[i].getPosition());
// 			m_AbilitySprite[i].setPosition(m_AbilitySprite[i].getPosition() + m_Direction * 1.8f);
// 
//  			if (m_AbilitySprite[i].getPosition().x >= player->getPosition().x + 200 ||
//  				m_AbilitySprite[i].getPosition().y >= player->getPosition().y + 200 ||
//  				m_AbilitySprite[i].getPosition().x <= player->getPosition().x -200 ||
//  				m_AbilitySprite[i].getPosition().y <= player->getPosition().y -200 ||
// 				m_AbilitySprite.size() == 4)
// 			{
// 				m_AbilitySprite.erase(m_AbilitySprite.begin());
// 				std::cout << "\nsize: " << m_AbilitySprite.size();
// 			}
// 	}

}

void Book::Init()
{
	m_Loader.Load(m_AbyssalBookText, "planet09.png");
	m_FireBall.setTexture(m_AbyssalBookText);
	m_FireBall.setTextureRect(sf::IntRect(0, 0, 64, 64));
}
