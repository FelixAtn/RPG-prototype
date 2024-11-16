#include "stdafx.h"
#include "Cursor.h"

void Cursor::SetTexture(const std::string& textureName)
{
	m_CursorSprite.setTexture(ResourceManager::Get().GetTexture(textureName));
	m_CursorSprite.rotate(20);
}

void Cursor::Update()
{
	if (m_Window != nullptr)
	{
		m_CursorPosition = sf::Mouse::getPosition(*m_Window); // Get mouse position
		m_CursorSprite.setPosition(static_cast<float>(m_CursorPosition.x), static_cast<float>(m_CursorPosition.y));
	}
}

void Cursor::Draw(Window& window)
{
	m_Window = &window;
	
	if (m_Window != nullptr)
	{
		m_Window->Draw(m_CursorSprite);
	}
}

bool Cursor::isMouseOver(const sf::FloatRect& bounds) const
{
	return bounds.contains(static_cast<float>(m_CursorPosition.x), static_cast<float>(m_CursorPosition.y));
}

