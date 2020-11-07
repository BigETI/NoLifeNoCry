#pragma once

#include "EKeyboardKey.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Keyboard key data structure
	struct KeyboardKeyData
	{
		/// @brief Code of the key that has been pressed
		NoLifeNoCry::Engine::EKeyboardKey keyCode;

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
