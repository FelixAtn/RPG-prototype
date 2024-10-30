#include "stdafx.h"
#include "Window.h"

Window::Window()
{
	
};

void Window::Create(unsigned int width, unsigned int height, sf::Uint32 windowStyle /*= sf::Style::Default*/)
{
	m_Window.create(sf::VideoMode(width, height), "Game");
	m_Window.setMouseCursorVisible(false);
}

void Window::HandleEvents()
{
	sf::Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
	}
	m_Event = event;
}
