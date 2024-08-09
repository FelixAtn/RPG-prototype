#include "Button.h"
#include "Resources/GameTools.h"
#include "iostream"


Button::Button(const std::string& buttonText, float xPos, float yPos, float xScale, float yScale)
	: isCursorOnButton(false)
	, m_Text(buttonText)
	, m_xRect(256)
	, m_yRect(0)
	, m_xSize(256)
	, m_ySize(64)
{
	std::cout << "\n- Button Created ->  " << buttonText << "\n";
	CreateButton(xPos, yPos, xScale, yScale);
	CreateText(m_Text, xPos, yPos);
}

Button::~Button()
{
	std::cout << "\nBUTTON DESTROYED: " << m_Text;
}

void Button::CreateButton(float xPos, float yPos, float xScale, float yScale)
{
	Tools::Texture::Load(m_Texture, Paths::assets + Files::TextureFiles::menuButton);
	m_SpriteButton.setTextureRect(sf::IntRect(m_xRect, m_yRect, 256, 64));
	m_SpriteButton.setTexture(m_Texture);
	m_SpriteButton.setScale(xScale, yScale);
	m_SpriteButton.setPosition(xPos, yPos);
}

void Button::CreateText(const std::string buttonText, float xPos, float yPos)
{
	int letterSize = 16;
	Tools::Font::Set(font, Paths::fonts, Files::Fonts::fpsFont);
	m_TextOnButton.setFont(font);
	m_TextOnButton.setCharacterSize(letterSize);
	m_TextOnButton.setString(m_Text);
	m_TextOnButton.setFillColor(sf::Color::White);
	sf::Vector2f textPos = CalculateTextPosition(xPos, yPos);
	m_TextOnButton.setPosition(textPos);

}

void Button::Update(sf::Sprite& cursor)
{
	m_TextOnButton.setString(m_Text);
	if (!m_SpriteButton.getGlobalBounds().intersects(cursor.getGlobalBounds()))
	{
		m_xRect = 256;
		m_SpriteButton.setTextureRect(sf::IntRect(m_xRect, m_yRect, m_xSize, m_ySize));
		isCursorOnButton = false;
		return;
	}
	m_xRect = 0;
	isCursorOnButton = true;
	m_SpriteButton.setTextureRect(sf::IntRect(m_xRect, m_yRect, m_xSize, m_ySize));
}

void Button::Render(Window& window)
{
	window.Render(m_SpriteButton);
	window.Render(m_TextOnButton);
}

void Button::SetText(const std::string& text)
{
	m_Text = text;
}

sf::Vector2f Button::CalculatedCenterOrigin(sf::Vector2f size) const
{
	return size * 0.5f;
}

sf::Vector2f Button::CalculateTextPosition(float xPos, float yPos) 
{
	m_ButtonCenter = CalculatedCenterOrigin(sf::Vector2f(m_SpriteButton.getGlobalBounds().width, m_SpriteButton.getGlobalBounds().height));
	m_TextCenter = CalculatedCenterOrigin(sf::Vector2f(m_SpriteButton.getGlobalBounds().width, m_SpriteButton.getGlobalBounds().height));
	sf::Vector2f textPos = sf::Vector2f (xPos + m_ButtonCenter.x - (m_TextCenter.x * 0.5f), yPos + m_ButtonCenter.y - (m_TextCenter.y * 0.5f));

	return textPos;
}



