#include "FriendlyEntity.h"


FriendlyEntity::FriendlyEntity(Window& m_Window) : Entity(m_Obj), m_Entity(m_Entity) {}

void FriendlyEntity::Init()
{
	
}
void FriendlyEntity::Update(float deltaTime)
{

}
void FriendlyEntity::Draw(Window& window)
{
	window.Draw(*Friend);
}

