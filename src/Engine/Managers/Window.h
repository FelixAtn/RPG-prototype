#pragma once
constexpr int DEFAULT_RESOLUTION_WIDTH = 1920;
constexpr int DEFAULT_RESOLUTION_HEIGHT = 1080;
const sf::Color RED_COLOR = { 120,6,6 };

class Window
{
public:
	Window();
	inline sf::RenderWindow& GetWindowRenderer() { return m_Window; }
	inline Vector2u GetPosition() { m_Window.getPosition(); }
	inline Vector2u GetSize() { m_Window.getSize(); }
	inline const sf::View& GetWindowView() const { m_Window.getView(); }
	inline const sf::View& GetDefaultWindowView() const { m_Window.getDefaultView(); }
	inline const sf::Event& GetEvent() const { return m_Event; }

	inline void SetView(const sf::View& view) { m_Window.setView(view);  }
	inline void SetMouseCursorVisible(bool visible) { m_Window.setMouseCursorVisible(visible); };

	inline bool IsOpen() const { return m_Window.isOpen(); }
	inline void Clear(sf::Color backgroundColor = RED_COLOR) 
	{ 
		m_Window.clear(backgroundColor);
	}
	inline void Display() { m_Window.display(); }
	inline void Draw(sf::Drawable& drawable) { m_Window.draw(drawable); }

	void Create(unsigned int width, unsigned int height, sf::Uint32 windowStyle = sf::Style::Default);
	void HandleEvents(); 
	


private:
	sf::RenderWindow m_Window;
	sf::Event m_Event;
};
