#pragma once

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	struct MouseMovementData
	{
		/// @brief X position of the mouse pointer, relative to the left of the owner window
		int x;

		/// @brief Y position of the mouse pointer, relative to the top of the owner window
		int y;
	};
}
