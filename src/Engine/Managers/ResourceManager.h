#pragma once

enum class ObjectType;

class ResourceManager 
{
public:
	static ResourceManager& Get()
	{
		static ResourceManager instance;
		return instance;
	}

	bool LoadTexture(const std::string& name, const std::string& filename);
	sf::Texture& GetTexture(const std::string& name);


	bool LoadFont(const std::string& name, const std::string& filename);
	sf::Font& GetFont(const std::string& name);

	bool LoadSoundBuffer(const std::string& name, const std::string& filename);
	sf::SoundBuffer* GetSoundBuffer(const std::string& name);

	bool LoadMusic(const std::string& name, const std::string& filename);
	sf::Music& GetMusic(const std::string& name);

	void LoadCharacterFile(const std::string& fileName);
	YAML::Node& GetCharacterFile();

	void LoadMapFile(const std::string& fileName);
	YAML::Node& GetMapFile();

private:
	ResourceManager() = default;
	~ResourceManager() = default;
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator= (const ResourceManager&) = delete;

	std::map<std::string, std::unique_ptr<sf::Texture>> m_Textures;
	std::map<std::string, std::unique_ptr<sf::Font>> m_Fonts;
	std::map<std::string, std::unique_ptr<sf::SoundBuffer>> m_SoundBuffers;
	std::map<std::string, std::unique_ptr<sf::Music>> m_Music;

	YAML::Node m_CharacterFile;
	YAML::Node m_Maps;
};

