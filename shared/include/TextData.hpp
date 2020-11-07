#pragma once

#include <cstdint>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Text data structure
	struct TextData
	{
		/// @brief UTF-32 Unicode value of the character
		std::uint32_t unicode;
	};
}
