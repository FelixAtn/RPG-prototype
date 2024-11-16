#include "stdafx.h"
#include "LevelEditor.h"

void LevelEditor::OnInit()
{
	const Vector2f gridSize = Vector2f(1280, 720);
	const Vector2f squareSize = Vector2f(32, 32);

	m_World.Init(gridSize, squareSize);
}

void LevelEditor::OnDestroy()
{

}

void LevelEditor::OnStart()
{

}

void LevelEditor::OnStop()
{

}

void LevelEditor::Update(float deltaTime)
{
	m_World.Update(deltaTime);

	if (InputManager::Get().IsKeyPress(KeyBind::ESC))
	{
		m_StateManager.Switch(GameStateID::MAIN_MENU_STATE_ID);
	}
}

void LevelEditor::Draw(Window& window)
{
	m_World.Draw(window);
}
