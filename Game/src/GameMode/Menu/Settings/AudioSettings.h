#pragma once
#include "GameMode/Menu/Menu.h"


class AudioSettings : public Menu
{
public:
	AudioSettings(StateMachine& state, Window& window);
	virtual ~AudioSettings() {};
	void Create() override;
	void Destroy() override;
	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) override;
	void Render(Window& window) override;
	void CheckChosenButton(Cursor& cursor);
};