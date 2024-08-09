#pragma once
#include "SFML/Window.hpp"
#include "Input/Cursor.h"
#include "Input/Keyboard.h"
#include <memory>
#include <unordered_map>

class States
{
public:
	virtual void Create() = 0;
	virtual void Destroy() = 0;
	virtual void Start() {};
	virtual void Pause() {};
	virtual void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime) {};
	virtual void Render(Window& window) {};
};

class StateMachine
{
public:
	StateMachine();

	void Update(Cursor& cursor, Keyboard& keyboard, float deltaTime);
	void Draw(Window& window);

	unsigned int AddState(std::shared_ptr<States> state);
	void SwitchState(unsigned int ID);
	void SwitchStateAndDestroy(unsigned int ID);
	void RemoveState(unsigned int ID);

private:
	std::unordered_map<unsigned int, std::shared_ptr<States>> m_States;
	std::shared_ptr<States> m_CurrentState;
	unsigned int m_InsertStateID;
};





