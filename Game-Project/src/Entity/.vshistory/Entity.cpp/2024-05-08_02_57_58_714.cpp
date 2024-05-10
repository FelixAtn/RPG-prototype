#include "Entity.h"


Entity::Entity(Characters* m_Obj): m_Obj(m_Obj)
{
//	m_Character = m_Obj->GetCharacterList();
//	m_Projectile = m_Obj->GetProjectileList();
	InitCharacters();
	
}
Entity::~Entity()
{

}

void Entity::InitCharacters()
{
	World1 = m_Character[0];
	Player = m_Character[1];
	Friend = m_Character[2];
	Enemy = m_Character[3];
	
	m_Globe = m_Projectile[0];
}

