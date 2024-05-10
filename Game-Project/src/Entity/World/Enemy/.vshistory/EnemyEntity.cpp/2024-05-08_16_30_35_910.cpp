#include "EnemyEntity.h"

EnemyEntity::EnemyEntity(Window& m_Window) 
{ 
	m_Player.setTexture(m_FoeText);
	m_Player.setTextureRect(sf::IntRect(0, 0, 80, 80));
	m_Player.setPosition(sf::Vector2f(600, 600));
	m_Player.scale(1, 1);
}

void EnemyEntity::Init()
{}
void EnemyEntity::Update(float deltaTime){}
void EnemyEntity::Draw(Window& window)
{
	//window.Draw(m_Foe);
}

