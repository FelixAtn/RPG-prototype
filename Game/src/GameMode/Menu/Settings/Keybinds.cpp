#include "Keybinds.h"

Keybinds::Keybinds(StateMachine& state, Window& window) : Menu(state, window)
{

}

Keybinds::~Keybinds()
{

}

void Keybinds::Create()
{
	// ### TODO: 
	// 1. Init BUTTON OBJECTS
	// 2. Init Functionality
}

void Keybinds::Destroy()
{

}

void Keybinds::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	// ### TODO: 
	// To update the Keybind menu options, eg: Everytime a keybind is changed( W TO L ) -> Update both visually and functionally accordingly.
}

void Keybinds::Draw(Window& window)
{

}

void Keybinds::CheckChosenButton(Cursor& cursor)
{

}
