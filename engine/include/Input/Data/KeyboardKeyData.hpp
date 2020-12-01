#pragma once

#include <Input/EKeyboardKey.hpp>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	/// @brief Keyboard key data structure
	struct KeyboardKeyData
	{
		/// @brief Code of the key that has been pressed
		DirtMachine::Input::EKeyboardKey keyCode;

		/// @brief Is the Alt key used?
		bool isAltKeyUsed;

		/// @brief Is the Control key used?
		bool isControlKeyUsed;

		/// @brief Is the Shift key used?
		bool isShiftKeyUsed;

		/// @brief Is the System key used?
		bool isSystemKeyUsed;
	};
}
