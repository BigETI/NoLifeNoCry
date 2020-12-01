#pragma once

#include <SFML/Audio/Sound.hpp>
#include <Audio/AudioClip.hpp>
#include <Audio/EAudioPlayStatus.hpp>

/// @brief Dirt Machine game engine audio namespace
namespace DirtMachine::Audio
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
        void SetAudioClip(const DirtMachine::Audio::AudioClip& audioClip);
        
        /// @brief Set loop
        /// @param loop Loop
        void SetLoop(bool loop);

        /// @brief Set playing time offset
        /// @param timeOffset Time offset
        void SetPlayingTimeOffset(DirtMachine::Time timeOffset);
        
        /// @brief Get audio clip
        /// @return Audio clip
        const DirtMachine::Audio::AudioClip* GetAudioClip() const;
        
        /// @brief Get loop
        /// @return Loop
        bool GetLoop() const;
        
        /// @brief Get playing time offset
        /// @return Playing time offset
        DirtMachine::Time GetPlayingTimeOffset() const;

        /// @brief Get audio play status
        /// @return Audio play status
        DirtMachine::Audio::EAudioPlayStatus GetAudioPlayStatus() const;
        
        /// @brief Reset audio clip
        void ResetAudioClip();

        /// @brief Assign operator
        /// @param audioPlayer Audio player
        /// @return Itself
        AudioPlayer& operator =(const AudioPlayer& audioPlayer);
	};
}
