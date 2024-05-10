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

	void Init() override;
	void Draw(Window& window) override;
	void Update(float deltaTime) override;

private:
	void InitPlayer();
	void InitEnemy();
	void InitFriend();
	void InitWorld();
	void InitArrow();

protected:
	// Walking Entities
	sf::Texture* playerText;
	sf::Texture m_FriendText;
	sf::Texture m_FoeText;
	sf::Texture m_WorldText;
	sf::Texture m_ArrowText;	


	
	// Projectile Types


	//Utilities
	Loader m_Loader;
	InitSprites m_Init;
};

