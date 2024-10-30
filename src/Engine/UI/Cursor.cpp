#include "stdafx.h"
#include "Cursor.h"


void Cursor::SetTexture(const std::string& textureName)
{
	m_CursorSprite.setTexture(ResourceManager::Get().GetTexture(textureName));
	m_CursorSprite.rotate(20);
}

void Cursor::Update(Window& window)
{
	m_CursorPosition = sf::Mouse::getPosition(window.GetWindowRenderer()); // Get mouse position
	m_CursorSprite.setPosition(static_cast<float>(m_CursorPosition.x), static_cast<float>(m_CursorPosition.y));
}

void Cursor::Draw(Window& window)
{
	window.Draw(m_CursorSprite);
}


