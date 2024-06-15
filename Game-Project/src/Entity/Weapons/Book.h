#pragma once
#include "Entity/Weapons/Ability.h"
#include "Entity/Player/Player.h"
#include "Entity/Enemy/Enemy.h"
#include "Input/InputManager.h"
#include "Physics/VectorNormalizer.h"
#include "vector"
#include <deque>

enum class AbilityNames
{
	projectile = 0,
};

class Book : public Ability
{
public:
	Book(Window& window, InputManager& input);

	void Update(float& deltaTime) override;
	void Draw(Window& window) override;
	void Init() override;
	void Input();

private:

	Window& m_Window;
	InputManager& m_Input;
	CollisionManager m_Check;
	Enemy m_Enemy;
	Player m_Player;
	Normalize m_Unit;

	std::vector<sf::Sprite> m_AbilitySprite;
	sf::Texture m_AbyssalBookText;
	sf::Sprite m_FireBall;

	sf::Vector2f calculateCoord;
	float m_DeltaTime;
	int i;

	sf::Vector2f m_StartingPos;
	sf::Vector2f m_TargetPos;
	sf::Vector2f m_Direction;
};

