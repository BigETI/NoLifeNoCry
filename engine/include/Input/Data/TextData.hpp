#pragma once

#include <cstdint>

/// @brief No Life, No Cry engine input data namespace
namespace NoLifeNoCry::Engine::Input::Data
{
	/// @brief Text data structure
	struct TextData
	{
		/// @brief UTF-32 Unicode value of the character
		std::uint32_t unicode;
	};
}
