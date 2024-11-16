#pragma once

const sf::Color RED_COLOR = { 120,6,6 };


class Window : public sf::RenderWindow
{
public:
	inline operator const Window&() const { return *this; }
	inline operator Window&() { return *this; }

	void Init(const std::string& fileName);
	void LoadSettings(const std::string& fileName);
	void SaveSettings(const std::string& fileName) const;

	void Draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default) { draw(drawable, states); }
	void DrawVertices(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type) { draw(vertices, vertexCount, type); }
	void DrawVertexBuffer(const sf::VertexBuffer& vertexBuffer, sf::RenderStates states) { draw(vertexBuffer, states); }
	void DrawVertexBuffer(const sf::VertexBuffer& vertexBuffer) { draw(vertexBuffer); }
	void DrawVertexBufferRange(const sf::VertexBuffer& vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, sf::RenderStates states) { draw(vertexBuffer, firstVertex, vertexCount, states); }
	void DrawVertexBufferRange(const sf::VertexBuffer& vertexBuffer, std::size_t firstVertex, std::size_t vertexCount) { draw(vertexBuffer, firstVertex, vertexCount); }

	const std::string& GetTitle() const { return m_WindowSettings.title; }
	const int GetWidth() const { return m_WindowSettings.width; }
	const int GetHeight() const { return m_WindowSettings.height; }
	const int GetMaxFPS() const { return m_WindowSettings.maxFPS; }
	const sf::Uint32 GetStyle() const { return m_WindowSettings.style; }
	const bool IsCursorVisible() const { return m_WindowSettings.isCursorVisible; }
	const bool IsVSyncOn() const { return m_WindowSettings.isVSyncOn; }
	const bool IsFullscreenOn() const { return m_WindowSettings.isFullscreenOn; }

	void SetTitle(const std::string& title) { m_WindowSettings.title = title; }
	void SetWidth(int width) { m_WindowSettings.width = width; }
	void SetHeight(int height) { m_WindowSettings.height = height; }
	void SetMaxFPS(int maxFPS) { m_WindowSettings.maxFPS = maxFPS; }
	void SetStyle(sf::Uint32 style) { m_WindowSettings.style = style; }
	void SetCursorVisible(bool isCursorVisible) { m_WindowSettings.isCursorVisible = isCursorVisible; }
	void SetVSyncOn(bool isVSyncOn) { m_WindowSettings.isVSyncOn = isVSyncOn; }
	void SetFullscreenOn(bool isFullscreenOn) { m_WindowSettings.isFullscreenOn = isFullscreenOn; }



private:
	struct WindowSettings
	{
		std::string title;
		int width;
		int height;
		int maxFPS;
		sf::Uint32 style;
		bool isCursorVisible;
		bool isVSyncOn;
		bool isFullscreenOn;
	};

	WindowSettings m_WindowSettings;
};

