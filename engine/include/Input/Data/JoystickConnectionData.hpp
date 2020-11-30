#pragma once

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Joystick connection data structure
	struct JoystickConnectionData
	{
		/// @brief Index of the joystick (in range [0 .. Joystick::Count - 1])
		unsigned int joystickID;
	};
}
