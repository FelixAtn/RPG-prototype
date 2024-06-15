#include "Window.h"

Window::Window() : m_WindowRenderer(sf::VideoMode(1440, 1080), "yuumi", sf::Style::Default), 
m_PixelPosition(sf::Mouse::getPosition(m_WindowRenderer)), m_WorldPosition(m_WindowRenderer.mapPixelToCoords(m_PixelPosition))
{
	m_WindowRenderer.setVerticalSyncEnabled(true);
}
Window::~Window(){}

void Window::Update()
{
	sf::Event event;
	while (m_WindowRenderer.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_WindowRenderer.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_WindowRenderer.close();
				break;
			}
		}
	}
}
void Window::Clear()
{
	m_WindowRenderer.clear(sf::Color::Cyan);
}
void Window::Draw(const sf::Drawable& drawable)
{
	m_WindowRenderer.draw(drawable);
}
void Window::EndDraw()
{
	m_WindowRenderer.display();
}
bool Window::IsRunning() 
{
	return m_WindowRenderer.isOpen();
}
sf::Vector2i& Window::GetPixelPosition()
{
	return m_PixelPosition;
}
sf::Vector2f& Window::GetWorldPosition()
{
	return m_WorldPosition;
}
void Window::setWindowView(sf::View view)
{
	m_WindowRenderer.setView(view);
}


