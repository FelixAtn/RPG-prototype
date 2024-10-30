#include "stdafx.h"
#include "InputManager.h"

void InputManager::Update(float deltaTime)
{
	m_PreviousKey = m_CurrentKey;
	m_CurrentKey.reset();
	UpdateKeyboard();
	UpdateMouse();
	UpdateGamepad();
	m_MouseWheel = 0.0f;
}

void InputManager::ReceiveEvent(const sf::Event event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		m_MouseWheel += event.mouseWheelScroll.delta;
	}
}

void InputManager::UpdateKeyboard()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::UP));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::LEFT));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::DOWN));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::RIGHT));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::INTERACT));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::DODGE));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_ONE));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_TWO));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_THREE));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::PAUSE));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::DIAGONAL_RIGHT_UP));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::DIAGONAL_RIGHT_DOWN));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::DIAGONAL_LEFT_UP));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::DIAGONAL_LEFT_DOWN));
	}

}

void InputManager::UpdateMouse()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::BASIC_ATTACK));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::CHARGE_ATTACK));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::BASIC_ATTACK));
	}

	if (m_MouseWheel > 0)
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::ZOOM_IN));
	}

	if (m_MouseWheel < 0)
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::ZOOM_OUT));
	}
}

void InputManager::UpdateGamepad()
{
	unsigned int joystickID = 0;

	if (sf::Joystick::isConnected(joystickID))
	{
		float xAxis = sf::Joystick::getAxisPosition(joystickID, sf::Joystick::X);
		float yAxis = sf::Joystick::getAxisPosition(joystickID, sf::Joystick::Y);

		if (xAxis < -50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::LEFT));
		}
		else if (xAxis > 50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::RIGHT));
		}

		if (yAxis < -50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::UP));
		}
		else if (yAxis > 50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::DOWN));
		}

		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::CROSS)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::INTERACT));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::CIRCLE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::DODGE));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::TRIANGLE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_ONE));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::SQUARE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_TWO));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::RIGHT_STICK)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_THREE));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::SQUARE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::SPELL_TWO));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::R1)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::BASIC_ATTACK));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::OPTIONS)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::PAUSE));
		}
	}
}

bool InputManager::IsKeyPress(KeyBind key)
{
	auto kb = static_cast<int>(key);
	return m_CurrentKey.test(kb) && !m_PreviousKey.test(kb);
}

bool InputManager::IsKeyDown(KeyBind key)
{
	return m_CurrentKey.test(static_cast<int>(key));
}

bool InputManager::IsKeyUp(KeyBind key)
{
	size_t bind = static_cast<size_t>(key);
	return !m_CurrentKey.test(bind) && m_PreviousKey.test(bind);
}