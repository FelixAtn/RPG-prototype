#include "stdafx.h"
#include "AudioManager.h"

void AudioManager::PlaySoundX(const std::string& name)
{
	if (ResourceManager::Get().GetSoundBuffer(name) != nullptr) 
	{
		auto sound = std::make_shared<sf::Sound>(); // Create a shared pointer to a sound
		sound->setBuffer(*ResourceManager::Get().GetSoundBuffer(name));
		sound->play();
		m_Sounds.push_back(sound); 
		RemoveSound();
	}
	else
	{
		Log::Print("SOUND " + name, LogLevel::ERROR_);
	}
		
}

void AudioManager::PlayMusic(const std::string& name)
{
	ResourceManager::Get().GetMusic(name).play();
}

void AudioManager::Volume(int factor)
{
	
}

void AudioManager::StopMusic(const std::string& name)
{
	ResourceManager::Get().GetMusic(name).stop();
}

void AudioManager::StopAllSounds()
{
	
}

void AudioManager::RemoveSound()
{
	m_Sounds.erase(std::remove_if(m_Sounds.begin(), m_Sounds.end(), [](const std::shared_ptr<sf::Sound>& sound)
		{
			return sound->getStatus() == sf::Sound::Stopped;
		}), m_Sounds.end());
}

void AudioManager::SetBuffer(const std::string& sound)
{
	m_SingleSound.setBuffer(*ResourceManager::Get().GetSoundBuffer(sound));

}

bool AudioManager::Play()
{
	if (m_SingleSound.getStatus() != sf::Sound::Playing)
	{
		m_SingleSound.play();
		return true;
	}
	return false;
}

bool AudioManager::IsSoundDone()
{
	if (m_SingleSound.getStatus() == sf::Sound::Stopped)
	{
		return true;
	}
	return false;
}