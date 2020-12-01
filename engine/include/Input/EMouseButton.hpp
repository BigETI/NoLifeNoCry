#pragma once

#include <SFML/Window/Mouse.hpp>

/// @brief Dirt Machine game engine input namespace
namespace DirtMachine::Input
{
	/// @brief Mouse button enumerator
	enum class EMouseButton
	{
		/// @brief The left mouse button
		Left = sf::Mouse::Button::Left,

		/// @brief The right mouse button
		Right = sf::Mouse::Button::Right,

		/// @brief The middle (wheel) mouse button
		Middle = sf::Mouse::Button::Middle,

		/// @brief The first extra mouse button
		XButton1 = sf::Mouse::Button::XButton1,

		/// @brief The second extra mouse button
		XButton2 = sf::Mouse::Button::XButton2,

		/// @brief Number of enumerator elements
		Count = 5
	};
}
