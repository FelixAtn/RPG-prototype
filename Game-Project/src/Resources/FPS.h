#pragma once
#include "SFML/Graphics.hpp"
#include "Window/Window.h"

class Fps 
{
public:
	Fps(Window& window);
	void Update(float deltaTime);
	void Draw(Window& window) const;

private:
	sf::Text m_FpsText;
	sf::Font m_Font;

	float m_Timer;
	float m_DrawPerFrame;
};

