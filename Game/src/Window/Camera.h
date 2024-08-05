#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera(float zoomLevel);
	sf::View GetView(sf::Vector2u windowSize);

	float m_ZoomLevel;
};

