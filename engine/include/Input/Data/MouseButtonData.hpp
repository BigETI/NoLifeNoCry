#pragma once

#include <glm/vec2.hpp>
#include <Input/EMouseButton.hpp>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	/// @brief Mouse button data structure
	struct MouseButtonData
	{
		/// @brief Mode of the button that has been pressed
		DirtMachine::Input::EMouseButton button;

		/// @brief Position of the mouse pointer, relative to the top-left of the owner window
		glm::ivec2 position;
	};
}
