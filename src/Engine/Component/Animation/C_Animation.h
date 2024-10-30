#pragma once


class C_Animation : public I_Component
{
public:
	C_Animation(Object& object);
	struct Animation
	{
		float duration; // Time between frames
		int id;
		int row; // Row of the spritesheet for the animation
		int framesOnRow; // Number of frames in animation
		int width;
		int height;
		bool playOnce = false; // whether or not this animation should play only once
		bool isAction = false;  // True for animations that can play while moving (attacks, buffs)
		int priority = 0;      // Higher priority animations interrupt lower ones
	};

	void Update(float deltaTime) override;
	void UpdateMovementState(bool isMoving);

	void PlayAction(AnimationID id);
	void Pause();
	void Resume();
	void Stop();

	bool IsPlaying() const { return m_CurrentAnimation != nullptr && !m_IsPaused; }
	bool IsActionPlaying() const;
	AnimationID GetCurrentAnimation() const { return m_CurrentAnimationID; }

private:
	void LoadAnimations(const std::string& configFile);
	void MapAnimation(const Animation& animation, int idAsInt);
	void HandleCompletedAnimation();
	bool IsAnimationValid(AnimationID id) const;
	AnimationID GetDirectionalAnimation(bool isMoving) const;
	void UpdateCurrentAnimation();

private:
	C_Sprite* m_SpriteComponent;
	C_AttributeData* m_Data;
	C_Movement* m_Movement;

	Animation* m_CurrentAnimation = nullptr;
	Animation* m_CurrentActionAnimation = nullptr;

	std::unordered_map<AnimationID, Animation> m_Animations;

	Timer m_Timer;
	Timer m_ActionTimer;

	int m_FrameIndex = 0;
	int m_ActionFrameIndex = 0;

	bool m_IsPaused = false;
	bool m_IsMoving = false;

	AnimationID m_CurrentAnimationID = AnimationID::NONE;
	AnimationID m_CurrentActionID = AnimationID::NONE;
};
