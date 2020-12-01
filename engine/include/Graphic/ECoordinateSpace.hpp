#pragma once

#include <SFML/Graphics/Texture.hpp>

/// @brief Dirt Machine game engine graphic namespace
namespace DirtMachine::Graphic
{
	/// @brief Coordinate space enumerator
	enum class ECoordinateSpace
	{
		/// @brief Texture coordinates in range [0 .. 1]
		Normalized = sf::Texture::CoordinateType::Normalized,

		/// @brief Texture coordinates in range [0 .. size]
		Pixels = sf::Texture::CoordinateType::Pixels
	};
}
