#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();

	void Update();
	void ChangeResolution(int x, int y);

	inline operator sf::RenderWindow& () { return m_Renderer; }
	inline operator const sf::RenderWindow& () const { return m_Renderer; }
	inline operator sf::Event& () { return m_WindowEvent; }
	inline operator const sf::Event& () { return m_WindowEvent; }

	inline bool IsOpen() const { return m_Renderer.isOpen(); }
	inline void Clear() { m_Renderer.clear(sf::Color::Transparent); }
	inline void Draw(const sf::Drawable& drawable) { m_Renderer.draw(drawable); }
	inline void Display() { m_Renderer.display(); }
	inline void Close() { m_Renderer.close(); }
	inline sf::Vector2f MapPixelToCoords(const sf::Vector2i& point) { return m_Renderer.mapPixelToCoords(point); }

	inline void SetView(sf::View view) { m_WindowView = &view; }
	inline void SetViewCenter(sf::Vector2f centerCoord) { m_WindowView->setCenter(centerCoord); }
	inline sf::View* GetView() { return m_WindowView; }

	inline sf::Vector2f& WindowEventSize() { sf::Vector2f size = { 
		static_cast<float>(m_WindowEvent.size.width)
		, static_cast<float>(m_WindowEvent.size.height) }; return size; }

private:
	void LoadFromConfig();
	void CreateRenderer();

private:
	sf::RenderWindow m_Renderer;
	sf::Event m_WindowEvent;
	sf::View* m_WindowView;
	// Config
	std::string m_GameTitle;
	sf::VideoMode m_Resolution;
	int m_MaxFPS;
};
