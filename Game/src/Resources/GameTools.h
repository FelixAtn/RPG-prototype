#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace Paths
{
	static const std::string maps = "maps/";
	static const std::string objects = "objects/";
	static const std::string sound = "sounds/";
	static const std::string fonts = "fonts/";
	static const std::string assets = "assets/";
	static const std::string config = "config/";
}

namespace Files
{
	namespace TextureFiles
	{
		static const std::string ninja = "Player/Ninja-Complete.png";
		static const std::string enemy = "Enemies/g_cast.png";
		static const std::string worldObjects = "WorldObjects/C_OutSide_Nature.png";
		static const std::string ground = "A2_Ground.png";
		static const std::string ghost = "Enemies/ghost1.png";
		static const std::string mainMenu = "Menu/MainMenuBackground.jpg";
		static const std::string menuButton = "Menu/MenuButton.png";
		static const std::string cursor = "Menu/Cursor Default.png";
	}

	namespace SoundFiles
	{
		static const std::string mainTheme = "12sky2-theme.mp3";
	}

	namespace MapFiles
	{
		static const std::string ground = "Ground.map";
	}

	namespace SolidObjectsFiles
	{
		static const std::string object = "Object.map";
	}

	namespace Fonts
	{
		static const std::string fpsFont = "HelpMe.otf";
	}

	namespace Configs
	{
		static const std::string window = "window.ini";
	}
}

// rename to Helper?
namespace Tools
{
	struct Texture
	{
		// rename texture to outTexture since it's an out parameter
		// rename Set to Load maybe since it modifies an outside variable anyway
		static bool Load(sf::Texture& textureLocation, const std::string& fileName);
	};

	struct Music
	{
		static bool Set(sf::Music& music, const std::string& fileLocation, const std::string& fileName);
	};

	struct Font
	{
		static bool Set(sf::Font& font, const std::string& fileLocation, const std::string& fileName);
	};


	// 	template <typename T, typename A, typename S> bool(T& fileType, A fileLocation, S fileName)
	// 	{
	// 		std::string files = fileLocation + fileName;
	// 		if (!fileType.loadFromFile(files))
	// 		{
	// 			std::cerr << ": failed to load.\n";
	// 			return false;
	// 		}
	// 		fileType.setSmooth(true);
	// 		return true;
	// 	}


};

