#include "Player.h"
#include "iostream"
#include "Resources/GameTools.h"
#include "Physics/VectorMath.h"


Player::Player(const std::string& playerName, const std::string& playerType) : m_Component(GetSprite())
{
	std::cout << "Init: " << playerName << "\n";
	SetName(playerName);
	SetTexture(playerType); 
	SetScale(1, 1);
	SetRect(0, 0, 64, 64);
	SetMovementSpeed(80.f);
	SetPosition(200, 500);
}

Player::~Player() {}

void Player::UpdateInput(Keyboard& keyboardInput, Mouse& mouseInput, float deltaTime)
{

}

void Player::UpdateAnimation(float deltaTime)
{
	
}

void Player::UpdateData(Keyboard& input, float deltaTime)
{
	m_Component.UpdateInput(input, m_Velocity, GetMovementSpeed(), deltaTime);
	m_Component.UpdateAnimation(deltaTime);
}

void Player::Render(Window& window)
{
	window.Render(m_Sprite); 
}




void Player::SetVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}
