#include "Window.h"

Window::Window() : m_WindowRenderer(sf::VideoMode(1920, 1080), "yuumi", sf::Style::Default)
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
	m_WindowRenderer.clear(sf::Color::White);
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



//sf::RenderWindow* Window::GetWindow() {}
// void Window::InitWindow(int x, int y)
// {
// 		sf::VideoMode SetWindowSize(x, y);
// 		m_WindowRenderer = new sf::RenderWindow(SetWindowSize, "Yuumi", sf::Style::Default);
// 		m_WindowRenderer->setFramerateLimit(144);
// 		m_WindowRenderer->setVerticalSyncEnabled(true);
// }
// 
// sf::RenderWindow* Window::GetWindow()
// {
// 	return m_WindowRenderer;
// }