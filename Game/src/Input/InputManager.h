#pragma once
#include "Input/Mask.h"
#include "iostream"

class InputManager
{
public:
	InputManager() = default;
	virtual ~InputManager() {};

	virtual void Clear() = 0;
	virtual void Update() = 0;

	template <typename DeviceType> bool IsKeyDown(DeviceType keyCode);
	template <typename DeviceType> bool IsKeyPressed(DeviceType keyCode);
	template <typename DeviceType> bool IsKeyReleased(DeviceType keyCode);

protected:
	BitMask m_CurrentFrame;
	BitMask m_PreviousFrame; 
	BitMask m_Clear; 
};

template <typename DeviceType>
bool InputManager::IsKeyDown(DeviceType keyCode)
{
	return m_CurrentFrame.HasBit(static_cast<int>(keyCode));
}

template <typename DeviceType>
bool InputManager::IsKeyPressed(DeviceType keyCode)
{
	bool lastFrame = m_PreviousFrame.HasBit(static_cast<int>(keyCode));
	bool thisFrame = m_CurrentFrame.HasBit(static_cast<int>(keyCode));
	return thisFrame && !lastFrame;
}

template <typename DeviceType>
bool InputManager::IsKeyReleased(DeviceType keyCode)
{
	bool lastFrame = m_PreviousFrame.HasBit(static_cast<int>(keyCode));
	bool thisFrame = m_CurrentFrame.HasBit(static_cast<int>(keyCode));
	return !thisFrame && lastFrame;
}

