#include "Button.h"
#include "Resources/GameTools.h"
#include "iostream"


Button::Button(const std::string& buttonText, float xPos, float yPos, float xScale, float yScale)
	: isCursorOnButton(false)
	, m_Text(buttonText)
{
	std::cout << "\n- Button Created ->  " << buttonText << "\n";
	CreateButton(xPos, yPos, xScale, yScale);
	CreateText(buttonText, xPos, yPos);
}
Button::~Button()
{
	std::cout << "\nBUTTON DESTROYED: " << m_Text;
}

void Button::CreateButton(float xPos, float yPos, float xScale, float yScale)
{
	Tools::Texture::Load(m_Texture, Paths::assets + Files::TextureFiles::menuButton);
	m_SpriteButton.setTextureRect(sf::IntRect(256, 0, 256, 64));
	m_SpriteButton.setTexture(m_Texture);
	m_SpriteButton.setScale(xScale, yScale);
	m_SpriteButton.setPosition(xPos, yPos);
}
void Button::CreateText(const std::string buttonText, float xPos, float yPos)
{
	Tools::Font::Set(font, Paths::fonts, Files::Fonts::fpsFont);
	m_TextOnButton.setFont(font);
	m_TextOnButton.setCharacterSize(16);
	m_TextOnButton.setString(buttonText);
	m_TextOnButton.setFillColor(sf::Color::White);
	sf::Vector2f textPos = CalculateTextPosition(xPos, yPos);
	m_TextOnButton.setPosition(textPos);
}
void Button::Update(sf::Sprite& cursor)
{
	if (!m_SpriteButton.getGlobalBounds().intersects(cursor.getGlobalBounds()))
	{
		m_SpriteButton.setTextureRect(sf::IntRect(256, 0, 256, 64));
		isCursorOnButton = false;
		return;
	}
	isCursorOnButton = true;
	m_SpriteButton.setTextureRect(sf::IntRect(0, 0, 256, 64));
}
void Button::Draw(Window& window)
{
	window.Render(m_SpriteButton);
	window.Render(m_TextOnButton);
}

sf::Vector2f Button::CalculatedCenterOrigin(sf::Vector2f size) const
{
	return size * 0.5f;
}
sf::Vector2f Button::CalculateTextPosition(float xPos, float yPos) 
{
	m_ButtonCenter = CalculatedCenterOrigin(sf::Vector2f(m_SpriteButton.getGlobalBounds().width, m_SpriteButton.getGlobalBounds().height));
	m_TextCenter = CalculatedCenterOrigin(sf::Vector2f(m_SpriteButton.getGlobalBounds().width, m_SpriteButton.getGlobalBounds().height));

	sf::Vector2f textPos = sf::Vector2f
	(xPos + m_ButtonCenter.x - (m_TextCenter.x * 0.5f),
	yPos + m_ButtonCenter.y - (m_TextCenter.y * 0.5f));

	return textPos;
}



