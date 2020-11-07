#pragma once

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Joystick button data structure
	struct JoystickButtonData
	{
		/// @brief Index of the joystick (in range [0 .. Joystick::Count - 1])
		unsigned int joystickID;

		/// @brief Index of the button that has been pressed (in range [0 .. Joystick::ButtonCount - 1])
		unsigned int button;
	};
}
