#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>

#include "AudioClip.hpp"

/// @brief Default constructor
NoLifeNoCry::Engine::AudioClip::AudioClip()
{
	// ...
}

/// @brief Constructor
/// @param path Audio clip path
NoLifeNoCry::Engine::AudioClip::AudioClip(const std::string& path)
{
	loadFromFile(path);
}

/// @brief Copy constructor
/// @param audioClip Audio clip
NoLifeNoCry::Engine::AudioClip::AudioClip(const AudioClip& audioClip) : sf::SoundBuffer(audioClip)
{
	// ...
}

/// @brief Move constructor
/// @param audioClip Audio clip
NoLifeNoCry::Engine::AudioClip::AudioClip(AudioClip&& audioClip) noexcept : sf::SoundBuffer(audioClip)
{
	// ...
}

/// @brief Load audio clip from file
/// @param path Audio clip path
/// @return "true" if audio clip was successfully loaded from file, otherwise "false"
bool NoLifeNoCry::Engine::AudioClip::LoadFromFile(const std::string& path)
{
	return loadFromFile(path);
}

/// @brief Save audio clip to file
/// @param path Audio clip path
/// @return "true" if audio clip was successfully saved at the specified path, otherwise "false"
bool NoLifeNoCry::Engine::AudioClip::SaveToFile(const std::string& path) const
{
	return saveToFile(path);
}

/// @brief Get samples
/// @return Samples
const std::tuple<const std::int16_t*, std::size_t> NoLifeNoCry::Engine::AudioClip::GetSamples() const
{
	return std::make_tuple<const std::int16_t*, std::size_t>(reinterpret_cast<const std::int16_t*>(getSamples()), static_cast<std::size_t>(getSampleCount()));
}

/// @brief Get audio clip channel count
/// @return Audio clip channel count
unsigned int NoLifeNoCry::Engine::AudioClip::GetChannelCount() const
{
	return getChannelCount();
}

/// @brief Get audio clip duration
/// @return Audio clip duration
NoLifeNoCry::Engine::Time NoLifeNoCry::Engine::AudioClip::GetDuration() const
{
	return getDuration();
}

/// @brief Assign operator
/// @param audioClip Audio clip
/// @return Itself
NoLifeNoCry::Engine::AudioClip& NoLifeNoCry::Engine::AudioClip::operator =(const AudioClip& audioClip)
{
	*reinterpret_cast<sf::SoundBuffer*>(this) = audioClip;
	return *this;
}