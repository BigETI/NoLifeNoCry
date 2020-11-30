#pragma once

#include <glm/vec3.hpp>
#include <Input/ESensorType.hpp>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Sensor data structure
	struct SensorData
	{
		/// @brief Type of the sensor
		NoLifeNoCry::Engine::Input::ESensorType type;

		/// @brief Current value of the sensor
		glm::vec3 value;
	};
}
