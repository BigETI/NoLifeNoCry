#pragma once

#include <SFML/Graphics/Rect.hpp>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Rectangle
	/// @tparam T Rectangle components type
	template <typename T>
	using Rectangle = sf::Rect<T>;
}
