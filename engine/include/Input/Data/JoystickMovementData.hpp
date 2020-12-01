#pragma once

#include <Input/EJoystickAxis.hpp>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	/// @brief Joystick movement data structure
	struct JoystickMovementData
	{
		/// @brief Index of the joystick (in range [0 .. Joystick::Count - 1])
		unsigned int joystickID;

		/// @brief Axis on which the joystick moved
		DirtMachine::Input::EJoystickAxis axis;

		/// @brief New position on the axis (in range [-100 .. 100])
		float position;
	};
}
