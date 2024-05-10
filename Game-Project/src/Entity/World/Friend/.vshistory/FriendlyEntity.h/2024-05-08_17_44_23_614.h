#pragma once
#include "Entity/Entity Resources/Character.h"
#include "Entity/Entity.h"

class FriendlyEntity : public Characters
{
public:
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	
private:
	void Init() override;
	
public:
	FriendlyEntity(Window& m_Window, Characters& m_Character);
};

