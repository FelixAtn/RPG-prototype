#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Loader
{
public:
	Loader();
	void Load(sf::Texture desiredTexture, std::string fileName);
	void UpdateFileLocation();
private:
	std::string m_FullPath;
};

