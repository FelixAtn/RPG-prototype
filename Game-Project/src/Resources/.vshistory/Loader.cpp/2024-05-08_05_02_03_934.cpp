#include "Loader.h"
#include <filesystem>
#include <iostream>

Loader::Loader() {}

void Loader::UpdateFileLocation()
{
	std::filesystem::path projectDir = std::filesystem::absolute(std::filesystem::path(__FILE__)).parent_path().parent_path().parent_path().parent_path();
	std::filesystem::path assetPath = projectDir / "Assets/";

	m_FullPath = assetPath.string();
	std::replace(m_FullPath.begin(), m_FullPath.end(), '/', '\\');
}

void Loader::Load(sf::Texture desiredTexture, std::string fileName)
{
	UpdateFileLocation();
	if (!desiredTexture.loadFromFile(m_FullPath + fileName))
	{
		std::cerr << ": failed to load.\n";
	}
	else { std::cout << fileName << ": success.\n"; }
}


