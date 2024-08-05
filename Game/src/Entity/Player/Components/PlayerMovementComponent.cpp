 #include "PlayerMovementComponent.h"
 #include "Physics/VectorMath.h"

PlayerMovementComponent::PlayerMovementComponent(sf::Sprite& target) 
	: m_Sprite(target)
{
	InitStateVector(target);
	AddAnimations();
}

void PlayerMovementComponent::UpdateInput(Keyboard& input, sf::Vector2f& velocity, float movementSpeed, float deltaTime)
{
		input.Update();
		sf::Vector2f movementDirection(0.f, 0.f);
		sf::Vector2f m_PlayerPosition = m_Sprite.getPosition();
		
		if (input.IsKeyDown(Key::W))
		{
			movementDirection.y -= 1.f;
			m_AnimationState = AnimationState::WalkUp;
		}
		else if(input.IsKeyReleased(Key::W))
		{
			m_AnimationState = AnimationState::IdleUp;
		}

		if (input.IsKeyDown(Key::S))
		{
			movementDirection.y += 1.f;
			m_AnimationState = AnimationState::WalkDown;
		}
		else if(input.IsKeyReleased(Key::S))
		{
			m_AnimationState = AnimationState::IdleDown;
		}

		if (input.IsKeyDown(Key::D))
		{
			movementDirection.x += 1.f;
			m_AnimationState = AnimationState::WalkRight;
		}
		else if(input.IsKeyReleased(Key::D))
		{
			m_AnimationState = AnimationState::IdleRight;
		}

		if (input.IsKeyDown(Key::A))
		{
			movementDirection.x -= 1.f;
			m_AnimationState = AnimationState::WalkLeft;
		}
		else if(input.IsKeyReleased(Key::A))
		{
			m_AnimationState = AnimationState::IdleLeft;
		}

		// ####################### LOGIC TO BE SEPARATED #######################

//  		if (input.IsKeyPressed(Key::LeftClick))
// 		{
// 			m_AnimationState = AnimationState::AttackLeft;
// 			m_AnimationStates[AnimationType::AttackLeft].Reset();
// 		}

		// #####################################################################

		if (movementDirection.x == 0.f && movementDirection.y == 0.f)
		{
			return;
		}

		movementDirection = VectorMath::Math::GetNormalizedVector(movementDirection);
		m_PlayerPosition += movementDirection * movementSpeed * deltaTime;
		sf::Vector2f position = m_PlayerPosition + velocity;

		m_Sprite.setPosition(position);
		velocity = { 0,0 };
}

void PlayerMovementComponent::UpdateAnimation(float deltaTime)
{
	switch (m_AnimationState)
	{
	case AnimationState::WalkUp:
		m_AnimationStates[AnimationType::WalkUp].Update(deltaTime, true);
		break;

	case AnimationState::WalkDown:
		m_AnimationStates[AnimationType::WalkDown].Update(deltaTime, true);
		break;

	case AnimationState::WalkLeft:
		m_AnimationStates[AnimationType::WalkLeft].Update(deltaTime, true);
		break;

	case AnimationState::WalkRight:
		m_AnimationStates[AnimationType::WalkRight].Update(deltaTime, true);
	break;

	case AnimationState::IdleUp:
		m_AnimationStates[AnimationType::IdleUp].Update(deltaTime, true);
		break;

	case AnimationState::IdleDown: 
		m_AnimationStates[AnimationType::IdleDown].Update(deltaTime, true);
		break;

	case AnimationState::IdleLeft:
		m_AnimationStates[AnimationType::IdleLeft].Update(deltaTime, true);
		break;

	case AnimationState::IdleRight: 
		m_AnimationStates[AnimationType::IdleRight].Update(deltaTime, true);
		break;

	case AnimationState::AttackLeft:
		m_AnimationStates[AnimationType::AttackLeft].Update(deltaTime, false);
		if (m_AnimationStates[AnimationType::AttackLeft].IsAnimationComplete())
		{
			m_AnimationState = AnimationState::IdleLeft;
		}
		break;

	case AnimationState::none:
	default:
		return;
	}
}

void PlayerMovementComponent::InitStateVector(sf::Sprite& target)
{
	m_AnimationStates.reserve(20);
	for (int i = 0; i < 12; i++)
	{
		m_AnimationStates.emplace_back(AnimationManager(target));
	}
}
void PlayerMovementComponent::AddAnimations()
{
	int width = 64;
	int height = 64;

	m_AnimationStates[AnimationType::WalkUp].AddAnimation(0, 8, 0, width, height, 0.1f);
	m_AnimationStates[AnimationType::WalkDown].AddAnimation(0, 8, 2, width, height, 0.1f);
	m_AnimationStates[AnimationType::WalkLeft].AddAnimation(0, 7, 1, width, height, 0.1f);
	m_AnimationStates[AnimationType::WalkRight].AddAnimation(0, 7, 3, width, height, 0.1f);

	m_AnimationStates[AnimationType::IdleUp].AddAnimation(0, 2, 9, width, height, 1.2f);
	m_AnimationStates[AnimationType::IdleLeft].AddAnimation(2, 4, 9, width, height, 1.2f);
	m_AnimationStates[AnimationType::IdleDown].AddAnimation(4, 6, 9, width, height, 1.2f);
	m_AnimationStates[AnimationType::IdleRight].AddAnimation(6, 8, 9, width, height, 1.2f);

	m_AnimationStates[AnimationType::AttackUp].AddAnimation(0, 5, 5, width, height, 0.1f);
	m_AnimationStates[AnimationType::AttackDown].AddAnimation(0, 5, 7, width, height, 0.1f);
	m_AnimationStates[AnimationType::AttackLeft].AddAnimation(0, 5, 6, width, height, 0.1f);
	m_AnimationStates[AnimationType::AttackRight].AddAnimation(0, 5, 8, width, height, 0.1f);

}
