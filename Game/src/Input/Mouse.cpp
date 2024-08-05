#include "Mouse.h"


void Mouse::Clear()
{
	m_PreviousFrame.SetMask(m_CurrentFrame);
	m_CurrentFrame.ClearByte();
}

void Mouse::Update()
{
	m_CurrentFrame.UpdateBit(static_cast<int>(MouseKey::LEFT_CLICK)
		,(sf::Mouse::isButtonPressed(sf::Mouse::Left)));

	m_CurrentFrame.UpdateBit(static_cast<int>(MouseKey::WHEEL_CLICK)
		, (sf::Mouse::isButtonPressed(sf::Mouse::Middle)));

	m_CurrentFrame.UpdateBit(static_cast<int>(MouseKey::RIGHT_CLICK)
		, (sf::Mouse::isButtonPressed(sf::Mouse::Right)));

	m_CurrentFrame.UpdateBit(static_cast<int>(MouseKey::FORWARD_CLICK)
		, (sf::Mouse::isButtonPressed(sf::Mouse::XButton1)));

	m_CurrentFrame.UpdateBit(static_cast<int>(MouseKey::BACK_CLICK)
		, (sf::Mouse::isButtonPressed(sf::Mouse::XButton2)));
}

// void Mouse::UpdatePosition(Window& window)
// {
// 	MousePositionOnScreen = sf::Mouse::GetPosition();
// }

