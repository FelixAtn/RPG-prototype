#include "stdafx.h"
#include "C_Animation.h"

C_Animation::C_Animation(Object& object)
	: m_SpriteComponent(object.GetComponent<C_Sprite>())
	, m_Data(object.GetComponent<C_AttributeData>())
	, m_Movement(object.GetComponent<C_Movement>())
{
	if (m_SpriteComponent == nullptr || m_Movement == nullptr || m_Data == nullptr)
	{
		Log::Print("Animation - failed INIT: Missing components (nullptr)", LogLevel::ERROR_);
		throw std::runtime_error("Animation - Missing Components");
	}
	LoadAnimations(m_Data->GetName());
}


void C_Animation::LoadAnimations(const std::string& objectName)
{
	YAML::Node config = ResourceManager::Get().GetCharacterFile();
	Animation animation;

	if (!config[objectName] || !config[objectName]["ANIMATIONS"])
	{
		Log::Print("NODE IN FILE NOT FOUND", objectName, LogLevel::WARNING);
		return;
	}

	for (const auto& cfg : config[objectName]["ANIMATIONS"])
	{
		if (!cfg["animationID"])
		{
			return;
		}

		animation.duration = cfg["interval"].as<float>();
		animation.row = cfg["row"].as<int>();
		animation.framesOnRow = cfg["xFrames"].as<int>();
		animation.width = cfg["width"].as<int>();
		animation.height = cfg["height"].as<int>();
		animation.playOnce = cfg["playOnce"].as<bool>();
		animation.playOnce = cfg["playOnce"].as<bool>();
		animation.isAction = cfg["isAction"].as<bool>(false);
		animation.priority = cfg["priority"].as<int>(0);

		int id = cfg["animationID"].as<int>();
		MapAnimation(animation, id);
	};
}

void C_Animation::Update(float deltaTime) 
{
	if (m_IsPaused)
	{
		return;
	}

	// Update action animation if it exists
	if (m_CurrentActionAnimation != nullptr)
	{
		m_ActionTimer.SetInterval(m_CurrentActionAnimation->duration);
		if (m_ActionTimer.HasTimePassed(deltaTime))
		{
			if (m_ActionFrameIndex < m_CurrentActionAnimation->framesOnRow)
			{
				// Update sprite for action animation
				sf::IntRect rect;
				rect.left = m_ActionFrameIndex * m_CurrentActionAnimation->width;
				rect.top = m_CurrentActionAnimation->row * m_CurrentActionAnimation->height;
				rect.width = m_CurrentActionAnimation->width;
				rect.height = m_CurrentActionAnimation->height;
				m_SpriteComponent->GetSprite().setTextureRect(rect);
				m_ActionFrameIndex++;
			}
			else if (m_CurrentActionAnimation->playOnce)
			{
				m_CurrentActionAnimation = nullptr;
				m_CurrentActionID = AnimationID::NONE;
				m_ActionFrameIndex = 0;
				UpdateCurrentAnimation(); // Return to movement animation
			}
			else
			{
				m_ActionFrameIndex = 0;
			}
		}
		return; // Don't update movement animation while action is playing
	}

	// Update movement animation
	if (m_CurrentAnimation) 
	{
		m_Timer.SetInterval(m_CurrentAnimation->duration);
		if (m_Timer.HasTimePassed(deltaTime))
		{
			if (m_FrameIndex < m_CurrentAnimation->framesOnRow) 
			{
				sf::IntRect rect;
				rect.left = m_FrameIndex * m_CurrentAnimation->width;
				rect.top = m_CurrentAnimation->row * m_CurrentAnimation->height;
				rect.width = m_CurrentAnimation->width;
				rect.height = m_CurrentAnimation->height;
				m_SpriteComponent->GetSprite().setTextureRect(rect);
				m_FrameIndex++;
			}
			else 
			{
				m_FrameIndex = 0;
			}
		}
	}
}

void C_Animation::UpdateMovementState(bool isMoving)
{
	m_IsMoving = isMoving;

	if (m_CurrentActionAnimation == nullptr) // Only update movement animation if no action is playing
	{ 
		UpdateCurrentAnimation();
	}
}

void C_Animation::PlayAction(AnimationID id)
{
	if (!IsAnimationValid(id))
	{
		return;
	}

	Animation& newAction = m_Animations[id];

	if (!newAction.isAction)
	{
		return; // Only play animations marked as actions
	}

	// Check if we can interrupt current action
	if (m_CurrentActionAnimation != nullptr && newAction.priority <= m_CurrentActionAnimation->priority)
	{
		return;
	}

	m_CurrentActionAnimation = &newAction;
	m_CurrentActionID = id;
	m_ActionFrameIndex = 0;
	m_ActionTimer.Restart();
}

void C_Animation::MapAnimation(const Animation& animation, int idAsInt)
{
	AnimationID id = static_cast<AnimationID>(idAsInt);

	if (m_Animations.find(id) != m_Animations.end()) 
	{
		throw std::runtime_error("Animation ID already exists: " + std::to_string(idAsInt));
	}

	m_Animations.emplace(id, animation);
}

void C_Animation::HandleCompletedAnimation() 
{
	if (m_FrameIndex >= m_CurrentAnimation->framesOnRow)
	{
		if (m_CurrentAnimation->playOnce) 
		{
			Stop();
		}

		else 
		{
			m_FrameIndex = 0;
		}
	}
}

bool C_Animation::IsAnimationValid(AnimationID id) const 
{
	return m_Animations.find(id) != m_Animations.end();
}

AnimationID C_Animation::GetDirectionalAnimation(bool isMoving) const
{
	if (isMoving)
	{
		switch (m_Movement->GetCurrentDirection())
		{
		case Direction::DOWN: return AnimationID::WALK_DOWN;
		case Direction::UP: return AnimationID::WALK_UP;
		case Direction::LEFT: return AnimationID::WALK_LEFT;
		case Direction::RIGHT: return AnimationID::WALK_RIGHT;
		}
	}
	else 
	{
		switch (m_Movement->GetCurrentDirection())
		{
		case Direction::DOWN: return AnimationID::IDLE_DOWN_LEFT;
		case Direction::UP: return AnimationID::IDLE_UP;
		case Direction::LEFT: return AnimationID::IDLE_DOWN_LEFT;
		case Direction::RIGHT: return AnimationID::IDLE_DOWN_RIGHT;
		}
	}
	return AnimationID::IDLE_DOWN_LEFT; 
}

void C_Animation::UpdateCurrentAnimation()
{
	AnimationID newAnimID = GetDirectionalAnimation(m_IsMoving);

	if (newAnimID != m_CurrentAnimationID) 
	{
		m_CurrentAnimationID = newAnimID;
		m_CurrentAnimation = &m_Animations[newAnimID];
		m_FrameIndex = 0;
		m_Timer.Restart();
	}
}

void C_Animation::Pause() 
{
	m_IsPaused = true;
}

void C_Animation::Resume() 
{
	m_IsPaused = false;
}

void C_Animation::Stop() 
{
	m_CurrentAnimation = nullptr;
	m_CurrentAnimationID = AnimationID::NONE;
	m_FrameIndex = 0;
	m_Timer.Restart();
}

bool C_Animation::IsActionPlaying() const
{
	return false;
}

