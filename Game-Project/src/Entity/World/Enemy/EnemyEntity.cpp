#include "EnemyEntity.h"


Enemy::Enemy(Window& window, InputManager& input) : Character(m_EnemyText)
{
    Init();
}

Enemy::Enemy(){}
Enemy::~Enemy()
{
}

void Enemy::Init()
{
	m_Loader.Load(m_EnemyText, "Fall (78x58).png");
	m_Enemy.setTexture(m_EnemyText);
	m_Enemy.setPosition(600, 600);
	m_Enemy.setTextureRect(sf::IntRect(0, 0, 78, 58));
	m_Enemy.setScale(1, 1);
}

void Enemy::Draw(Window& window)
{
    window.Draw(m_Enemy);
}

void Enemy::Update(float deltaTime){}


sf::Vector2f Enemy::GetEnemyPosition()
{
	const sf::Vector2f* enemyPosition;
	enemyPosition = &m_Enemy.getPosition();
    return *enemyPosition; 
}

sf::Sprite& Enemy::GetEnemy()
{
    return m_Enemy;
}
