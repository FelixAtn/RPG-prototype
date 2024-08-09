#pragma once
#include "GameMode/Menu/Menu.h"

enum class DisplaySettingType
{
	Back = 0,
	Resolution,
	MaxFPS,
	vSync
};

class DisplaySettings : public Menu
{
public:
	DisplaySettings(StateMachine& state, Window& window);
	virtual ~DisplaySettings() {};
	void Create() final;
	void Destroy() final;
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) final;
	void Render(Window& window) final;
	void CheckChosenButton(Cursor& cursor);

};

