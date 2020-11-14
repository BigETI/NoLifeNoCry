#pragma once

#include <string>
#include <rttr/registration.h>

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Asset meta data structure
	struct AssetMetaData
	{
		/// @brief Author name
		std::string author;

		/// @brief License
		std::string license;
	};

	RTTR_REGISTRATION
	{
		rttr::registration::class_<NoLifeNoCry::Engine::AssetMetaData>("Meta")
			.constructor<>()
			.property("Author", &NoLifeNoCry::Engine::AssetMetaData::author)
			.property("License", &NoLifeNoCry::Engine::AssetMetaData::license);
	}
}
