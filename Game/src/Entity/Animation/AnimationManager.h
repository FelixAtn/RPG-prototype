#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>


// Reference : Easy Animations With Spritesheets (Maverick peppers) 10th Nov 2018

class AnimationManager
{
public:
	AnimationManager(sf::Sprite& target);
	struct Frame
	{
		sf::IntRect rect;
		float m_AnimationSpeed;
	};

	void AddAnimation(int xStartFrame, int xEndFrame, int row, int width, int height, float animationSpeed);
	void AddFrame(int x, int y, int width, int height, float frameSpeed);
	void Update(float deltaTime, bool isLooping);
	void ProcessAnimation(bool isLooping);
	const bool ShouldFrameAdvance(float currentFrame, size_t index) const;
	const bool IsLastFrameEnding(size_t index) const;
	const bool IsLastFrameBeforeEnding(size_t index) const;
	const bool IsAnimationComplete() const;
	void Reset();

private:
	std::vector<Frame> m_Frames;
	float m_TotalFrames;
	float m_CurrentFrame;
	sf::Sprite& m_Target;
};















