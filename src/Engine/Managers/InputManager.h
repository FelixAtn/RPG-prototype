#pragma once

constexpr uint32_t MAX_KEYS = 650;

enum class GamepadKey
{
	CROSS = 0,
	CIRCLE,
	SQUARE,
	TRIANGLE,
	L1,
	R1,
	L2,
	R2,
	SHARE,
	OPTIONS,
	PS,
	TOUCHPAD,
	LEFT_STICK,
	RIGHT_STICK
};

enum class KeyBind
{
	W,
	S,
	A,
	D,
	W_D,
	S_D,
	W_A,
	S_A,
	SHIFT,
	LEFT_CLICK, 
	RIGHT_CLICK, 
	Q,
	R,
	F,
	E, 
	USE, // Not used (mouse)
	PICK_UP, // Not used (mouse)
	ZOOM_IN, // Not used (mouse)
	ZOOM_OUT, // Not used (mouse)
	ESC
};

class InputManager
{
public:
	static InputManager& Get()
	{
		static InputManager instance;
		return instance;
	}
	 
	void Update(float deltaTime);
	void ReceiveEvent(const sf::Event event);
	bool NoKeyPress() { return m_CurrentKey.none(); }
	bool IsKeyPress(KeyBind key);
	bool IsKeyDown(KeyBind key);
	bool IsKeyUp(KeyBind key);

private:
	InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	void UpdateKeyboard();
	void UpdateMouse();
	void UpdateGamepad();
	
private:
	std::bitset<MAX_KEYS> m_CurrentKey;
	std::bitset<MAX_KEYS> m_PreviousKey = 0;
	std::bitset<MAX_KEYS> m_ToggleKey;

	float m_MouseWheel = 0.0f;
};
