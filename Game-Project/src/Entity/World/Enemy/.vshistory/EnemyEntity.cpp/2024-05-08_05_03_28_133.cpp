#include "EnemyEntity.h"

EnemyEntity::EnemyEntity(Window& m_Window) : m_Character(m_Character) {  }

void EnemyEntity::Init()
{
	m_Loader.Load(m_FoeText, "Idle-Pig(34x28).png");
	m_Init.SetSpriteTexture(&m_FoeText, &m_Foe);
	m_Init.SetSpriteRect(m_Foe, 0, 0, 34, 28);
	m_Init.SetSpriteDefaultPosition(m_Foe, 400, 300);
	m_Init.SetSpriteScale(m_Foe, 3, 3);
}
void EnemyEntity::Update(float deltaTime){}
void EnemyEntity::Draw(Window& window)
{
	window.Draw(m_Foe);
}

