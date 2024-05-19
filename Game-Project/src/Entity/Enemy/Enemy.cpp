#include "Enemy.h"


Enemy::Enemy(Window& window, InputManager& input) : Character(window, input), m_Fire(m_Enemy){}
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
void Enemy::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Burn();

}
void Enemy::Draw(Window& window)
{
    window.Draw(*m_Enemy);
}

void Enemy::Burn()
{	m_Fire.Update(m_DeltaTime);
	m_Fire.AddIntRect({ sf::IntRect(0, 0, 480, 480), 0.01f });
	m_Fire.AddIntRect({ sf::IntRect(480, 0, 480, 480), 0.01f });
	m_Fire.AddIntRect({ sf::IntRect(960, 0, 480, 480), 0.2f });
	m_Fire.AddIntRect({ sf::IntRect(1440, 0, 480, 480), 0.2f });
	m_Fire.AddIntRect({ sf::IntRect(1920, 0, 480, 480), 0.2f });

// 	m_Fire.AddIntRect({ sf::IntRect(0, 960, 480, 480), 0.1f });
// 	m_Fire.AddIntRect({ sf::IntRect(0, 960, 480, 480), 0.1f });
// 	m_Fire.AddIntRect({ sf::IntRect(960, 0, 480, 480), 0.1f });
// 	m_Fire.AddIntRect({ sf::IntRect(1440, 0, 480, 480), 0.1f });
// 	m_Fire.AddIntRect({ sf::IntRect(1920, 0, 480, 480), 0.1f });
// 	m_Fire.AddIntRect({ sf::IntRect(2400, 0, 480, 480), 0.1f });
}

sf::Sprite* Enemy::GetEnemy()
{
    return m_Enemy;
}
