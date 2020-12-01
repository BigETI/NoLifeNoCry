#include <Audio/AudioPlayer.hpp>

/// @brief Play audio
void DirtMachine::Audio::AudioPlayer::Play()
{
	play();
}

/// @brief Pause audio
void DirtMachine::Audio::AudioPlayer::Pause()
{
	pause();
}

/// @brief Stop audio
void DirtMachine::Audio::AudioPlayer::Stop()
{
	stop();
}

/// @brief Set audio clip
/// @param audioClip Audio clip
void DirtMachine::Audio::AudioPlayer::SetAudioClip(const DirtMachine::Audio::AudioClip& audioClip)
{
	setBuffer(audioClip);
}

/// @brief Set loop
/// @param loop Loop
void DirtMachine::Audio::AudioPlayer::SetLoop(bool loop)
{
	setLoop(loop);
}

/// @brief Set playing time offset
/// @param timeOffset Time offset
void DirtMachine::Audio::AudioPlayer::SetPlayingTimeOffset(Time timeOffset)
{
	setPlayingOffset(timeOffset);
}

/// @brief Get audio clip
/// @return Audio clip
const DirtMachine::Audio::AudioClip* DirtMachine::Audio::AudioPlayer::GetAudioClip() const
{
	return reinterpret_cast<const DirtMachine::Audio::AudioClip*>(getBuffer());
}

/// @brief Get loop
/// @return Loop
bool DirtMachine::Audio::AudioPlayer::GetLoop() const
{
	return getLoop();
}

/// @brief Get playing time offset
/// @return Playing time offset
DirtMachine::Time DirtMachine::Audio::AudioPlayer::GetPlayingTimeOffset() const
{
	return getPlayingOffset();
}

/// @brief Get audio play status
/// @return Audio play status
DirtMachine::Audio::EAudioPlayStatus DirtMachine::Audio::AudioPlayer::GetAudioPlayStatus() const
{
	return static_cast<DirtMachine::Audio::EAudioPlayStatus>(getStatus());
}

/// @brief Reset audio clip
void DirtMachine::Audio::AudioPlayer::ResetAudioClip()
{
	resetBuffer();
}

/// @brief Assign operator
/// @param audioPlayer Audio player
/// @return Itself
DirtMachine::Audio::AudioPlayer& DirtMachine::Audio::AudioPlayer::operator =(const DirtMachine::Audio::AudioPlayer& audioPlayer)
{
	*reinterpret_cast<sf::Sound*>(this) = audioPlayer;
	return *this;
}
