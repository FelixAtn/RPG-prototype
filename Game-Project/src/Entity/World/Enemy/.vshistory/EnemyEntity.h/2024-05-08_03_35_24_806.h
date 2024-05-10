#pragma once
#include "Entity/Entity.h"


class EnemyEntity : public Characters
{
public:
	EnemyEntity(Window& m_Window);
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

private:
	void Init() override;

private:


};

