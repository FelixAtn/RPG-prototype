#pragma once
#include <memory>
#include "Game/FSM - Learning/GameState.h"
#include "Resources/Window/Window.h"
#include <unordered_map>

// This class is responsible for Maintaining the Game States.
class SceneState
{
public:
	SceneState();

	// ProcessInput / Update / WindowUpdate / Draw will be passed through the following methods.
	// They will call the corresponding methods of the CURRENT active state.

	void ProcessInput();
	void Update(float deltaTime);
	void WindowUpdate(float deltaTime);
	void Draw(Window& window);

	// Adds a state and RETURNS THE ID of that GameState (FSM).
	unsigned int Add(std::shared_ptr<GameState> state);

	// Transition to state with specified ID.
	void SwitchTo(unsigned int ID);

	// Removes state from GameState (FSM)
	void Remove(unsigned int ID);

private:
	// Stores all states associated with the GameState (FSM)
	std::unordered_map<unsigned int, std::shared_ptr<GameState>> states;

	// Stores a reference to the current state. Used when Drawing / Updating.
	std::shared_ptr<GameState> currentState;

	// Stores our current SceneState ID. This is incremented whenever a scene is added.
	unsigned int addedStateID;

};

