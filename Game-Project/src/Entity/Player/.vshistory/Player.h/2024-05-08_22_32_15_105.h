#pragma once
#include "Input/InputManager.h"
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class PlayerEntity : public Characters
{
public:
	PlayerEntity(Window& window, InputManager& input, Characters& m_Character);
	~PlayerEntity();

	void Init() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

	std::vector<sf::Sprite*> vec;
	sf::Texture* texture;
private:
	void Input();
	void ValidateMove();

private:
	Window& m_Window;
	InputManager& m_Input;
	Characters(m_Player);
	CollisionManager m_Check;

	sf::Vector2f m_CurrentPosition;
	sf::Vector2f m_Move;
	sf::Vector2f m_NewPosition;

	sf::Sprite m_Play;

	float m_WalkSpeed;
	float m_DeltaTime;
};

