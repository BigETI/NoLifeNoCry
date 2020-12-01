#pragma once

#include <glm/vec2.hpp>
#include <Input/EMouseWheel.hpp>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	struct MouseWheelData
	{
		/// @brief Which wheel (for mice with multiple ones)
		DirtMachine::Input::EMouseWheel wheel;

		/// @brief Wheel offset (positive is up/left, negative is down/right). High-precision mice may use non-integral offsets.
		float delta;

		/// @brief Position of the mouse pointer, relative to the top-left of the owner window
		glm::ivec2 position;
	};
}
