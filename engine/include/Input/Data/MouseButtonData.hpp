#pragma once

#include <glm/vec2.hpp>
#include <Input/EMouseButton.hpp>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Mouse button data structure
	struct MouseButtonData
	{
		/// @brief Mode of the button that has been pressed
		NoLifeNoCry::Engine::Input::EMouseButton button;

		/// @brief Position of the mouse pointer, relative to the top-left of the owner window
		glm::ivec2 position;
	};
}
