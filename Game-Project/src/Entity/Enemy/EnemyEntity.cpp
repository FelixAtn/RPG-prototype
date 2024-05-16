#include "EnemyEntity.h"


Enemy::Enemy(Window& window, InputManager& input) : Character(window, input){}
Enemy::~Enemy(){}

void Enemy::Init()
{
		if(m_Enemy)
		{
		m_Enemy->setPosition(90, 600);
		m_Enemy->setTextureRect(sf::IntRect(0, 0, 78, 58));
		m_Enemy->setScale(1, 1);
		}
}
void Enemy::Draw(Window& window)
{
    window.Draw(*m_Enemy);
}
void Enemy::Update(float deltaTime)
{
}
sf::Sprite* Enemy::GetEnemy()
{
    return m_Enemy;
}
