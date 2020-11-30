#pragma once

#include <glm/vec2.hpp>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Mouse movement data structure
	struct MouseMovementData
	{
		/// @brief Position of the mouse pointer, relative to the top-left of the owner window
		glm::ivec2 position;
	};
}
