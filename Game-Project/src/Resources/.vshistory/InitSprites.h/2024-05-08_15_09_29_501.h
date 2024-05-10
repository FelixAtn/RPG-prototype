#pragma once
#include <SFML/Graphics.hpp>
#include "Resources/Loader.h"
class InitSprites
{
public:
	InitSprites();
static void SetSpriteTexture(sf::Texture* texture, sf::Sprite& sprite);
static void SetSpriteRect(sf::Sprite& sprites, int x, int y, int width, int height);
static void SetSpriteDefaultPosition(sf::Sprite& sprite, float x, float y);
static void SetSpriteScale(sf::Sprite& sprite, float x, float y);
};

