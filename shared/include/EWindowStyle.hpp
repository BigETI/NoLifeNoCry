#pragma once

#include <SFML/Window/WindowStyle.hpp>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
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
