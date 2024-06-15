#include "Enemy.h"


Enemy::Enemy(Window& window, InputManager& input) : Character(window, input), m_Idle(m_Enemy){}
Enemy::~Enemy(){}

void Enemy::Init()
{
	if (m_Enemy)
	{
		m_Enemy->setPosition(600, 300);
		m_Enemy->setTextureRect(sf::IntRect(0, 0, 64, 64));
		m_Enemy->setScale(1, 1);
	}
}

void Enemy::Update(float deltaTime)
{
	m_Idle.Idle(deltaTime);
}
void Enemy::Draw(Window& window)
{
	if (m_Enemy)
	{
		window.Draw(*m_Enemy);
	}
}


