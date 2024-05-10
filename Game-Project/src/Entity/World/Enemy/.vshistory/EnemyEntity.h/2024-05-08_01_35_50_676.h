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
	Characters* m_Obj;
	Entity& m_Entity;
	//sf::Sprite m_Player = m_Obj.GetPlayer();
	//sf::Sprite m_Foe = m_Obj.GetEnemy();
	//sf::Sprite m_Friend = m_Obj.GetFriend();
};

