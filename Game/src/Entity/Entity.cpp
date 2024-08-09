#include "Entity.h"

void Entity::SetTexture(const std::string& textureName)
{
	const sf::Texture& texture = m_TextureManager.GetTexture(textureName);
	m_Sprite.setTexture(texture);
}

void Entity::SetPosition(float x, float y)
{
	m_Sprite.setPosition(x, y);
}

void Entity::SetOrigin(float x, float y)
{
	m_Sprite.setOrigin(x, y);
}

void Entity::SetRotation(float angle)
{
	m_Sprite.setRotation(angle);
}

void Entity::SetScale(float x, float y)
{
	m_Sprite.setScale(x, y);
}

void Entity::SetRect(int x, int y, int width, int height)
{
	m_Sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

sf::Texture Entity::GetTextureSize(const std::string& textureName)
{
	return m_TextureManager.GetTexture(textureName);
}

sf::Sprite& Entity::GetSprite()
{
	return m_Sprite;
}
const sf::Sprite& Entity::GetSprite() const
{
	return m_Sprite;
}

sf::Vector2f Entity::GetSpriteCenter() const
{
	sf::Vector2f center = m_Sprite.getGlobalBounds().getSize() * 0.5f;
	return center;
}

sf::Vector2f Entity::GetSpritePosition() const
{
	return m_Sprite.getPosition();
}

sf::Vector2f Entity::GetOrigin() const
{
	return m_Sprite.getOrigin();
}

sf::Vector2f Entity::GetScale() const
{
	return m_Sprite.getScale();
}

const sf::IntRect Entity::GetRect() const
{
	return m_Sprite.getTextureRect();
}

float Entity::GetRotation() const
{
	return m_Sprite.getRotation();
}

sf::Vector2f Entity::GetSize() const
{
	return m_Sprite.getGlobalBounds().getSize();
}

const sf::FloatRect Entity::GetBounds() const
{
	return m_Sprite.getGlobalBounds();
}
