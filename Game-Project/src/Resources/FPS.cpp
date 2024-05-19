#include "FPS.h"
#include <iostream>
#include <string.h>
Fps::Fps(Window& window) : m_Timer(0), m_DrawPerFrame(0.1f)
{
	if (m_Font.loadFromFile("Vegur-Yg1a.otf"))
	{
		std::cout << "Font: loaded";
		m_FpsText.setFont(m_Font);
		m_FpsText.setPosition(0, 0);
	}
}

Fps::Fps(){}


void Fps::Update(float deltaTime)
{
	m_Timer += deltaTime;

	if(m_Timer >= m_DrawPerFrame)
	{
	int frames = (int)1.f / deltaTime;
	std::string fps = "FPS: " + std::to_string(frames);
	m_FpsText.setString(fps);
	m_Timer = 0;
	}
}
void Fps::Draw(Window& window)
{
	window.Draw(m_FpsText);
}
