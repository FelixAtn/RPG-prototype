#include "Animator.h"
#include "Input\BitArithmetics.h"

Animation::Animation(sf::Sprite* sprite) : m_Sprite(*sprite)
{
	m_IntRectLenght = m_Timer;
}
Animation::~Animation(){}

void Animation::Update(float deltaTime)
{
	m_Timer += deltaTime;
	float time = m_Timer;
	for(size_t i = 0; i < m_AnimationRect.size(); i++)
	{
		time -= m_AnimationRect[i].m_Duration;

		if (time <= 0.0f || &(m_AnimationRect[i]) == &m_AnimationRect.back())
		{
			m_Sprite.setTextureRect(m_AnimationRect[i].m_IntRect);
			break;
		}
	}
}
void Animation::AddIntRect(AnimationFrame&& frameRect)
{
	m_IntRectLenght += frameRect.m_Duration;
	m_AnimationRect.push_back(std::move(frameRect));
}
const double Animation::GetTime() const
{
	return m_Timer;
}



