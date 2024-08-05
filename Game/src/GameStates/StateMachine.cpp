#include "StateMachine.h"

StateMachine::StateMachine()
	: m_States(0)
	, m_CurrentState(nullptr)
	, m_InsertStateID(0)
{
	m_States.reserve(10);
}

void StateMachine::Update(Cursor& cursor, Keyboard& keyboard, float deltaTime)
{
	if(m_CurrentState != nullptr)
	{
		m_CurrentState->Update(cursor, keyboard, deltaTime);
	}
}

void StateMachine::Draw(Window& window)
{
	if(m_CurrentState != nullptr)
	{
		m_CurrentState->Draw(window);
	}
}

unsigned int StateMachine::AddState(std::shared_ptr<States> state)
{
	auto insert = m_States.insert(std::make_pair(m_InsertStateID, state));
	m_InsertStateID++;
	insert.first->second->Create();

	return m_InsertStateID - 1;
}

void StateMachine::SwitchState(unsigned int ID)
{
	auto it = m_States.find(ID);
	if(it != m_States.end())
	{
		if (m_CurrentState != nullptr)
		{
			m_CurrentState->Pause();
		}
		m_CurrentState = it->second;
		m_CurrentState->Start();
	}
}

void StateMachine::SwitchStateAndDestroy(unsigned int ID)
{
	auto it = m_States.find(ID);
	if (it != m_States.end())
	{
		if (m_CurrentState != nullptr)
		{
			m_CurrentState->Destroy();
		}
		m_CurrentState = it->second;
		m_CurrentState->Start();
	}
}

void StateMachine::RemoveState(unsigned int ID)
{
	auto it = m_States.find(ID);
	if(it != m_States.end())
	{
		if(m_CurrentState == it->second)
		{
			m_CurrentState = nullptr;
		}
		it->second->Destroy();
	}
	m_States.erase(it);
}


