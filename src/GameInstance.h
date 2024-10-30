#pragma once

class GameInstance
{
public:
	GameInstance();
	~GameInstance() = default;

	void Init();
	void Run();

private:
	void HandleInput();
	void Update();
	void Draw();

private:
	Window m_Window;
	StateManager m_StateManager;
	Timer m_Timer;
	Vector2f m_Speed;
	sf::Clock m_Clock;
	float m_deltaTime;



	//############## TO use/move later####################
	Camera m_Camera;                //##
	Minimap m_Minimap;              //##     
	//##################################             
};


