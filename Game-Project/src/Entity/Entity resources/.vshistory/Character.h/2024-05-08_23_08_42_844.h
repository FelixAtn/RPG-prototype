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

	void InitPlayer();
	sf::Sprite GetPlayer()const;
private:
	void InitEnemy();
	void InitFriend();
	void InitWorld();
	void InitArrow();

private:
	bool isInit;

protected:
	// Walking Entities
	sf::Texture m_PlayerText;
	sf::Texture m_FoeText;

	sf::Sprite m_Player;
	sf::Sprite m_Foe;

	// Projectile Types
	sf::Texture m_GlobeText;
	sf::Sprite m_Globe;

	//Utilities
	Loader m_Loader;
	InitSprites m_Init;
};

