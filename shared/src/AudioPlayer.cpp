#include "AudioPlayer.hpp"

/// @brief Play audio
void NoLifeNoCry::Engine::AudioPlayer::Play()
{
	play();
}

/// @brief Pause audio
void NoLifeNoCry::Engine::AudioPlayer::Pause()
{
	pause();
}

/// @brief Stop audio
void NoLifeNoCry::Engine::AudioPlayer::Stop()
{
	stop();
}

/// @brief Set audio clip
/// @param audioClip Audio clip
void NoLifeNoCry::Engine::AudioPlayer::SetAudioClip(const NoLifeNoCry::Engine::AudioClip& audioClip)
{
	setBuffer(audioClip);
}

/// @brief Set loop
/// @param loop Loop
void NoLifeNoCry::Engine::AudioPlayer::SetLoop(bool loop)
{
	setLoop(loop);
}

/// @brief Set playing time offset
/// @param timeOffset Time offset
void NoLifeNoCry::Engine::AudioPlayer::SetPlayingTimeOffset(Time timeOffset)
{
	setPlayingOffset(timeOffset);
}

/// @brief Get audio clip
/// @return Audio clip
const NoLifeNoCry::Engine::AudioClip* NoLifeNoCry::Engine::AudioPlayer::GetAudioClip() const
{
	return reinterpret_cast<const NoLifeNoCry::Engine::AudioClip*>(getBuffer());
}

/// @brief Get loop
/// @return Loop
bool NoLifeNoCry::Engine::AudioPlayer::GetLoop() const
{
	return getLoop();
}

/// @brief Get playing time offset
/// @return Playing time offset
NoLifeNoCry::Engine::Time NoLifeNoCry::Engine::AudioPlayer::GetPlayingTimeOffset() const
{
	return getPlayingOffset();
}

/// @brief Get audio play status
/// @return Audio play status
NoLifeNoCry::Engine::EAudioPlayStatus NoLifeNoCry::Engine::AudioPlayer::GetAudioPlayStatus() const
{
	return static_cast<NoLifeNoCry::Engine::EAudioPlayStatus>(getStatus());
}

/// @brief Reset audio clip
void NoLifeNoCry::Engine::AudioPlayer::ResetAudioClip()
{
	resetBuffer();
}

/// @brief Assign operator
/// @param audioPlayer Audio player
/// @return Itself
NoLifeNoCry::Engine::AudioPlayer& NoLifeNoCry::Engine::AudioPlayer::operator =(const AudioPlayer& audioPlayer)
{
	*reinterpret_cast<sf::Sound*>(this) = audioPlayer;
	return *this;
}
