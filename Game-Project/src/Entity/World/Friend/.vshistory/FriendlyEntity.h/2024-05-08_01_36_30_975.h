#pragma once
#include "Entity/Entity.h"


class FriendlyEntity : public Entity
{
public:
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	
private:
	void Init() override;
	
public:
	FriendlyEntity(Window& m_Window);
	Characters* m_Obj;
	Entity& m_Entity;
};

