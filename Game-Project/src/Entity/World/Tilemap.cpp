#include "Tilemap.h"

Tilemap::Tilemap(Window& window, InputManager& input) : Character(window, input) {}
Tilemap::~Tilemap() {}

void Tilemap::Update(float deltaTime)
{
	m_Tiles->getPosition();
	m_Tiles->getGlobalBounds();
}
void Tilemap::Draw(Window& window)
{
	for (int y = 0; y < 70; y++)
	{
		for (int x = 0; x < 70; x++)
		{
			m_Tiles->setPosition(sf::Vector2f(m_Tiles->getGlobalBounds().getSize().x * y, m_Tiles->getGlobalBounds().getSize().y * x));
			m_Window.Draw(*m_Tiles);
		}
	}

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			m_Blocks->setPosition(m_Blocks->getGlobalBounds().width * y, m_Tiles->getGlobalBounds().height * x);
			m_Window.Draw(*m_Blocks);
		}
	}
}

void Tilemap::Init()
{
	m_Tiles->setScale(1.5, 1.5);
	m_Tiles->setTextureRect(sf::IntRect(0, 0, 32, 32));

	m_Blocks->setScale(1.5, 1.5);
	m_Blocks->setTextureRect(sf::IntRect(0, 0, 32, 32));
}
