#include "stdafx.h"
#include "StateManager.h"
#include <cassert>

StateManager::~StateManager()
{
	for (const auto& [id, state] : m_States)
	{
		if(state != nullptr)
		{
			state->OnDestroy();
		}
	}
}

void StateManager::Update(float deltaTime)
{
	Cursor::Get().Update();

	if (m_Current != nullptr)
	{
		m_Current->Update(deltaTime);
	}
}
void StateManager::Draw(Window& window)
{
	if (m_Current != nullptr)
	{
		m_Current->Draw(window);
	}
}
void StateManager::HandleInput(float deltaTime)
{
	InputManager::Get().Update(deltaTime);
	if (m_Current != nullptr)
	{
		m_Current->HandleInput(deltaTime);
	}
}
void StateManager::Add(std::shared_ptr<I_GameState> pushingState, int allocationID)
{
	// Check if the ID is already mapped
	if (m_States.find(allocationID) != m_States.end()) 
	{
		Log::Print("State with this allocation ID already exists!", LogLevel::ERROR_);
		return; 
	}

	// Check if the state is valid
	if (!pushingState) 
	{
		Log::Print("Cannot add a null state!", LogLevel::ERROR_);
		return; // Exit if the state is null
	}

	// If the ID is valid and the state is valid, insert the new state
	auto [it, hadSuccess] = m_States.emplace(allocationID, pushingState);
	if (hadSuccess)
	{
		pushingState->OnInit(); // Initialize the state
	}
}

void StateManager::Switch(int stateID)
{
	auto it = m_States.find(stateID);
	auto& [id, state] = *it;

	if (it != m_States.end())
	{
		if (m_Current != nullptr)
		{
			Log::Print("Changing current state to", stateID);
			m_Current->OnStop();
		}

		m_Current = state;
		m_Current->OnStart();
	}
}

void StateManager::Remove(int stateID)
{
	auto it = m_States.find(stateID);
	auto& [id, state] = *it;

	if (it != m_States.end())
	{
		if (m_Current != nullptr)
		{
			m_Current = nullptr;
		}
		state->OnDestroy();
		m_States.erase(stateID);
	}
}

void StateManager::Validate(int ID)
{
	auto checkID = m_States.find(ID);

}
