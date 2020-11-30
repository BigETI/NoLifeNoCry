#include <Audio/AudioPlayer.hpp>

/// @brief Play audio
void NoLifeNoCry::Engine::Audio::AudioPlayer::Play()
{
	play();
}

/// @brief Pause audio
void NoLifeNoCry::Engine::Audio::AudioPlayer::Pause()
{
	pause();
}

/// @brief Stop audio
void NoLifeNoCry::Engine::Audio::AudioPlayer::Stop()
{
	stop();
}

/// @brief Set audio clip
/// @param audioClip Audio clip
void NoLifeNoCry::Engine::Audio::AudioPlayer::SetAudioClip(const NoLifeNoCry::Engine::Audio::AudioClip& audioClip)
{
	setBuffer(audioClip);
}

/// @brief Set loop
/// @param loop Loop
void NoLifeNoCry::Engine::Audio::AudioPlayer::SetLoop(bool loop)
{
	setLoop(loop);
}

/// @brief Set playing time offset
/// @param timeOffset Time offset
void NoLifeNoCry::Engine::Audio::AudioPlayer::SetPlayingTimeOffset(Time timeOffset)
{
	setPlayingOffset(timeOffset);
}

/// @brief Get audio clip
/// @return Audio clip
const NoLifeNoCry::Engine::Audio::AudioClip* NoLifeNoCry::Engine::Audio::AudioPlayer::GetAudioClip() const
{
	return reinterpret_cast<const NoLifeNoCry::Engine::Audio::AudioClip*>(getBuffer());
}

/// @brief Get loop
/// @return Loop
bool NoLifeNoCry::Engine::Audio::AudioPlayer::GetLoop() const
{
	return getLoop();
}

/// @brief Get playing time offset
/// @return Playing time offset
NoLifeNoCry::Engine::Time NoLifeNoCry::Engine::Audio::AudioPlayer::GetPlayingTimeOffset() const
{
	return getPlayingOffset();
}

/// @brief Get audio play status
/// @return Audio play status
NoLifeNoCry::Engine::Audio::EAudioPlayStatus NoLifeNoCry::Engine::Audio::AudioPlayer::GetAudioPlayStatus() const
{
	return static_cast<NoLifeNoCry::Engine::Audio::EAudioPlayStatus>(getStatus());
}

/// @brief Reset audio clip
void NoLifeNoCry::Engine::Audio::AudioPlayer::ResetAudioClip()
{
	resetBuffer();
}

/// @brief Assign operator
/// @param audioPlayer Audio player
/// @return Itself
NoLifeNoCry::Engine::Audio::AudioPlayer& NoLifeNoCry::Engine::Audio::AudioPlayer::operator =(const NoLifeNoCry::Engine::Audio::AudioPlayer& audioPlayer)
{
	*reinterpret_cast<sf::Sound*>(this) = audioPlayer;
	return *this;
}
