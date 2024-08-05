#include "Cursor.h"
#include "Resources/GameTools.h"

Cursor::Cursor()
{
	InitCursor();
}

Cursor::~Cursor()
{

}

void Cursor::InitCursor()
{
	Tools::Texture::Load(m_CursorTexture, Paths::assets + Files::TextureFiles::cursor);
	m_CursorSprite.setTexture(m_CursorTexture);
	m_CursorSprite.rotate(20);
}

void Cursor::UpdateCursor(Window& window)
{
	m_MousePositionOnScreen = sf::Mouse::getPosition();
	m_MousePositionOnWindow = sf::Mouse::getPosition(window.GetWindow());
	m_MousePositionView = window.GetWindow().mapPixelToCoords(sf::Mouse::getPosition(window.GetWindow()));
	
	m_CursorSprite.setPosition(sf::Vector2f(m_MousePositionView));
}

void Cursor::Draw(Window& window)
{
	window.Render(m_CursorSprite);
}

sf::Sprite& Cursor::GetSprite()
{
	return m_CursorSprite;
}
