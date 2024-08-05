#include "Camera.h"

Camera::Camera(float zoomLevel) : m_ZoomLevel(zoomLevel)
{

}

sf::View Camera::GetView(sf::Vector2u windowSize)
{
	float aspectRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
	sf::Vector2f size;
	if(aspectRatio < 1.0f)
	{
		size = sf::Vector2f(m_ZoomLevel, m_ZoomLevel / aspectRatio);
	}
	else 
	{
		size = sf::Vector2f(m_ZoomLevel * aspectRatio, m_ZoomLevel);
	}
	return sf::View(sf::Vector2f(0, 0), size);
}
