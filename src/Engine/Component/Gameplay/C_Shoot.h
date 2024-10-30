#pragma once

class C_Shoot : public I_Component
{
public:
	C_Shoot(const std::string& projectileName);

	void Update(float deltaTime) override;
	void Shoot(Object& attacker, Object& target, float deltaTime);
	void DrawProjectile(Window& window);
	std::vector<sf::Sprite>& GetSprites() { return m_ProjectileList; }

private:
	std::string m_ProjectileName;
	std::vector<sf::Sprite> m_ProjectileList;
	std::vector<Vector2f> m_ProjectileVelocities;
	Timer m_CooldownBetweenShot;
	bool m_CanShoot;
	std::vector<Object*> m_PotentialTargets;
	float m_MaxRange;
};

