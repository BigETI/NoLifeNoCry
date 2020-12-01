#pragma once

#include <chrono>
#include <string>

/// @brief Dirt Machine game engine namespace
namespace DirtMachine
{
	/// @brief Utilities class
	class Utilities
	{
	public:

		Utilities() = delete;
		Utilities(const Utilities&) = delete;
		Utilities(Utilities&&) = delete;

		/// @brief Gets the date and time string from point
		/// @param timePoint Time point
		/// @return Date and time string
		static std::string GetDateTimeStringFromTimePoint(const std::chrono::system_clock::time_point& timePoint);

		Utilities& operator=(const Utilities&) = delete;
		Utilities& operator=(Utilities&&) = delete;
	};
}
