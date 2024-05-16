#pragma once
#include <string>
#include <SFML/Graphics.hpp>
struct Loader
{
	Loader();
	void Load(sf::Texture& desiredTexture, std::string fileName);
	void UpdateFileLocation();
	std::string m_FullPath;
};

