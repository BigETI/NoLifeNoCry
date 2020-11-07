#pragma once

#include "EMouseButton.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Mouse button data structure
	struct MouseButtonData
	{
		/// @brief ode of the button that has been pressed
		NoLifeNoCry::Engine::EMouseButton button;

		/// @brief X position of the mouse pointer, relative to the left of the owner window
		int  x;

		/// @brief Y position of the mouse pointer, relative to the top of the owner window
		int y;
	};
}
