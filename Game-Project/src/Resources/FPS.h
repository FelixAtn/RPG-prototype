#pragma once
#include "SFML/Graphics.hpp"
#include "Window/Window.h"

class Fps
{
public:
	Fps();
	Fps(Window& window);
	static void Print(float deltaTime);
	void Update(float deltaTime);
	void Draw(Window& window);

private:
	sf::Text m_FpsText;
	sf::Font m_Font;
};

