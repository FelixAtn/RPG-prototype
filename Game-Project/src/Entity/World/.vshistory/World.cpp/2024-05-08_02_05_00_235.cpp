#include "World.h"

World::World(Window& m_Window) : m_Entity(m_Entity), m_Window(m_Window), Entity(m_Obj){}

void World::Init()
{

}

void World::Update(float deltaTime)
{

}

void World::Draw(Window& window)
{
	window.Draw(*World1);
}
