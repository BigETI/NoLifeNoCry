#pragma once

#include <Input/EJoystickAxis.hpp>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Joystick movement data structure
	struct JoystickMovementData
	{
		/// @brief Index of the joystick (in range [0 .. Joystick::Count - 1])
		unsigned int joystickID;

		/// @brief Axis on which the joystick moved
		NoLifeNoCry::Engine::Input::EJoystickAxis axis;

		/// @brief New position on the axis (in range [-100 .. 100])
		float position;
	};
}
