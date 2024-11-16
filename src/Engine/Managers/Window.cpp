#include "stdafx.h"
#include "Window.h"

void Window::Init(const std::string& fileName)
{
	LoadSettings(fileName);

	create(sf::VideoMode(m_WindowSettings.width, m_WindowSettings.height), m_WindowSettings.title, m_WindowSettings.style);

    this->setFramerateLimit(m_WindowSettings.maxFPS);
	this->setVerticalSyncEnabled(m_WindowSettings.isVSyncOn);
	this->setMouseCursorVisible(m_WindowSettings.isCursorVisible);
	
}

void Window::LoadSettings(const std::string& fileName)
{
	YAML::Node config = YAML::LoadFile(fileName);

	m_WindowSettings.title = config["window"]["title"].as<std::string>();
	m_WindowSettings.width = config["window"]["width"].as<int>();
	m_WindowSettings.height = config["window"]["height"].as<int>();
	m_WindowSettings.maxFPS = config["window"]["maxFPS"].as<int>();
 	m_WindowSettings.style = config["window"]["style"].as<sf::Uint32>();

 	// Get other window settings
 	m_WindowSettings.isCursorVisible = config["window"]["isCursorVisible"].as<bool>();
 	m_WindowSettings.isVSyncOn = config["window"]["isVSyncOn"].as<bool>();
 	m_WindowSettings.isFullscreenOn = config["window"]["isFullscreenOn"].as<bool>();
}

void Window::SaveSettings(const std::string& fileName) const
{
//         YAML::Node config;
// 
//         // Set window settings
//         config["window"]["title"] = m_WindowSettings.title;
//         config["window"]["width"] = m_WindowSettings.width;
//         config["window"]["height"] = m_WindowSettings.height;
//         config["window"]["maxFPS"] = m_WindowSettings.maxFPS;
//         config["window"]["style"] = m_WindowSettings.style;
// 
//         // Save other window settings
//         config["window"]["isCursorVisible"] = m_WindowSettings.isCursorVisible;
//         config["window"]["isVSyncOn"] = m_WindowSettings.isVSyncOn;
//         config["window"]["isFullscreenOn"] = m_WindowSettings.isFullscreenOn;
// 
//         // Write to file
//         std::ofstream fout(fileName);
//         fout << config;
}

