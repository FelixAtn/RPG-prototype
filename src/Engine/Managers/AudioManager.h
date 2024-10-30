#pragma once

class AudioManager
{
public:
	void PlaySoundX(const std::string& name);
	void PlayMusic(const std::string& name);
	void Volume(int factor);
	void StopMusic(const std::string& name);
	void StopAllSounds();
	void RemoveSound();

private:
	std::vector<std::shared_ptr<sf::Sound>> m_Sounds;
};