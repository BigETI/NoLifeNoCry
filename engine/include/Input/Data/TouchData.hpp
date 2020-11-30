#pragma once

#include <glm/vec2.hpp>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
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
