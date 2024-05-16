#include "Character.h"

Character::Character(Window& window, InputManager& input) : m_Window(window), m_Input(input), m_SpriteManager(SpriteManager::getInstance()) {Init();}
Character::~Character(){}

void Character::Init()
{
	m_Player = m_SpriteManager.GetSprite(0);
	m_Enemy = m_SpriteManager.GetSprite(1);
}
sf::Sprite* Character::GetEnemy()
{
	return m_Enemy;
}
void Character::Update(float deltaTime){}
void Character::Draw(Window& window){}

