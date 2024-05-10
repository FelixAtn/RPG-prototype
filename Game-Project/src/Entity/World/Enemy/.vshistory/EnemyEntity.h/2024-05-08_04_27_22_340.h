#pragma once
#include "Entity/Entity.h"
#include "Entity/Entity resources/Animator.h"

class EnemyEntity : public Characters
{
public:
	EnemyEntity(Window& m_Window);
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	Characters m_Character;
private:
	void Init() override;

private:


};

