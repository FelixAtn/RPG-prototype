#pragma once
#include "Entity/Character/Character.h"
#include "GameMode/Menu/UI/Button.h"

class Enemy : public Character
{
public:
	Enemy(const std::string& Name, const std::string& type, float xPos, float yPos);
	void Update(Cursor& cursor, Keyboard& input, float deltaTime) override;

	std::string m_HpToString;
	std::vector < std::shared_ptr<Button>> GetButton() const; 

private:
};

