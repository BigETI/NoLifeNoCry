#pragma once

#include <cstdint>

/// @brief Dirt Machine game engine input data namespace
namespace DirtMachine::Input::Data
{
	/// @brief Text data structure
	struct TextData
	{
		/// @brief UTF-32 Unicode value of the character
		std::uint32_t unicode;
	};
}
