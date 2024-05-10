#pragma once
#include <SFML/Graphics.hpp>
#include "Resources/Window/Window.h"

// FSM - FINITE-STATE MACHINE

class GameState
{
public:
	// IMPLEMENT CREATE AND DESTROY AS PURE VIRTUAL FUNCTIONS TO ENSURE THAT THE CLASS IS NOT INSTANTIATED.
	// These two methods will need to be implemented in any class that inherits from GameState
//	_________________________________________________________
	// This will be called when the scene is created. ONCE.
	virtual void OnCreate() = 0; 

	// This will be called when the scene is destroyed
	virtual void OnDestroy() = 0;
//  _________________________________________________________


	// This will be called when a scene is TRANSITIONED INTO  - It can be called many times in a game cycle.
		virtual void OnActivate() {};

	// This will be called when a Trainsition OUT OF SCENE occurs
	virtual void OnDeactivate() {};

	// The below functions can be ovverriden as needed in our scenes.
	virtual void ProcessInput() {};
	virtual void Update(float deltaTime) {};
	virtual void WindowUpdate(float deltaTime) {};
	virtual void Draw(Window& window);

	// To manage the scenes we will write a FINITE-STATE machine (FSM).
};

