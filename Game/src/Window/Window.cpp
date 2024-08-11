#include "Window.h"
#include <iostream>
#include <fstream>
#include <sstream>


Window::Window()
	: m_GameTitle("Game")
	, m_Resolution(800, 600)
	, m_MaxFPS(240)
{
	LoadFromConfig();
	CreateRenderer();
}

void Window::LoadFromConfig()
{
	std::ifstream fileStream("Config/window.ini");
	if (!fileStream.is_open())
	{
		std::cerr << "Failed to load window.ini\n";
		return;
	}

	std::string line;
	std::getline(fileStream, m_GameTitle);

	fileStream >> m_Resolution.width >> m_Resolution.height;
	fileStream >> m_MaxFPS;
	fileStream.close();
}

void Window::CreateRenderer()
{
	m_Renderer.create(m_Resolution, m_GameTitle, sf::Style::Default);
	m_Renderer.setVerticalSyncEnabled(true);
	m_Renderer.setMouseCursorVisible(false);
	m_Renderer.setFramerateLimit(m_MaxFPS);
}

void Window::Update()
{
	sf::Event event{};
	sf::FloatRect visibleArea; 

/*	break;*/

	while (m_Renderer.pollEvent(event))
	{ 
		switch (event.type)
		{
		case sf::Event::Closed:
			Close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Tilde)
			{
				Close();
			}
			break;

		case sf::Event::Resized:
		{
			visibleArea = sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			m_Renderer.setView(sf::View(visibleArea));
		}
		}


	}
}

void Window::ChangeResolution(int x, int y)
{
	m_Resolution = sf::VideoMode(x, y);
	m_Renderer.create(m_Resolution, m_GameTitle, sf::Style::Default);
}