#include "AnimationManager.h"
#include <iostream>

AnimationManager::AnimationManager(sf::Sprite& target) 
	: m_Target(target)
	, m_CurrentFrame(0.f)
	, m_TotalFrames(0.f)
{
	m_CurrentFrame = m_TotalFrames = 0.0f;
	m_Frames.reserve(20);
}

void AnimationManager::AddAnimation(int xStartFrame, int xEndFrame, int row, int width, int height, float animationSpeed)
{
	int y = height * row;
	for (int i = xStartFrame; i < xEndFrame; ++i)
	{
		int x = (i * width) % 512;
		AddFrame(x, y, width, height, animationSpeed);
	}
}

void AnimationManager::AddFrame(int x, int y, int width, int height, float animationSpeed)
{
	sf::IntRect rect(x, y, width, height);
	Frame frame = { rect, animationSpeed };
	m_TotalFrames += frame.m_AnimationSpeed;
	m_Frames.emplace_back(frame);
}

void AnimationManager::Update(float deltaTime, bool isLooping)
{
	m_CurrentFrame += deltaTime;
	ProcessAnimation(isLooping);
}

void AnimationManager::ProcessAnimation(bool isLooping)
{
	float currentFrame = m_CurrentFrame;
	for (size_t i = 0; i < m_Frames.size(); i++)
	{
		currentFrame -= m_Frames[i].m_AnimationSpeed;

		if (ShouldFrameAdvance(currentFrame, i))
		{
			m_Target.setTextureRect(m_Frames[i].rect);

			if (isLooping && IsLastFrameEnding(i))
			{
				Reset();
			}
			else if (!isLooping && IsLastFrameBeforeEnding(i))
			{
				m_CurrentFrame = m_TotalFrames; // the last frame stay visible
			}
			break;
		}
	}
}

const bool AnimationManager::ShouldFrameAdvance(float currentFrame, size_t index ) const
{
	const Frame& lastFrame = m_Frames.back();
	return currentFrame <= 0.0f || &(m_Frames[index]) == &lastFrame; // Check if it's on the last frame
}

const bool AnimationManager::IsLastFrameEnding(size_t index) const 
{
	const Frame& lastFrame = m_Frames.back();
	return IsAnimationComplete() && &(m_Frames[index]) == &lastFrame; // check if the animation is complete and on the last frame
}

const bool AnimationManager::IsLastFrameBeforeEnding(size_t index) const
{
	const Frame& lastFrame = m_Frames.back(); 
	return !IsAnimationComplete() && &(m_Frames[index]) == &lastFrame; // Check if the animation is not complete and on the last frame
}

const bool AnimationManager::IsAnimationComplete() const 
{
	return m_CurrentFrame >= m_TotalFrames; // Check if the animation is complete
}

void AnimationManager::Reset()
{
	m_CurrentFrame = 0.0;
}
