#pragma once

#include <SFML/Graphics/Rect.hpp>

/// @brief No Life, No Cry engine graphic namespace
namespace NoLifeNoCry::Engine::Graphic
{
	/// @brief Rectangle
	/// @tparam T Rectangle components type
	template <typename T>
	using Rectangle = sf::Rect<T>;
}
