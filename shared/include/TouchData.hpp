#pragma once

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Touch data structure
	struct TouchData
	{
		/// @brief Index of the finger in case of multi-touch events
		unsigned int finger;

		/// @brief X position of the touch, relative to the left of the owner window
		int x;

		/// @brief Y position of the touch, relative to the top of the owner window
		int y;
	};
}
