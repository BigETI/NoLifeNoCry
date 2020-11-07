#pragma once

#include <cstdint>
#include <span>
#include <string>
#include <tuple>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/SoundSource.hpp>
#include <glm/vec3.hpp>

#include "Time.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Audio clip class
	class AudioClip : public sf::SoundBuffer
	{
	public:

		/// @brief Default constructor
		AudioClip();

		/// @brief Constructor
		/// @param path Audio clip path
		AudioClip(const std::string& path);

		/// @brief Constructor
		/// @tparam Extent Number of bytes
		/// @param memory Audio clip from memory
		template <std::size_t Extent>
		AudioClip(const std::span<std::uint8_t, Extent> memory)
		{
			loadFromMemory(memory.data(), memory.size());
		}

		/// @brief Constructor
		/// @tparam Extent Number of bytes
		/// @param samples Audio clip from samples
		/// @param channelCount Channel count
		/// @param sampleRate Sample rate
		template <std::size_t Extent>
		AudioClip(const std::span<std::int16_t, Extent> samples, unsigned int channelCount, unsigned int sampleRate)
		{
			loadFromSamples(samples.data(), samples.size(), channelCount, sampleRate);
		}

		/// @brief Copy constructor
		/// @param audioClip Audio clip
		AudioClip(const AudioClip& audioClip);

		/// @brief Move constructor
		/// @param audioClip Audio clip
		AudioClip(AudioClip&& audioClip) noexcept;

        /// @brief Load audio clip from file
        /// @param path Audio clip path
        /// @return "true" if audio clip was successfully loaded from file, otherwise "false"
        bool LoadFromFile(const std::string& path);

		/// @brief Load audio clip from memory
		/// @param memory Audio clip from memory
		/// @return "true" if audio clip was successfully loaded from memory, otherwise "false"
		template <std::size_t Extent>
		bool LoadFromMemory(const std::span<std::uint8_t, Extent> memory)
		{
			return loadFromMemory(memory.data(), memory.size());
		}

		/// @brief Load audio clip from samples
		/// @param samples Samples
		/// @param channelCount Channel count
		/// @param sampleRate Sample rate
		/// @return "true" if audio clip wa successfully loaded from samples, otherwise "false"
		template <std::size_t Extent>
		bool LoadFromSamples(const std::span<std::int16_t, Extent> samples, unsigned int channelCount, unsigned int sampleRate)
		{
			return loadFromSamples(samples.data(), samples.size(), channelCount, sampleRate);
		}

		/// @brief Save audio clip to file
		/// @param path Audio clip path
		/// @return "true" if audio clip was successfully saved at the specified path, otherwise "false"
		bool SaveToFile(const std::string& path) const;

		/// @brief Get samples
		/// @return Samples
		const std::tuple<const std::int16_t*, std::size_t> GetSamples() const;

		/// @brief Get audio clip channel count
		/// @return Audio clip channel count
		unsigned int GetChannelCount() const;

        /// @brief Get audio clip duration
        /// @return Audio clip duration
        Time GetDuration() const;

        /// @brief Assign operator
        /// @param audioClip Audio clip
        /// @return Itself
        AudioClip& operator =(const AudioClip& audioClip);
	};
}
