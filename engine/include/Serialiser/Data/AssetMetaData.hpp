#pragma once

#include <string>
#include <rttr/registration.h>

/// @brief No Life, No Cry engine serialiser data namespace
namespace NoLifeNoCry::Engine::Serialiser::Data
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
		rttr::registration::class_<NoLifeNoCry::Engine::Serialiser::Data::AssetMetaData>("Meta")
			.constructor<>()
			.property("Author", &NoLifeNoCry::Engine::Serialiser::Data::AssetMetaData::author)
			.property("License", &NoLifeNoCry::Engine::Serialiser::Data::AssetMetaData::license);
	}
}
