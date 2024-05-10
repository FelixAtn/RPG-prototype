#pragma once
#include "Entity/Entity.h"


class EnemyEntity : public Entity
{
public:
	EnemyEntity(Window& m_Window);
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	void Init() override;

private:


};

