#pragma once
#include "Mouse.h"

class Cursor : public Mouse
{
public:
	Cursor();
	~Cursor();

	void InitCursor();
	void UpdateCursor(Window& window);
	void Draw(Window& window);

	sf::Vector2i GetCursorPositionOnScreen() const { return m_MousePositionOnScreen; }
	sf::Vector2i GetCursorPositionOnWindow() const { return m_MousePositionOnWindow; }
	sf::Vector2f GetCursorPositionView() const { return m_MousePositionView; }
	sf::Sprite& GetSprite();

private:
	sf::Vector2i m_MousePositionOnScreen;
	sf::Vector2i m_MousePositionOnWindow;
	sf::Vector2f m_MousePositionView;
	 
	sf::Texture m_CursorTexture;
	sf::Sprite m_CursorSprite;

};

