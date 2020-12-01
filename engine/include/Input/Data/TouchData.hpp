#pragma once

#include <glm/vec2.hpp>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	/// @brief Touch data structure
	struct TouchData
	{
		/// @brief Index of the finger in case of multi-touch events
		unsigned int finger;

		/// @brief Position of the touch, relative to the top-left of the owner window
		glm::ivec2 position;
	};
}
