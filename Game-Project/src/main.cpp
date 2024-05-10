#include <iostream>
#include "Game/GameManager.h"


int main()
{
	GameManager game;
	game.Run();
	
	system("exit");
}


// When returning pointers from a func, return the FUNC* instead of DEREFERENCING the pointers before returning.
// when using it, condition it if != nullptr. !=  

