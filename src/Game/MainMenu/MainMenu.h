#pragma once

class MenuState : public I_GameState
{
public:
	MenuState(StateManager& stateManager);
	void OnInit() override;
	void OnDestroy() override;
	void OnStart() override;
	void OnStop() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;
	void HandleInput(float deltaTime) override;

private:
	StateManager& m_StateManager;
	AudioManager m_Music;
	Timer m_Timer;
	int time;
	bool startCounting = false;
};
