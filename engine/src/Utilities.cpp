#include <ctime>
#include <Utilities.hpp>

/// @brief Gets the date and time string from point
/// @param timePoint Time point
/// @return Date and time string
std::string NoLifeNoCry::Engine::Utilities::GetDateTimeStringFromTimePoint(const std::chrono::system_clock::time_point& timePoint)
{
	std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
	return std::ctime(&time);
}
