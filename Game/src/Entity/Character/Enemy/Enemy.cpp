#include "Enemy.h"
#include <iostream>
#include "GameMode/Menu/UI/Button.h"

Enemy::Enemy(const std::string& enemyName, const std::string& type, float xPos, float yPos)
{
	std::cout << "Init: " << enemyName << "\n";
	SetName(enemyName);
	SetTexture(type);
	SetRect(0, 0, 64, 64);
	SetPosition(xPos, yPos);
	SetOrigin(GetSpriteCenter().x, GetSpriteCenter().y);
	GetHealthComponent().SetHealth(100);
}

void Enemy::Update(Cursor& cursor, Keyboard& input, float deltaTime)
{
	SecondUpdate();
}


