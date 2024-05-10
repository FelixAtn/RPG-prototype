#include "EnemyEntity.h"

EnemyEntity::EnemyEntity(Window& m_Window) : Entity(m_Obj), m_Entity(m_Entity), m_Obj(m_Obj)
{
	Init();
}


void EnemyEntity::Init(){}
void EnemyEntity::Update(float deltaTime){}
void EnemyEntity::Draw(Window& window)
{
	//window.Draw(m_Foe);
}

