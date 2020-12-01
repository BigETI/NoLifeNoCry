#pragma once

#include <string>
#include <rttr/registration.h>

/// @brief Dirt Machine game engine serialiser data namespace
namespace DirtMachine::Serialiser::Data
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
		rttr::registration::class_<DirtMachine::Serialiser::Data::AssetMetaData>("Meta")
			.constructor<>()
			.property("Author", &DirtMachine::Serialiser::Data::AssetMetaData::author)
			.property("License", &DirtMachine::Serialiser::Data::AssetMetaData::license);
	}
}
