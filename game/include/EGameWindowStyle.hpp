#pragma once

#include <SFML/Window.hpp>

/// @brief BA3 Game Programming template namespace
namespace BA3GameProgrammingTemplate
{
	/// @brief Game window style enumerator
	enum class EGameWindowStyle
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
