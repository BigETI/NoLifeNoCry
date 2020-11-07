#pragma once

#include "ESensorType.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Sensor data structure
	struct SensorData
	{
		/// @brief Type of the sensor
		NoLifeNoCry::Engine::ESensorType type;

		/// @brief Current value of the sensor on X axis
		float x;

		/// @brief Current value of the sensor on Y axis
		float y;

		/// @brief Current value of the sensor on Z axis
		float z;
	};
}
