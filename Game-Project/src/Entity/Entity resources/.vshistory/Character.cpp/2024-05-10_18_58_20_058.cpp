#include "Character.h"

Character::Character() : m_Player(m_Player), m_Enemy(m_Enemy),m_IsInit(false)
{
	Init();
}


Character::~Character()
{

}

void Character::Init()
{
	InitPlayer();
}

void Character::Update(float deltaTime)
{

}

void Character::Draw(Window& window)
{
	window.Draw(m_Player);
}

void Character::InitPlayer()
{
	m_IsInit = true;
	if(m_IsInit)
	{
		m_Loader.Load(m_PlayerText, "mobss.png");
		m_Player.setTexture(m_PlayerText);
		m_Player.setPosition(200, 200);
		m_Player.setTextureRect(sf::IntRect(0, 0, 80, 80));
		m_Player.setScale(1, 1);
	}
	
}

void Character::InitEnemy()
{

}

