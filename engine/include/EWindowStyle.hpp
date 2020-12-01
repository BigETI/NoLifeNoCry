#pragma once

#include <SFML/Window/WindowStyle.hpp>

/// @brief Dirt Machine game engine namespace
namespace DirtMachine
{
	/// @brief Game window style enumerator
	enum class EWindowStyle
	{
		/// @brief No window style
		None = sf::Style::None,

		/// @brief Titlebar
		Titlebar = sf::Style::Titlebar,

		/// @brief Closed
		Close = sf::Style::Close,

		/// @brief Default
		Default = sf::Style::Default,

		/// @brief Fullscreen
		Fullscreen = sf::Style::Fullscreen
	};
}
