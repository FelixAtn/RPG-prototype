#pragma once
#include "SFML/Graphics.hpp"
#include "Window/Window.h"

class Button
{
public:
	Button(const std::string& buttonText, float xPos, float yPos, float xScale, float yScale);
	~Button();

	void CreateButton(float xPos, float yPos, float xScale, float yScale);
	void CreateText(const std::string buttonText, float xPos, float yPos);
	void Update(sf::Sprite& cursor);
	void Draw(Window& window);

	sf::Vector2f CalculatedCenterOrigin(sf::Vector2f size) const;
	sf::Vector2f CalculateTextPosition(float xPos, float yPos) ;
	const bool IsCursorOn() const { return isCursorOnButton; };

private:
	sf::Texture m_Texture;
	sf::Sprite m_SpriteButton; 
	std::string m_Text;
	sf::Text m_TextOnButton;
	sf::Font font;

	sf::Vector2f m_ButtonCenter;
	sf::Vector2f m_TextCenter; 

	bool isCursorOnButton;


	int m_xRect;
	int m_yRect;
	int m_xSize;
	int m_ySize;
};

