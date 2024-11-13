#include "stdafx.h"
#include "ResourceManager.h"


// Load a texture
bool ResourceManager::LoadTexture(const std::string& name, const std::string& filename) 
{
	auto texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(filename))
	{
		std::string textureLog = "TEXTURE: " + name;
		Log::Print(textureLog, LogLevel::WARNING);
		return false; // Failed to load texture
	}
	m_Textures[name] = std::move(texture); // Store the texture
	return true;
}

// Get a texture
sf::Texture& ResourceManager::GetTexture(const std::string& name)
{
	return *m_Textures.at(name);
}

// Load a font
bool ResourceManager::LoadFont(const std::string& name, const std::string& filename)
{
	auto font = std::make_unique<sf::Font>();

	if (!font->loadFromFile(filename)) 
	{
		std::string fontLog = "FONT: " + name;
		Log::Print(fontLog, LogLevel::WARNING);
		return false; 
	}

	m_Fonts[name] = std::move(font); // Store the font
	return true;
}
// Get a font
sf::Font& ResourceManager::GetFont(const std::string& name) {
	return *m_Fonts.at(name);
}

// Load a sound buffer
bool ResourceManager::LoadSoundBuffer(const std::string& name, const std::string& filename)
{
	auto soundBuffer = std::make_unique<sf::SoundBuffer>();

	if (!soundBuffer->loadFromFile(filename)) 
	{
		std::string audioLog = "Audio: " + name;
		Log::Print(audioLog, LogLevel::WARNING);
		return false; 
	}
	m_SoundBuffers[name] = std::move(soundBuffer); // Store the sound buffer
	return true;
}
// Get a sound buffer
sf::SoundBuffer* ResourceManager::GetSoundBuffer(const std::string& name)
{
	auto it = m_SoundBuffers.find(name);

	if (it != m_SoundBuffers.end())
	{
		return it->second.get();
	}
	Log::Print("SOUND " + name, LogLevel::ERROR_);
	return nullptr;
}

// Load a melody
bool ResourceManager::LoadMusic(const std::string& name, const std::string& filename)
{
	auto music = std::make_unique<sf::Music>();
	if (!music->openFromFile(filename))
	{
		std::string musicLog = "MUSIC: " + name;
		Log::Print(musicLog, LogLevel::WARNING);
		return false;
	}
	m_Music[name] = std::move(music);
	return true;
}

//  Get a melody
sf::Music& ResourceManager::GetMusic(const std::string& name)
{
	return *m_Music.at(name);
}

void ResourceManager::LoadCharacterFile(const std::string& fileName)
{
	m_CharacterFile = YAML::LoadFile(fileName);
}

YAML::Node& ResourceManager::GetCharacterFile()
{
	return m_CharacterFile;
}

void ResourceManager::LoadMapFile(const std::string& fileName)
{
	m_Maps = YAML::LoadFile(fileName);
}

YAML::Node& ResourceManager::GetMapFile()
{
	return m_Maps;
}
