#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
	bool IsRunning();
	sf::RenderWindow m_WindowRenderer;
private:

public:
	Window();
	~Window();

	void Update();
	void Clear();
	void Draw(const sf::Drawable& drawable);
	void EndDraw();
};

