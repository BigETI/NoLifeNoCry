#pragma once

#include <string>
#include <vector>
#include <rttr/registration.h>
#include <PageData.hpp>

/// @brief No Life, No Cry namespace
namespace NoLifeNoCry
{
	/// @brief Chapter data structure
	struct ChapterData
	{
		/// @brief Chapter name
		std::string name;

		/// @brief Chapter desciption
		std::string description;

		/// @brief Pages
		std::vector<NoLifeNoCry::PageData> pages;
	};
}
