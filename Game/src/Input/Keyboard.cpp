#include "Keyboard.h"
#include <SFML/Graphics.hpp>

void Keyboard::Clear()
{
	m_PreviousFrame.SetMask(m_CurrentFrame);
	m_CurrentFrame.ClearByte();
}

void Keyboard::Update()
{
	m_CurrentFrame.UpdateBit(static_cast<int>(Key::W),
		(sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	m_CurrentFrame.UpdateBit(static_cast<int>(Key::A),
		(sf::Keyboard::isKeyPressed(sf::Keyboard::A)));

	m_CurrentFrame.UpdateBit(static_cast<int>(Key::S),
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

	m_CurrentFrame.UpdateBit(static_cast<int>(Key::D),
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

	m_CurrentFrame.UpdateBit(static_cast<int>(Key::E),
		(sf::Keyboard::isKeyPressed(sf::Keyboard::E)));

	m_CurrentFrame.UpdateBit(static_cast<int>(Key::ESC),
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)));
}
