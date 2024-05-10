#include "SceneState.h"

SceneState::SceneState() : states(0), currentState(0) {}

void SceneState::ProcessInput()
{
	if (currentState)
	{
		currentState->ProcessInput();
	}
}

void SceneState::Update(float deltaTime)
{
	if (currentState)
	{
		currentState->Update(deltaTime);
	}
}

void SceneState::WindowUpdate(float deltaTime)
{
	if (currentState)
	{
		currentState->WindowUpdate(deltaTime);
	}
}

void SceneState::Draw(Window& window)
{
	if (currentState)
	{
		currentState->Draw(window);
	}
	std::unique_ptr<GameState> h ;

}


unsigned int SceneState::Add(std::shared_ptr<GameState> state)
{
	auto inserted = states.insert(std::make_pair(addedStateID, state));
	addedStateID++;
	inserted.first->second->OnCreate();
	
	return addedStateID - 1;
}

void SceneState::Remove(unsigned int ID)
{
	auto it = states.find(ID);

	if (it != states.end())
	{
		// if the current scene is removes, it will be set to nullptr so the state will no longer be updated.
		if (currentState == it->second)
		{
		currentState = nullptr;
		}
	}

	// We make sure to call the OnDestroy of the state Removed.
	it->second->OnDestroy();

	states.erase(it);
}

void SceneState::SwitchTo(unsigned int id)
{
	auto it = states.find(id);
	if (it != states.end())
	{
		if (currentState)
		{
			// If we have a current scene, we call its OnDeactivate method.
			currentState->OnDeactivate();
		}

		// Setting the current scene ensures that it is updated and drawn.
		currentState = it->second;

		currentState->OnActivate();
	}
}