#include "stdafx.h"
#include "Window.h"

void Window::Init(const std::string& fileName)
{
	YAML::Node config = YAML::LoadFile(fileName);

	WindowData m_WindowData;

	// Get window title
	m_WindowData.title = config["window"]["title"].as<std::string>();

	// Get window size (width and height)
	m_WindowData.width = config["window"]["width"].as<int>();
	m_WindowData.height = config["window"]["height"].as<int>();

	// Get video mode (width, height, bits per pixel)
	m_WindowData.videoMode = sf::VideoMode(
		config["window"]["videoMode"]["width"].as<int>(),
		config["window"]["videoMode"]["height"].as<int>(),
		config["window"]["videoMode"]["bitsPerPixel"].as<int>()
	);

	// Get window style
	m_WindowData.style = config["window"]["style"].as<sf::Uint32>();

	// Get background color (RGBA)
	m_WindowData.backgroundColor = sf::Color(
		config["window"]["backgroundColor"]["r"].as<sf::Uint8>(),
		config["window"]["backgroundColor"]["g"].as<sf::Uint8>(),
		config["window"]["backgroundColor"]["b"].as<sf::Uint8>(),
		config["window"]["backgroundColor"]["a"].as<sf::Uint8>()
	);

	// Get other window settings
	m_WindowData.isCursorVisible = config["window"]["isCursorVisible"].as<bool>();
	m_WindowData.isVSyncOn = config["window"]["isVSyncOn"].as<bool>();
	m_WindowData.isFullscreenOn = config["window"]["isFullscreenOn"].as<bool>();
	m_WindowData.isAntiAliasingOn = config["window"]["isAntiAliasingOn"].as<bool>();
	m_WindowData.isWindowResizable = config["window"]["isWindowResizable"].as<bool>();
	m_WindowData.shouldCaptureMouseEvents = config["window"]["shouldCaptureMouseEvents"].as<bool>();
	m_WindowData.shouldCaptureKeyboardEvents = config["window"]["shouldCaptureKeyboardEvents"].as<bool>();

	m_Window.create(m_WindowData.videoMode, m_WindowData.title, m_WindowData.style);
}

void Window::SetFullscreen(bool enabled)
{
	m_WindowData.isFullscreenOn = enabled;

	if (enabled)
	{
		SetStyle(sf::Style::Fullscreen);
		sf::VideoMode fullscreen = sf::VideoMode(m_WindowData.width, m_WindowData.height);
		SetVideoMode(fullscreen);
		m_Window.create(fullscreen, m_WindowData.title, m_WindowData.style);
	}
	else
	{
		SetStyle(sf::Style::Default);
		sf::VideoMode windowed = sf::VideoMode(m_WindowData.width, m_WindowData.height);
		SetVideoMode(windowed);
		m_Window.create(sf::VideoMode(m_WindowData.width, m_WindowData.height), m_WindowData.title, m_WindowData.style);
	}
}

void Window::SetWindowed(bool enabled)
{

}

void Window::ToggleFullscreen()
{

}
