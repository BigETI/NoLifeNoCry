#pragma once

#include <SFML/Graphics/Rect.hpp>

/// @brief Dirt Machine game engine graphic namespace
namespace DirtMachine::Graphic
{
	/// @brief Rectangle
	/// @tparam T Rectangle components type
	template <typename T>
	using Rectangle = sf::Rect<T>;
}
