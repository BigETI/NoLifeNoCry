#pragma once

#include <glm/vec3.hpp>
#include <Input/ESensorType.hpp>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	/// @brief Sensor data structure
	struct SensorData
	{
		/// @brief Type of the sensor
		DirtMachine::Input::ESensorType type;

		/// @brief Current value of the sensor
		glm::vec3 value;
	};
}
