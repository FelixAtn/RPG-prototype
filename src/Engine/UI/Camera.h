#pragma once
constexpr float DIVISOR = 0.5f;

class Camera
{
public:
	Camera(Window& window, const Vector2f& initialSize);

	void Follow(const Vector2f targetToFollow) { m_View.setCenter(targetToFollow); }
	void Zoom(float zoomValue) { m_View.zoom(zoomValue); }
	void Move(const Vector2f offest) { m_View.move(offest); }
	void Apply() { m_Window.SetView(m_View); }
	void Reset();

private:
	Window& m_Window;
	sf::View m_View;
	Vector2f m_OriginalSize;
	
};