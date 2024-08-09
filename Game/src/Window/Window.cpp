#include "Window.h"
#include <iostream>
#include <fstream>
#include <sstream>


Window::Window() 
{
	CreateRenderer();

	m_Renderer.setVerticalSyncEnabled(true);
	m_Renderer.setMouseCursorVisible(false);
}


void Window::CreateRenderer()
{
	std::ifstream fileStream("Config/window.ini");
	if (!fileStream.is_open())
	{
		std::cerr << "COULD NOT OPEN WINDOW.INI";
		m_Renderer.close();
	}
	std::string line;

	std::getline(fileStream, m_GameTitle);
	fileStream >> m_Resolution.width >> m_Resolution.height;
	fileStream >> m_MaxFPS;

	m_Renderer.setFramerateLimit(m_MaxFPS);
	m_Renderer.create(m_Resolution, m_GameTitle, sf::Style::Default);
	fileStream.close();
}

void Window::ChangeResolution(int x, int y)
{
	m_Resolution = sf::VideoMode(x, y);
	m_Renderer.create(m_Resolution, m_GameTitle, sf::Style::Default);
}

void Window::Update()
{
	sf::FloatRect visibleArea;
	sf::Event event{};

	m_GameView = m_Renderer.getDefaultView();
	while (m_Renderer.pollEvent(event))
	{ 
		switch (event.type)
		{
		case sf::Event::Closed: m_Renderer.close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Tilde) m_Renderer.close();	
			break;

		case sf::Event::Resized:
			visibleArea = sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			m_Renderer.setView(sf::View(visibleArea));
		}
	}
}


void Window::Clear()
{ 
	m_Renderer.clear(sf::Color::Transparent);
}

void Window::Render(const sf::Drawable& drawable)
{
	m_Renderer.draw(drawable);
}

void Window::Display()
{
	m_Renderer.display();
}

bool Window::IsOpen() const
{
	return m_Renderer.isOpen();
}

sf::RenderWindow& Window::GetWindow() 
{
	return m_Renderer;
}

