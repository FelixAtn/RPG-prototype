#include "SpriteAnimation.h"

// Player
PlayerAnimation::PlayerAnimation(sf::Sprite* sprite) 
: m_Idle(sprite), m_Attack(sprite), m_Left(sprite), m_Right(sprite), m_Up(sprite), m_Down(sprite){}
PlayerAnimation::~PlayerAnimation() {}
void PlayerAnimation::Idle(float deltaTime)
{
	m_Idle.Update(deltaTime);

	int left = -64;
	int top = 704;
	int width = 64;
	int height = 64;

	for (int i = 0; i < 6; i++)
	{
		left += 64;
		m_Idle.AddIntRect({ sf::IntRect(left, top, width, height), 2.f });
	}
}
void PlayerAnimation::Attack(float deltaTime)
{
	m_Attack.Update(deltaTime);

	int left = -64;
	int top = 512;
	int width = 64;
	int height = 64;

	for (int i = 0; i < 4; i++)
	{
		left += 64;
		m_Attack.AddIntRect({ sf::IntRect(left, top, width, height), 0.07f });
	}
}
void PlayerAnimation::WalkLeft(float deltaTime)
{
	m_Left.Update(deltaTime);
	int left = -64;
	int top = 64;
	int x = 64;
	int y = 64;

	for (int i = 0; i < 8; i++)
	{
		left += 64;
		m_Left.AddIntRect({ sf::IntRect(left, top, x, y), 0.07f });
	}
}
void PlayerAnimation::WalkRight(float deltaTime)
{
	m_Right.Update(deltaTime);
	int left = -64;
	int top = 196;
	int x = 64;
	int y = 64;

	for (int i = 0; i < 8; i++)
	{
		left += 64;
		m_Right.AddIntRect({ sf::IntRect(left, top, x, y), 0.07f });
	}
}
void PlayerAnimation::WalkDown(float deltaTime)
{
	m_Down.Update(deltaTime);
	int left = -64;
	int top = 128;
	int x = 64;
	int y = 64;

	for (int i = 0; i < 8; i++)
	{
		left += 64;
		m_Down.AddIntRect({ sf::IntRect(left, top, x, y), 0.07f });
	}
}
void PlayerAnimation::WalkUp(float deltaTime)
{
	m_Up.Update(deltaTime);
	int left = -64;
	int top = 0;
	int x = 64;
	int y = 64;

	for (int i = 0; i < 8; i++)
	{
		left += 64;
		m_Up.AddIntRect({ sf::IntRect(left, top, x , y), 0.05f });
	}
}


// Enemy
EnemyAnimation::EnemyAnimation(sf::Sprite* sprite) : m_Idle(sprite)
{

}
EnemyAnimation::~EnemyAnimation()
{

}
void EnemyAnimation::Idle(float deltaTime)
{
	m_Idle.Update(deltaTime);

	int left = -64;
	int top = 128;
	int width = 64;
	int height = 64;

	for (int i = 0; i < 6; i++)
	{
		left += 64;
		m_Idle.AddIntRect({ sf::IntRect(left, top, width, height), 0.5f });
	}
}



// NPC



// Environment / WOrld