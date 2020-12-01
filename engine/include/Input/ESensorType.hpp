#pragma once

#include <SFML/Window/Sensor.hpp>

/// @brief Dirt Machine game engine input namespace
namespace DirtMachine::Input
{
	enum class ESensorType
	{
        /// @brief Measures the raw acceleration (m/s^2)
        Accelerometer = sf::Sensor::Type::Accelerometer,

        /// @brief Measures the raw rotation rates (degrees/s)
        Gyroscope = sf::Sensor::Type::Gyroscope,

        /// @brief Measures the ambient magnetic field (micro-teslas)
        Magnetometer = sf::Sensor::Type::Magnetometer,

        /// @brief Measures the direction and intensity of gravity, independent of device acceleration (m/s^2)
        Gravity = sf::Sensor::Type::Gravity,

        /// @brief Measures the direction and intensity of device acceleration, independent of the gravity (m/s^2)
        UserAcceleration = sf::Sensor::Type::UserAcceleration, ///< 

        /// @brief Measures the absolute 3D orientation (degrees)
        Orientation = sf::Sensor::Type::Orientation
	};
}
