#include "Player.h"

Player::Player(Window& window, InputManager& inputManager) :Character(m_PlayerText),m_Enemy(window, inputManager), m_Input(inputManager), m_Window(window), m_DeltaTime(m_DeltaTime)
{

}

Player::~Player()
{

}

void Player::Init()
{
	isInit = true;
	if (isInit)
	{
		m_Loader.Load(m_PlayerText, "mobss.png");
		m_Player.setTexture(m_PlayerText);
		m_Player.setPosition(100, 100);
		m_Player.setTextureRect(sf::IntRect(0, 0, 80, 80));
		m_Player.setScale(1, 1);
		isInit = false;

		projectiles.setSize(sf::Vector2f(30, 5));
		projectiles.setOutlineColor(sf::Color::Magenta);
		projectiles.setFillColor(sf::Color::Transparent);
		projectiles.setOutlineThickness(2);
		projectiles.setPosition(m_Player.getPosition());
	}
}

void Player::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	Input();
	ValidateMove();
}

void Player::Draw(Window& window)
{
	window.Draw(m_Player);
	window.Draw(projectiles);
}

void Player::Input()
{
	m_Input.Update();
	m_Move.x = 0.f;
	m_Move.y = 0.f;
	m_WalkSpeed = 500;

	m_CurrentPosition = m_Player.getPosition();
	// Control Player X / Y axis 
	if (m_Input.IsKeyPressed(Key::Right))
	{
		m_Move.x = +m_WalkSpeed;
		projectiles.setPosition(m_Player.getPosition());
	}
	else if (m_Input.IsKeyPressed(Key::Left))
	{
		m_Move.x = -m_WalkSpeed;
		projectiles.setPosition(m_Player.getPosition());
	}
	if (m_Input.IsKeyPressed(Key::Down))
	{
		m_Move.y = +m_WalkSpeed;
		projectiles.setPosition(m_Player.getPosition());
	}
	else if (m_Input.IsKeyPressed(Key::Up))
	{
		m_Move.y = -m_WalkSpeed;
		projectiles.setPosition(m_Player.getPosition());
	}


	m_Move *= m_DeltaTime;
	m_NewPosition = m_CurrentPosition + sf::Vector2f(m_Move);
	m_Player.setPosition(m_NewPosition);
	//projectiles.setPosition(m_Player.getPosition());
	m_Input.Clear();

	sf::Vector2f projMove;
	projMove.x = 0;
	projMove.y = 0;

	sf::Vector2f enemyPos = m_Enemy.GetEnemy().getPosition();
	projMove *= m_DeltaTime;
	projMove = enemyPos - projectiles.getPosition();
	sf::Vector2f newProjMove = projectiles.getPosition() + projMove * 0.1f;

	if (m_Input.IsKeyPressed(Key::E))
	{
		projectiles.setPosition(newProjMove);
	}
}

void Player::ValidateMove()
{
	sf::Sprite enemySprite = m_Enemy.GetEnemy();
	if (!m_Check.IsColliding(m_Player, enemySprite) )
	{ 
		m_Player.setPosition(m_NewPosition);
	}
	else
	{
		std::cout << "Collide\n";
		m_Player.setPosition(m_NewPosition - m_Move);
	}
}



