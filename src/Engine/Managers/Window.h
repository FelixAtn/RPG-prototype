#pragma once
constexpr int DEFAULT_RESOLUTION_WIDTH = 1920;
constexpr int DEFAULT_RESOLUTION_HEIGHT = 1080;
const sf::Color RED_COLOR = { 120,6,6 };

struct WindowData
{
	sf::View defaultView;
	sf::View currentView;
	std::string title;
	sf::Image icon;
	sf::VideoMode videoMode;
	sf::Color backgroundColor;
	Vector2i windowPosition;
	sf::Uint32 style;
	int width;
	int height;
	bool isCursorVisible;
	bool isCursorWithinWindow;
	bool isVSyncOn;
	bool isFullscreenOn;
	bool isAntiAliasingOn;
	bool isWindowResizable;
	bool shouldCaptureMouseEvents;
	bool shouldCaptureKeyboardEvents;
};

class Window
{
public:
	inline operator const sf::RenderWindow&() const { return m_Window; }
	inline operator sf::RenderWindow&() { return m_Window; }

	void Init(const std::string& fileName);

	bool IsOpen() const { return m_Window.isOpen(); }
	void Clear(sf::Color backgroundColor = RED_COLOR)
	{
		m_Window.clear(backgroundColor);
	}
	void Display() { m_Window.display(); }
	void Draw(sf::Drawable& drawable) { m_Window.draw(drawable); }

	bool PollEvent(sf::Event& event) { return m_Window.pollEvent(event); }

	void Close() { m_Window.close(); }

	// Getters for WindowData
	const sf::View& GetDefaultView() const { return m_WindowData.defaultView; }
	const sf::View& GetCurrentView() const { return m_WindowData.currentView; }
	const std::string& GetTitle() const { return m_WindowData.title; }
	const sf::Image& GetIcon() const { return m_WindowData.icon; }
	const sf::VideoMode& GetVideoMode() const { return m_WindowData.videoMode; }
	const sf::Color& GetBackgroundColor() const { return m_WindowData.backgroundColor; }
	unsigned int GetWidth() const { return m_WindowData.width; }
	unsigned int GetHeight() const { return m_WindowData.height; }
	Vector2i GetSize() { return { m_WindowData.width, m_WindowData.height }; }
	const sf::Vector2i& GetPosition() const { return m_WindowData.windowPosition; }
	sf::Uint32 GetStyle() const { return m_WindowData.style; }
	bool IsCursorVisible() const { return m_WindowData.isCursorVisible; }
	bool IsCursorWithinWindow() const { return m_WindowData.isCursorWithinWindow; }
	bool IsVSyncOn() const { return m_WindowData.isVSyncOn; }
	bool IsFullscreenOn() const { return m_WindowData.isFullscreenOn; }
	bool IsAntiAliasingOn() const { return m_WindowData.isAntiAliasingOn; }
	bool IsWindowResizable() const { return m_WindowData.isWindowResizable; }
	bool ShouldCaptureMouseEvents() const { return m_WindowData.shouldCaptureMouseEvents; }
	bool ShouldCaptureKeyboardEvents() const { return m_WindowData.shouldCaptureKeyboardEvents; }

 	// Setters for WindowData
	void SetDefaultView(const sf::View& view) { m_WindowData.defaultView = view; }
	void SetCurrentView(const sf::View& view) { m_WindowData.currentView = view; }
	void SetTitle(const std::string& title) { m_WindowData.title = title; }
	void SetIcon(const sf::Image& icon) { m_WindowData.icon = icon; }
	void SetVideoMode(const sf::VideoMode& videoMode) { m_WindowData.videoMode = videoMode; }
	void SetBackgroundColor(const sf::Color& color) { m_WindowData.backgroundColor = color; }
	void SetWidth(unsigned int width) { m_WindowData.width = width; }
	void SetHeight(unsigned int height) { m_WindowData.height = height; }
	void SetPosition(const sf::Vector2i& position) 
	{
		m_WindowData.windowPosition = position;
		m_Window.setPosition(position); // Update SFML window position
	}
	void SetStyle(sf::Uint32 style) { m_WindowData.style = style; }
	void SetCursorVisible(bool visible) { m_WindowData.isCursorVisible = visible; }
	void SetVSync(bool enabled) { m_WindowData.isVSyncOn = enabled; }
	void SetFullscreen(bool enabled);
	void SetWindowed(bool enabled);
	void ToggleFullscreen();
	void SetAntiAliasing(bool enabled) { m_WindowData.isAntiAliasingOn = enabled; }
	void SetWindowResizable(bool resizable) { m_WindowData.isWindowResizable = resizable; }
	void SetCaptureMouseEvents(bool capture) { m_WindowData.shouldCaptureMouseEvents = capture; }
	void SetCaptureKeyboardEvents(bool capture) { m_WindowData.shouldCaptureKeyboardEvents = capture; }

private:
	WindowData m_WindowData;
	sf::RenderWindow m_Window;
};

