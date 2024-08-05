#pragma once
#include "Camera.h"

class Window
{
public:
	Window();

	void CreateRenderer();
	void ChangeResolution(int x, int y);


	const bool& IsOpen() const;
	void Update();
	void Clear();
	void Render(const sf::Drawable& drawable);
	void Display();
	sf::RenderWindow& GetWindow();

private:
	sf::RenderWindow m_Renderer;
	sf::View m_GameView;
	std::string m_GameTitle;
	sf::VideoMode m_Resolution;
	int m_MaxFPS;
};
