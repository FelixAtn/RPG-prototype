#pragma once

constexpr int MAIN_MENU_STATE_ID = 0;
constexpr int PLAY_STATE_ID = 1;

class I_GameState
{
public:
	virtual ~I_GameState() = default;
	virtual void OnInit() = 0;
	virtual void OnDestroy() = 0;
	virtual void OnStart() = 0;
	virtual void OnStop() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(Window& window) = 0;
	virtual void HandleInput(float deltaTime = 0) {};
};

class StateManager
{
public:
	~StateManager();
	void Update(float deltaTime);
	void Draw(Window& window);
	void HandleInput(float deltaTime);
	void Add(std::shared_ptr<I_GameState> pushingState, int allocationID);
	void Switch(int stateID);
	void Remove(int stateID);

	void PrintStates() const {
		for (const auto& [id, state] : m_States) {
			Log::Print("State ID: " + std::to_string(id), LogLevel::INFO);
		}
	}
private:
	// Assert that the allocation ID does not already exist
	void Validate(int ID);

private:
	std::unordered_map<int, std::shared_ptr<I_GameState>> m_States;
	std::shared_ptr<I_GameState> m_Current;
	int m_CurrentID;
};

