#pragma once

#include <Input/EKeyboardKey.hpp>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Keyboard key data structure
	struct KeyboardKeyData
	{
		/// @brief Code of the key that has been pressed
		NoLifeNoCry::Engine::Input::EKeyboardKey keyCode;

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
