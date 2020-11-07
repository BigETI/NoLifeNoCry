#pragma once

#include "EMouseWheel.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	struct MouseWheelData
	{
		/// @brief Which wheel (for mice with multiple ones)
		NoLifeNoCry::Engine::EMouseWheel wheel;

		/// @brief Wheel offset (positive is up/left, negative is down/right). High-precision mice may use non-integral offsets.
		float delta;

		/// @brief X position of the mouse pointer, relative to the left of the owner window
		int x;

		/// @brief Y position of the mouse pointer, relative to the top of the owner window
		int y;
	};
}
