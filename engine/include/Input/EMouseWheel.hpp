#pragma once

#include <SFML/Window/Mouse.hpp>

/// @brief Dirt Machine game engine input namespace
namespace DirtMachine::Input
{
	/// @brief Mouse wheel enumerator
	enum class EMouseWheel
	{
		/// @brief The vertical mouse wheel
		VerticalWheel = sf::Mouse::Wheel::VerticalWheel,

		/// @brief The horizontal mouse wheel
		HorizontalWheel = sf::Mouse::Wheel::HorizontalWheel
	};
}
