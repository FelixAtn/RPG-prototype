#include "FPS.h"
#include <iostream>
#include <string.h>
Fps::Fps(Window& window)
{
	if (m_Font.loadFromFile("Vegur-Yg1a.otf"))
	{
		std::cout << "Font: loaded";
		m_FpsText.setFont(m_Font);
		m_FpsText.setPosition(0, 0);
	}
}

Fps::Fps(){}

void Fps::Print(float deltaTime)
{
	
}
void Fps::Update(float deltaTime)
{
	int frames = (int)1.f / deltaTime;
	std::string fps = "FPS: " + std::to_string(frames) + " Te Iubesc Mult Alina si Yuumi <3 <3 ";
	m_FpsText.setString(fps);
}
void Fps::Draw(Window& window)
{
	window.Draw(m_FpsText);
}
