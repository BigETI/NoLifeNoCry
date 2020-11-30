#pragma once

#include <SFML/Audio/SoundSource.hpp>

/// @brief No Life, No Cry engine audio namespace
namespace NoLifeNoCry::Engine::Audio
{
	/// @brief Audio play status enumerator
	enum class EAudioPlayStatus
	{
		/// @brief Audio play has stopped
		Stopped = sf::SoundSource::Stopped,

		/// @brief Audio play has paused
		Paused = sf::SoundSource::Paused,

		/// @brief Audio is playing
		Playing = sf::SoundSource::Playing
	};
}
