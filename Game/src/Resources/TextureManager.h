#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager
{
public:
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	static TextureManager& getInstance();

	const sf::Texture& GetTexture(const std::string& name);

private:
	TextureManager();
	virtual ~TextureManager();

	void LoadTexture(const std::string& name, const std::string& filePath);

	std::unordered_map<std::string, sf::Texture> m_Textures;
};
