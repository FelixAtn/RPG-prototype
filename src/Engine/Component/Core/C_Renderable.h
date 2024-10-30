#pragma once


class C_Renderable : public I_Component
{
public:
	virtual ~C_Renderable() = default;
	virtual void Draw(Window& window) = 0;
	virtual Vector2f GetDrawingPosition() const = 0;
	virtual int GetDrawOrder() const { return 0; }
};

struct C_Sprite : public C_Renderable
{
public:
	C_Sprite() = default;

	// Constructor with texture name
	C_Sprite(const std::string& textureName)
		: m_Sprite(ResourceManager::Get().GetTexture(textureName))
	{}

	// Constructor with existing sprite
	C_Sprite(const sf::Sprite& sprite)
		: m_Sprite(sprite)
	{}

	void Draw(Window& window) override { window.Draw(m_Sprite); };
	Vector2f GetDrawingPosition() const override{ return m_Sprite.getPosition(); }
	sf::Sprite& GetSprite() { return m_Sprite; }

private:
	sf::Sprite m_Sprite;
};

