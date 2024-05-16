#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Input\BitArithmetics.h"

enum class Key
{
	None = 0,
	Left = 1,
	Right = 2,
	Up = 3,
	Down = 4,
	E = 5,
	Click = 7,
};

class InputManager
{
public:
	void Clear();
	void Update(); // Method responsible for polling the Keys


private:
	BitArithmetics thisFrameKeys; // to store this frame
	BitArithmetics lastFrameKeys; // to store last frame
	BitArithmetics clear; 

public:
	bool IsKeyPressed(Key keycode);
	bool IsKeyDown(Key keycode);
	bool IsKeyUp(Key keycode);
};

