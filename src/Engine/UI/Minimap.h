#pragma once

class Minimap
{
public:
	Minimap(const Vector2f& worldSize, const sf::FloatRect& viewPort)
	{
		m_MinimapView.setSize(worldSize);
		m_MinimapView.setViewport(viewPort);
	}

	void SetCenter(const Vector2f& centerPosition) { m_MinimapView.setCenter(centerPosition); }
	void SetWorldSize(Vector2f& worldSize) { m_MinimapView.setSize(worldSize); }
	void Apply(Window& window) { window.SetView(m_MinimapView);}

private:
	sf::View m_MinimapView;
};