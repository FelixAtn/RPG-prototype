#include "Player.h"
#include <math.h>


//************************************
// Method:    m_Animation
// FullName:  Player::m_Animation
// Access:    private 
// Returns:   
// Qualifier: : Character(window, inputManager), m_Animation(m_Player) m_Timer(0), m_DrawPerFrame(0.07f), m_Idle(0), m_IdleTop(0)
// Parameter: Window & window
// Parameter: InputManager & inputManager
//************************************
Player::Player(Window& window, InputManager& inputManager) : Character(window, inputManager),
m_Timer(0), m_DrawPerFrame(0.07f), m_Idle(m_Player), m_Attack(m_Player), m_Left(m_Player), 
m_Right(m_Player), m_Up(m_Player), m_Down(m_Player)
{
}

Player::~Player(){}


void Player::Init()
{
	Load();
}
void Player::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}
void Player::Draw(Window& window)
{
	if(m_Player)
	{
	window.Draw(*m_Player);
	}
}
void Player::Input()
{
	AnimateIdle();
	sf::Vector2f move(0.f, 0.f);
	sf::Vector2f currentPosition = m_Player->getPosition();
	
	m_WalkSpeed = 500;
	if (m_Input.IsKeyPressed(Key::Right))
	{
		AnimateRight();
		move.x = +m_WalkSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Left))
	{
		AnimateLeft();
		move.x = -m_WalkSpeed;
	}
	if (m_Input.IsKeyPressed(Key::Down))
	{
		AnimateDown();
		move.y = +m_WalkSpeed;
	}
	else if (m_Input.IsKeyPressed(Key::Up))
	{
		AnimateUp();
		move.y = -m_WalkSpeed;
	}
	if (m_Input.IsKeyPressed(Key::Click))
	{
		AnimateAttack();
	}
	if(m_Input.IsKeyPressed(Key::E))
	{
		AnimateDown();
	}
	move *= m_DeltaTime;
	m_NewPosition = currentPosition + move;
}
void Player::ValidateMove()
{
	if (!m_Check.IsColliding(*m_Player, *m_Enemy))
	{ 
		m_Player->setPosition(m_NewPosition);
	}
	else
	{
		m_Player->setPosition(m_NewPosition);
	}
}
void Player::Load()
{
	if (m_Player)
	{
		m_Player->setPosition(700, 700);
		m_Player->setTextureRect(sf::IntRect(0, 0, 512, 512));
		m_Player->scale(3, 3);
	}
}


void Player::AnimateIdle()
{
	m_Idle.Update(m_DeltaTime);
	m_Idle.AddIntRect({ sf::IntRect(0, 0, 192, 192), 0.1f });
	m_Idle.AddIntRect({ sf::IntRect(192, 0, 192, 192), 0.07f });
	m_Idle.AddIntRect({ sf::IntRect(384, 0, 192, 192), 0.07f });
	m_Idle.AddIntRect({ sf::IntRect(576, 0, 192, 192), 0.07f });
	m_Idle.AddIntRect({ sf::IntRect(768, 0, 192, 192), 0.07f });
	m_Idle.AddIntRect({ sf::IntRect(960, 0, 192, 192), 0.2f });
}
void Player::AnimateAttack()
{
	m_Attack.Update(m_DeltaTime);
	m_Attack.AddIntRect({ sf::IntRect(0, 576, 192, 192), 0.1f });
	m_Attack.AddIntRect({ sf::IntRect(192, 576, 192, 192), 0.07f });
	m_Attack.AddIntRect({ sf::IntRect(384, 576, 192, 192), 0.07f });
	m_Attack.AddIntRect({ sf::IntRect(576, 576, 192, 192), 0.07f });
	m_Attack.AddIntRect({ sf::IntRect(768, 576, 192, 192), 0.07f });
	m_Attack.AddIntRect({ sf::IntRect(960, 576, 192, 192), 0.2f });
}
void Player::AnimateRight()
{
	m_Right.Update(m_DeltaTime);
	m_Right.AddIntRect({ sf::IntRect(192, 192, 192, 192), 0.07f });
	m_Right.AddIntRect({ sf::IntRect(384, 192, 192, 192), 0.07f });
	m_Right.AddIntRect({ sf::IntRect(576, 192, 192, 192), 0.07f });
	m_Right.AddIntRect({ sf::IntRect(768, 192, 192, 192), 0.07f });
	m_Right.AddIntRect({ sf::IntRect(960, 192, 192, 192), 0.2f });
}
void Player::AnimateLeft()
{
	m_Left.Update(m_DeltaTime);
	m_Left.AddIntRect({ sf::IntRect(1152, 192, 192, 192), 0.07f });
	m_Left.AddIntRect({ sf::IntRect(1334, 192, 192, 192), 0.07f });
	m_Left.AddIntRect({ sf::IntRect(1536, 192, 192, 192), 0.07f });
	m_Left.AddIntRect({ sf::IntRect(1728, 192, 192, 192), 0.07f });
	m_Left.AddIntRect({ sf::IntRect(1920, 192, 192, 192), 0.2f });
}
void Player::AnimateUp()
{
	m_Up.Update(m_DeltaTime);
	m_Up.AddIntRect({ sf::IntRect(0, 1152, 192, 192), 0.1f });
	m_Up.AddIntRect({ sf::IntRect(192, 1152, 192, 192), 0.1f });
	m_Up.AddIntRect({ sf::IntRect(384, 1152, 192, 192), 0.1f });
}
void Player::AnimateDown()
{
	m_Down.Update(m_DeltaTime);
	m_Down.AddIntRect({ sf::IntRect(0, 576, 192, 192), 0.07f });
	m_Down.AddIntRect({ sf::IntRect(192, 576, 192, 192), 0.07f });
	m_Down.AddIntRect({ sf::IntRect(384, 576, 192, 192), 0.07f });
// 	m_Down.AddIntRect({ sf::IntRect(1728, 0, 192, 192), 0.07f });
// 	m_Down.AddIntRect({ sf::IntRect(1920, 0, 192, 192), 0.2f });;
}
sf::Sprite* Player::GetPlayer()
{
	return m_Player;
}


