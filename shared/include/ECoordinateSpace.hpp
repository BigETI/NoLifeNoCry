#pragma once

#include <SFML/Graphics/Texture.hpp>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
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
