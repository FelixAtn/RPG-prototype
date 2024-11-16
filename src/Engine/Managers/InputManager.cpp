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
		m_CurrentKey.set(static_cast<int>(KeyBind::W));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::A));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::S));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::D));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::E));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::SHIFT));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::Q));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::R));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::F));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::ESC));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::W_D));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::S_D));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::W_A));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::S_A));
	}
}

void InputManager::UpdateMouse()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::LEFT_CLICK));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::RIGHT_CLICK));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_CurrentKey.set(static_cast<int>(KeyBind::LEFT_CLICK));
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
			m_CurrentKey.set(static_cast<int>(KeyBind::A));
		}
		else if (xAxis > 50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::D));
		}

		if (yAxis < -50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::W));
		}
		else if (yAxis > 50)
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::S));
		}

		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::CROSS)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::E));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::CIRCLE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::SHIFT));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::TRIANGLE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::Q));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::SQUARE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::R));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::RIGHT_STICK)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::F));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::SQUARE)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::R));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::R1)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::LEFT_CLICK));
		}
		if (sf::Joystick::isButtonPressed(joystickID, static_cast<int>(GamepadKey::OPTIONS)))
		{
			m_CurrentKey.set(static_cast<int>(KeyBind::ESC));
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