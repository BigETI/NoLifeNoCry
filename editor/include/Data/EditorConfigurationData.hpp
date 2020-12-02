#pragma once

#include <string>
#include <rttr/registration.h>

namespace DirtyFinger::Data
{
	struct EditorConfigurationData
	{
		std::string lastOpenedProjectDirectoryPath;
	};

	RTTR_REGISTRATION
	{
		rttr::registration::class_<DirtyFinger::Data::EditorConfigurationData>("EditorConfiguration")
			.constructor<>()
			.property("LastOpenedProjectDirectoryPath", &DirtyFinger::Data::EditorConfigurationData::lastOpenedProjectDirectoryPath);
	}
}
