#include "InitSprites.h"

InitSprites::InitSprites()
{

}

void* InitSprites::SetSpriteTexture(sf::Texture* texture, sf::Sprite& sprite)
{
	sprite.setTexture(*texture);
}

// y, x are representing the Sprite POSITION on the spritesheet.
void InitSprites::SetSpriteRect(sf::Sprite& sprites, int x, int y, int width, int height)
{
	sprites.setTextureRect(sf::IntRect(x, y, width, height));
}

void InitSprites::SetSpriteDefaultPosition(sf::Sprite& sprite, float x, float y)
{
	sprite.setPosition(x, y);
}

void InitSprites::SetSpriteScale(sf::Sprite& sprite, float x, float y)
{
	sprite.setScale(x, y);
}
