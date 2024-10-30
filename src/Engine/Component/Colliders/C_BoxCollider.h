#pragma once

class C_BoxCollider : public I_Component
{
public:
	void Init(sf::Sprite& sprite, const Vector2f& hitboxSize, const Vector2f hitboxOffset = Vector2f(0.0f, 0.0f));
	void Update();
	void Draw(Window& window) { window.Draw(m_HitBox); }

	sf::Vector2f GetCenterRect();
	sf::Vector2f GetPosition();
	bool CheckAndResolve(C_BoxCollider& target, float pushValue);
	Vector2f GetHitboxCenter() const { return m_HitboxCenter; }
private:
	sf::Sprite* m_Sprite;
	sf::RectangleShape m_HitBox;
	Vector2f m_Offset;
	Vector2f m_HitboxCenter;
};

