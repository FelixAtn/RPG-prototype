#pragma once
#include "Window/Window.h"
#include "Resources/TextureManager.h"
#include <SFML/Graphics.hpp>
#include "Input/Keyboard.h" 
#include "Input/Mouse.h"

class Entity
{
public:
	Entity() : m_TextureManager(TextureManager::getInstance()) {};
	virtual ~Entity() {};

	virtual void UpdateData(Keyboard& input, float deltaTime) = 0;
	virtual void Render(Window& window) = 0;

	sf::Texture GetTextureSize(const std::string& textureName);

	const sf::Sprite& GetSprite() const;
	sf::Sprite& GetSprite();

	sf::Vector2f GetSpritePosition() const;
	sf::Vector2f GetOrigin() const; 
	sf::Vector2f GetScale() const;
	sf::IntRect GetRect() const;
	float GetRotation() const;
	sf::FloatRect GetBounds() const;
	sf::Vector2f GetSize() const;

	void SetTexture(const std::string& textureName);
	void SetPosition(float x, float y);
	void SetOrigin(float x, float y);
	void SetRotation(float angle);
	void SetScale(float x, float y);
	void SetRect(int x, int y, int width, int height);

protected:
	TextureManager& m_TextureManager;
	sf::Sprite m_Sprite;
	std::string m_Name;
	std::string m_Type;
	sf::Vector2f m_Position;



};
