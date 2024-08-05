#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& enemyName, const std::string& type, float xPos, float yPos)
{
	std::cout << "Init: " << enemyName << "\n";
	SetName(enemyName);
	SetTexture(type);
	SetScale(1, 1);
	SetRect(0, 0, 64, 64);
	SetMovementSpeed(100.f);
	SetPosition(xPos, yPos);
}

void Enemy::UpdateData(Keyboard& input , float deltaTime)
{
	m_Hitbox.setPosition(GetSpritePosition());
}
void Enemy::Render(Window& window)
{
	window.Render(m_Sprite);
	window.Render(m_Hitbox);
}
