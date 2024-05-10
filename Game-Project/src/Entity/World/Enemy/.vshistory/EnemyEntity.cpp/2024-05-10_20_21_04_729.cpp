#include "EnemyEntity.h"


Enemy::Enemy(Window& window, InputManager& input) : Character(m_EnemyText)
{
    Init();
}

void Enemy::Init()
{
	m_Loader.Load(m_EnemyText, "zombie.png");
    m_Enemy.setTexture(m_EnemyText);
    m_Enemy.setPosition(600, 600);
    m_Enemy.setTextureRect(sf::IntRect(0, 0, 80, 80));
    m_Enemy.setScale(1, 1);
}

void Enemy::Draw(Window& window)
{
    window.Draw(m_Enemy);
}

void Enemy::Update(float deltaTime)
{

}
