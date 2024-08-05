#pragma once
#include "Input/InputManager.h"


enum class Key
{
	None = 0,
	W = 1,
	A = 2,
	S = 3,
	D = 4,
	E = 5,
	ESC = 6,
};

class Keyboard : public InputManager
{
public:
	virtual ~Keyboard() { std::cout << "\nKEYBOARD DESTROYESD"; };
	void Clear() override;
	void Update() override;

};

