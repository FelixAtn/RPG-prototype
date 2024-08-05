#include "GameTools.h"
#include <iostream>

bool Tools::Texture::Load(sf::Texture& texture, const std::string& textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		std::cerr << ": TEXTURE\n";
		return false;
	}
	texture.setSmooth(true);
	return true;
}

bool Tools::Music::Set(sf::Music& music, const std::string& fileLocation, const std::string& fileName)
{
	std::string file = fileLocation + fileName;

	if (!music.openFromFile(file))
	{
		std::cerr << ": SOUND\n";
		return false;
	}
	return true;
}

bool Tools::Font::Set(sf::Font& font, const std::string& fileLocation, const std::string& fileName)
{
	std::string file = fileLocation + fileName;
	if (!font.loadFromFile(file))
	{
		std::cerr << ": FONT\n";
		return false;
	};
	return true;
}



