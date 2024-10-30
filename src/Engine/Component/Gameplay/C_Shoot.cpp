#include "stdafx.h"
#include "C_Shoot.h"

C_Shoot::C_Shoot(const std::string& projectileName)
	: m_ProjectileName(projectileName)
	, m_CooldownBetweenShot(1.0f)
	, m_CanShoot(true)
	, m_MaxRange(30.0f)

{
	m_ProjectileList.reserve(30);
}

void C_Shoot::Update(float deltaTime)
{

	// ************************* NOT DEFINITIVE *********************** Prototype 

	if (m_CooldownBetweenShot.HasTimePassed(deltaTime))
	{
		m_CanShoot = true;
	}

	auto projectileIt = m_ProjectileList.begin();
	auto velocityIt = m_ProjectileVelocities.begin();

	while (projectileIt != m_ProjectileList.end())
	{
		bool shouldRemove = false;

		// Update the position of the projectile
		projectileIt->move((*velocityIt) * deltaTime);

		sf::FloatRect projectileBounds = projectileIt->getGlobalBounds();

		// Check collision with all potential targets
		for (auto target : m_PotentialTargets)
		{

			if (target && target->GetComponent<C_Sprite>())
			{
				sf::FloatRect targetBounds = target->GetComponent<C_Sprite>()->GetSprite().getGlobalBounds();

				if (projectileBounds.intersects(targetBounds))
				{
					shouldRemove = true;

					// TODO later - Add collision, damage, effects logic
					if (auto targetData = target->GetComponent<C_AttributeData>())
					{
						targetData->SetHealth(20 - targetData->GetHealth()); 
					}
					break; 
				}
			}
		}

		// Remove the projectile if it collided
		if (shouldRemove)
		{
			projectileIt = m_ProjectileList.erase(projectileIt);
			velocityIt = m_ProjectileVelocities.erase(velocityIt);
		}
		else
		{
			++projectileIt;
			++velocityIt;
		}
	}

	m_PotentialTargets.clear();
}

void C_Shoot::Shoot(Object& attacker, Object& target, float deltaTime)
{
	// Add the target to potential targets if it's not already there
	if (std::find(m_PotentialTargets.begin(), m_PotentialTargets.end(), &target) == m_PotentialTargets.end())
	{
		m_PotentialTargets.push_back(&target);
	}

	if (m_CanShoot)
	{
		// Check vector limit
		if (m_ProjectileList.size() >= 20)
		{
			// Remove the oldest projectile
			m_ProjectileList.erase(m_ProjectileList.begin());
			m_ProjectileVelocities.erase(m_ProjectileVelocities.begin());
		}

		sf::Sprite projectile(ResourceManager::Get().GetTexture(m_ProjectileName));

		Vector2f initialPosition = attacker.GetComponent<C_Sprite>()->GetSprite().getPosition();

		Vector2f travelLocation(static_cast<float>(Cursor::Get().GetPosition().x),static_cast<float>(Cursor::Get().GetPosition().y));

		Vector2f direction = travelLocation - initialPosition;

		float length = direction.Length();

		// Normalize direction
		if (length > 0)
		{
			direction /= length;
		}

		// Set the projectile's position and velocity
		projectile.setPosition(initialPosition);

		// Set the origin to the center of the projectile for better collision
		sf::FloatRect bounds = projectile.getLocalBounds();

		//projectile.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

		m_ProjectileList.emplace_back(projectile);
		m_ProjectileVelocities.emplace_back(direction * 200.0f);

		Debug::Print("Shooting. \n Size: ", m_ProjectileList.size());
		m_CanShoot = false;
	}
}

void C_Shoot::DrawProjectile(Window& window)
{
	for (auto& sprite : m_ProjectileList)
	{
		window.Draw(sprite);
	}
}
