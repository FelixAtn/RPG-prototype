#pragma once

class CharactersManager
{
public:
	CharactersManager(RenderingSystem& renderingSystem);

	void InitPlayer(const Vector2f& position);
	void HandleInput();
	void Update(float deltaTime);
	void Draw(Window& window);

	template <typename... Args>
	void SpawnHostilesInArea(const Vector2f& topLeft, const Vector2f& areaSize, int count, Args&&... args)
	{
		RandomGenerator randomGen;

		for (int i = 0; i < count; ++i)
		{
			// Generate random positions within area
			float posX = randomGen.GetRandomFloat(topLeft.x, topLeft.x + areaSize.x);
			float posY = randomGen.GetRandomFloat(topLeft.y, topLeft.y + areaSize.y);

			auto newHostile = std::make_unique<Hostile>(std::forward<Args>(args)...);

			// Set the initial position for the hostile
			if (C_Sprite* spriteComponent = newHostile->GetComponent<C_Sprite>())
			{
				spriteComponent->GetSprite().setPosition(sf::Vector2f(posX, posY));
				m_RenderingSystem.Register(spriteComponent);
			}

			m_HostileEntities.emplace_back(std::move(newHostile));
		}
	}

	void RemoveDeadCharacters();

private:
	Player m_Player;
	std::vector<std::unique_ptr<Object>> m_HostileEntities;
	RenderingSystem& m_RenderingSystem;
};

