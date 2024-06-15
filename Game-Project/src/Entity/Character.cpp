#include "Character.h"

Character::Character(Window& window, InputManager& input) : m_Window(window), m_Input(input), m_SpriteManager(SpriteManager::getInstance()) {Init();}
Character::~Character(){}

void Character::Init()
{
	m_Player = m_SpriteManager.GetSprite(0);
	m_Enemy = m_SpriteManager.GetSprite(1);

	m_Tiles = m_SpriteManager.GetTiles(0);
	m_Blocks = m_SpriteManager.GetTiles(1);

	m_TileTest.push_back(m_Tiles);
	m_TileTest.push_back(m_Blocks);
}



