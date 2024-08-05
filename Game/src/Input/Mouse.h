#pragma once
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window/Window.h"
#include "InputManager.h"
#include "Input/Mask.h"


enum class MouseKey
{
	None = 0,
	LEFT_CLICK,
	RIGHT_CLICK,
	WHEEL_CLICK,
	FORWARD_CLICK,
	BACK_CLICK
};

class Mouse : public InputManager
{
public:
	virtual ~Mouse() { std::cout << "\nMOUSE DESTROYESD"; };
	void Clear() override;
	void Update() override;
};

