#include "EnemyEntity.h"


Enemy::Enemy(Window& window, InputManager& input) : Character(m_EnemyText)
{
    Init();
}



Enemy::Enemy()
{

}

void Enemy::Init()
{
	m_Loader.Load(m_EnemyText, "zombie.png");
    m_Enemy.setTexture(m_EnemyText);
    m_Enemy.setPosition(200,200);
    m_Enemy.setTextureRect(sf::IntRect(0, 0, 250, 250));
    m_Enemy.setScale(1, 1);
}

void Enemy::Draw(Window& window)
{
    window.Draw(m_Enemy);
}

void Enemy::Update(float deltaTime)
{

}

sf::Vector2f Enemy::GetEnemyPosition()
{
    return m_Enemy.getPosition();
}

sf::Sprite Enemy::GetEnemy()
{
    return m_Enemy;
}
