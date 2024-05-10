#include "Character.h"

Characters::Characters() : m_Player(m_Player), m_Friend(m_Friend), m_Foe(m_Foe), m_World(m_World), m_Globe(m_Globe), playerText(playerText)
{
	playerText->loadFromFile(nullptr);
}



Characters::~Characters()
{}

void Characters::Init()
{
	InitPlayer();
	InitFriend();
	InitArrow();
	InitEnemy();
	InitWorld();
	//std::cout << "another:" << &m_Player;
}
void Characters::Draw(Window& window)
{
	
	//window.Draw()
}
void Characters::Update(float deltaTime)
{

}
void Characters::InitPlayer()
{
// 
// 	m_Loader.Load(m_PlayerText, "Idle-64X128.png");
// 	m_Init.SetSpriteTexture(m_PlayerText, m_Player);
// 	m_Init.SetSpriteRect(m_Player, 0, 0, 64, 128);
// 	m_Init.SetSpriteDefaultPosition(m_Player, 200, 200);
// 	m_Init.SetSpriteScale(m_Player, 2, 2);
// 	std::cout << "One Player One:" << &m_Player;
	
} 
void Characters::InitEnemy()
{
// 	m_Loader.Load(m_FoeText, "Idle-Pig(34x28).png");
// 	m_Init.SetSpriteTexture(m_FoeText, m_Foe);
// 	m_Init.SetSpriteRect(m_Foe, 0, 0, 34, 28);
// 	m_Init.SetSpriteDefaultPosition(m_Foe, 400, 300);
// 	m_Init.SetSpriteScale(m_Foe, 3, 3);
}
void Characters::InitFriend()
{
// 	m_Loader.Load(m_FriendText, "mobss.png");
// 	m_Init.SetSpriteTexture(m_FriendText, m_Friend);
// 	m_Init.SetSpriteRect(m_Friend, 0, 0, 60,74);
// 	m_Init.SetSpriteDefaultPosition(m_Friend, 555, 555);
// 	m_Init.SetSpriteScale(m_Friend, 1, 1);
}
void Characters::InitWorld()
{
// 	m_Loader.Load(m_WorldText, "/pig/Opening (46x56).png");
// 	m_Init.SetSpriteTexture(m_WorldText, m_World);
// 	m_Init.SetSpriteRect(m_World, 0, 0, 60, 60);
// 	m_Init.SetSpriteDefaultPosition(m_World, 800, 600);
// 	m_Init.SetSpriteScale(m_World, 1, 1);
// 	m_World.setRotation(25.f);
}
void Characters::InitArrow()
{
// 	m_Loader.Load(m_ArrowText, "mobss.png");
// 	m_Init.SetSpriteTexture(m_ArrowText, m_Globe);
// 	m_Init.SetSpriteRect(m_Globe, 80, 880, 60, 80);
// 	m_Init.SetSpriteDefaultPosition(m_Globe, 800, 600);
// 	m_Init.SetSpriteScale(m_Globe, 1, 1);
}


// sf::Sprite Characters::GetPlayer()const
// {
// 	return m_Player;
// }
// sf::Sprite Characters::GetEnemy()const
// {
// 	return m_Foe;
// }
// sf::Sprite Characters::GetFriend()const
// {
// 	return m_Friend;
// }
// sf::Sprite Characters::GetWorld() const
// {
// 	return m_World;
// }

