#include "InputManager.h"
#include <iostream>

// # Pressed (1 time)
// # Down (between Pressed-Released)
// # Released (1 time)
// # Return true if key is pressed - A key:  1 << Position A.
// 
// bool InputManager::IsKeyDown(Key keycode)
// {
// 	return m_CurrentFrame.HasBit(static_cast<int>(keycode));
// }
// 
// bool InputManager::IsKeyPressed(Key keycode)
// {
// 	bool lastFrame = m_PreviousFrame.HasBit(static_cast<int>(keycode));
// 	bool thisFrame = m_CurrentFrame.HasBit(static_cast<int>(keycode));
// 	return thisFrame && !lastFrame;
// }
// 
// bool InputManager::IsKeyReleased(Key keycode)
// {
// 	bool lastFrame = m_PreviousFrame.HasBit(static_cast<int>(keycode));
// 	bool thisFrame = m_CurrentFrame.HasBit(static_cast<int>(keycode));
// 	return !thisFrame && lastFrame;
// }


