 #include "AnimationComponent.h"
 #include "Physics/VectorMath.h"

AnimationComponent::AnimationComponent(sf::Sprite& target) 
	: m_Sprite(target)
	, m_PreviousDirection(0.f, 0.f)
{
	Init(target);
	AddAnimations();
}

PlayAnimation AnimationComponent::MapDirection(const sf::Vector2f direction)
{
		if (direction.x == -1 && direction.y == 0)
		{
			return PlayAnimation::WalkLeft;
		}
		else if (direction.x == 1 && direction.y == 0)
		{
			return PlayAnimation::WalkRight;
		}
		else if (direction.x == 0 && direction.y == -1)
		{
			return PlayAnimation::WalkUp;
		}
		else if (direction.x == 0 && direction.y == 1)
		{
			return PlayAnimation::WalkDown;
		}
		else if (direction.x == 0 && direction.y == 0)
		{
			if (m_PreviousDirection.x == -1) return PlayAnimation::IdleLeft;
			if (m_PreviousDirection.x == 1) return PlayAnimation::IdleRight;
			if (m_PreviousDirection.y == -1) return PlayAnimation::IdleUp;
			if (m_PreviousDirection.y == 1) return PlayAnimation::IdleDown;
		}

		return PlayAnimation::none;
}

void AnimationComponent::MovementAnimation(const sf::Vector2f& movementDirection, float deltaTime)
{
	if (movementDirection != sf::Vector2f(0, 0))
	{
		m_PreviousDirection = movementDirection;
	}

	PlayAnimation state = MapDirection(movementDirection);
	m_Animation[state]->Update(deltaTime, true);
}

void AnimationComponent::AttackAnimation(bool isAttacking, float deltaTime)
{
	if (isAttacking && m_PreviousDirection.x == -1 && m_PreviousDirection.y == 0)
	{
		m_AnimationState = PlayAnimation::AttackLeft;
		m_Animation[PlayAnimation::AttackLeft]->Reset();
	}
	else if (isAttacking && m_PreviousDirection.x == 1 && m_PreviousDirection.y == 0)
	{
		m_AnimationState = PlayAnimation::AttackRight;
		m_Animation[PlayAnimation::AttackRight]->Reset();
	}
	else if (isAttacking && m_PreviousDirection.x == 0 && m_PreviousDirection.y == -1)
	{
		m_AnimationState = PlayAnimation::AttackUp;
		m_Animation[PlayAnimation::AttackUp]->Reset();
	}
	else if(isAttacking && m_PreviousDirection.x == 0 && m_PreviousDirection.y == 1)
	{
		m_AnimationState = PlayAnimation::AttackDown;
		m_Animation[PlayAnimation::AttackDown]->Reset();
	}
	switch (m_AnimationState)
	{
	case PlayAnimation::AttackLeft:
		m_Animation[PlayAnimation::AttackLeft]->Update(deltaTime, false);
		if (m_Animation[PlayAnimation::AttackLeft]->IsAnimationComplete())
		{
			m_AnimationState = PlayAnimation::IdleLeft;
		}
		break;

	case PlayAnimation::AttackRight:
		m_Animation[PlayAnimation::AttackRight]->Update(deltaTime, false);
		if (m_Animation[PlayAnimation::AttackRight]->IsAnimationComplete())
		{
			m_AnimationState = PlayAnimation::IdleRight;
		}
		break;

	case PlayAnimation::AttackUp:
		m_Animation[PlayAnimation::AttackUp]->Update(deltaTime, false);
		if (m_Animation[PlayAnimation::AttackUp]->IsAnimationComplete())
		{
			m_AnimationState = PlayAnimation::IdleUp;
		}
		break;

	case PlayAnimation::AttackDown:
		m_Animation[PlayAnimation::AttackDown]->Update(deltaTime, false);
		if(m_Animation[PlayAnimation::AttackDown]->IsAnimationComplete())
		{
			m_AnimationState = PlayAnimation::IdleDown;
		}
		break;
	}
}

void AnimationComponent::Init(sf::Sprite& target)
{
	int totalAnimations = static_cast<int>(PlayAnimation::END);
	m_Animation.reserve(totalAnimations);

	for (int i = 0; i < totalAnimations; i++)
	{
		m_Animation[static_cast<PlayAnimation>(i)] = std::make_shared<AnimationManager>(m_Sprite);
	}
}

void AnimationComponent::AddAnimations()
{
	int width = 64;
	int height = 64;

	m_Animation[PlayAnimation::WalkUp]->AddAnimation(0, 8, 0, width, height, 0.1f);
	m_Animation[PlayAnimation::WalkDown]->AddAnimation(0, 8, 2, width, height, 0.1f);
	m_Animation[PlayAnimation::WalkLeft]->AddAnimation(0, 7, 1, width, height, 0.1f);
	m_Animation[PlayAnimation::WalkRight]->AddAnimation(0, 7, 3, width, height, 0.1f);
						 
	m_Animation[PlayAnimation::IdleUp]->AddAnimation(0, 2, 9, width, height, 1.2f);
	m_Animation[PlayAnimation::IdleLeft]->AddAnimation(2, 4, 9, width, height, 1.2f);
	m_Animation[PlayAnimation::IdleDown]->AddAnimation(4, 6, 9, width, height, 1.2f);
	m_Animation[PlayAnimation::IdleRight]->AddAnimation(6, 8, 9, width, height, 1.2f);
						 
	m_Animation[PlayAnimation::AttackUp]->AddAnimation(0, 5, 5, width, height, 0.1f);
	m_Animation[PlayAnimation::AttackDown]->AddAnimation(0, 5, 7, width, height, 0.1f);
	m_Animation[PlayAnimation::AttackLeft]->AddAnimation(0, 5, 6, width, height, 0.1f);
	m_Animation[PlayAnimation::AttackRight]->AddAnimation(0, 5, 8, width, height, 0.1f);
}
