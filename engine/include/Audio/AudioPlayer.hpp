#pragma once

#include <SFML/Audio/Sound.hpp>
#include <Audio/AudioClip.hpp>
#include <Audio/EAudioPlayStatus.hpp>

/// @brief No Life, No Cry engine audio namespace
namespace NoLifeNoCry::Engine::Audio
{
	/// @brief Audio player class
	class AudioPlayer : sf::Sound
	{
        /// @brief Play audio
        void Play();

        /// @brief Pause audio
        void Pause();

        /// @brief Stop audio
        void Stop();

        /// @brief Set audio clip
        /// @param audioClip Audio clip
        void SetAudioClip(const NoLifeNoCry::Engine::Audio::AudioClip& audioClip);
        
        /// @brief Set loop
        /// @param loop Loop
        void SetLoop(bool loop);

        /// @brief Set playing time offset
        /// @param timeOffset Time offset
        void SetPlayingTimeOffset(NoLifeNoCry::Engine::Time timeOffset);
        
        /// @brief Get audio clip
        /// @return Audio clip
        const NoLifeNoCry::Engine::Audio::AudioClip* GetAudioClip() const;
        
        /// @brief Get loop
        /// @return Loop
        bool GetLoop() const;
        
        /// @brief Get playing time offset
        /// @return Playing time offset
        NoLifeNoCry::Engine::Time GetPlayingTimeOffset() const;

        /// @brief Get audio play status
        /// @return Audio play status
        NoLifeNoCry::Engine::Audio::EAudioPlayStatus GetAudioPlayStatus() const;
        
        /// @brief Reset audio clip
        void ResetAudioClip();

        /// @brief Assign operator
        /// @param audioPlayer Audio player
        /// @return Itself
        AudioPlayer& operator =(const AudioPlayer& audioPlayer);
	};
}
