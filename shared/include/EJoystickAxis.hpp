#pragma once

#include <SFML/Window/Joystick.hpp>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Joystick axis enumerator
	enum class EJoystickAxis
	{
		/// @brief The X axis
		X = sf::Joystick::Axis::X,

		/// @brief The Y axis
		Y = sf::Joystick::Axis::Y,

		/// @brief The Z axis
		Z = sf::Joystick::Axis::Z,

		/// @brief The R axis
		R = sf::Joystick::Axis::R,

		/// @brief The U axis
		U = sf::Joystick::Axis::U,

		/// @brief The V axis
		V = sf::Joystick::Axis::V,

		/// @brief The X axis of the point-of-view hat
		PovX = sf::Joystick::Axis::PovX,

		/// @brief The Y axis of the point-of-view hat
		PovY = sf::Joystick::Axis::PovY
	};
}
