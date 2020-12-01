#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <Audio/AudioClip.hpp>

/// @brief Default constructor
DirtMachine::Audio::AudioClip::AudioClip()
{
	// ...
}

/// @brief Constructor
/// @param path Audio clip path
DirtMachine::Audio::AudioClip::AudioClip(const std::string& path)
{
	loadFromFile(path);
}

/// @brief Copy constructor
/// @param audioClip Audio clip
DirtMachine::Audio::AudioClip::AudioClip(const DirtMachine::Audio::AudioClip& audioClip) : sf::SoundBuffer(audioClip)
{
	// ...
}

/// @brief Move constructor
/// @param audioClip Audio clip
DirtMachine::Audio::AudioClip::AudioClip(DirtMachine::Audio::AudioClip&& audioClip) noexcept : sf::SoundBuffer(audioClip)
{
	// ...
}

/// @brief Load audio clip from file
/// @param path Audio clip path
/// @return "true" if audio clip was successfully loaded from file, otherwise "false"
bool DirtMachine::Audio::AudioClip::LoadFromFile(const std::string& path)
{
	return loadFromFile(path);
}

/// @brief Save audio clip to file
/// @param path Audio clip path
/// @return "true" if audio clip was successfully saved at the specified path, otherwise "false"
bool DirtMachine::Audio::AudioClip::SaveToFile(const std::string& path) const
{
	return saveToFile(path);
}

/// @brief Get samples
/// @return Samples
const std::tuple<const std::int16_t*, std::size_t> DirtMachine::Audio::AudioClip::GetSamples() const
{
	return std::make_tuple<const std::int16_t*, std::size_t>(reinterpret_cast<const std::int16_t*>(getSamples()), static_cast<std::size_t>(getSampleCount()));
}

/// @brief Get audio clip channel count
/// @return Audio clip channel count
unsigned int DirtMachine::Audio::AudioClip::GetChannelCount() const
{
	return getChannelCount();
}

/// @brief Get audio clip duration
/// @return Audio clip duration
DirtMachine::Time DirtMachine::Audio::AudioClip::GetDuration() const
{
	return getDuration();
}

/// @brief Assign operator
/// @param audioClip Audio clip
/// @return Itself
DirtMachine::Audio::AudioClip& DirtMachine::Audio::AudioClip::operator =(const DirtMachine::Audio::AudioClip& audioClip)
{
	*reinterpret_cast<sf::SoundBuffer*>(this) = audioClip;
	return *this;
}
