#include "TextureManager.h"
#include "resources/GameTools.h"
#include <iostream>

TextureManager::TextureManager()
{
	std::cout << "TEXTURE MANAGER INSTANTIATED \n";
	LoadTexture("reaper", Paths::assets + Files::TextureFiles::ninja);
	LoadTexture("wolf", Paths::assets + Files::TextureFiles::enemy);
	LoadTexture("ghost", Paths::assets + Files::TextureFiles::ghost);
}

TextureManager::~TextureManager()
{
}

TextureManager& TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

void TextureManager::LoadTexture(const std::string& name, const std::string& filePath)
{
	sf::Texture texture;
	if (texture.loadFromFile(filePath))
	{
		m_Textures[name] = texture;
	}
	else
	{
		std::cerr << "Failed to load texture: " << filePath << std::endl;
	}
}

const sf::Texture& TextureManager::GetTexture(const std::string& name)
{
	return m_Textures.at(name);
}
