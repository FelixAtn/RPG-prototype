#pragma once
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class EnemyEntity : public Characters
{
public:
	EnemyEntity(Window& m_Window, Characters& m_Character);
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	Characters& m_Character;
	std::vector<sf::Sprite*> vecs;
	sf::Texture* texture;
private:
	void Init() override;

private:


};

