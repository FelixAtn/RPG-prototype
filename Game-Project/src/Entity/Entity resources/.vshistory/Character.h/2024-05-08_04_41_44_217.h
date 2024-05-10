#pragma once
#include "Entity/Entity.h"
#include "Resources/Loader.h"
#include "Resources/InitSprites.h"
#include <vector>

class Characters : public Entity
{
public:
	Characters();
	~Characters();
	sf::Texture m_PlayerText;
	sf::Sprite m_Player;
	void Init() override;
	void Draw(Window& window) override;
	void Update(float deltaTime) override;

	void InitPlayer();
	void InitEnemy();
	void InitFriend();
	void InitWorld();
	void InitArrow();

protected:
	// Walking Entities
	sf::Texture m_FriendText;

	sf::Texture m_FoeText;
	sf::Texture m_WorldText;


	sf::Sprite m_Friend;
	sf::Sprite m_Foe;
	sf::Sprite m_World;
	sf::Sprite m_Globe;

	// Projectile Types
	sf::Texture m_ArrowText;

	//Utilities
	Loader m_Loader;
	InitSprites m_Init;
};

