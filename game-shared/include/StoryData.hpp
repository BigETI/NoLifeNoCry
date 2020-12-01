#pragma once

#include <string>
#include <ChapterData.hpp>

/// @brief No Life, No Cry namespace
namespace NoLifeNoCry
{
	/// @brief Story data structure
	struct StoryData
	{
		/// @brief Story name
		std::string name;

		/// @brief Story description
		std::string description;

		/// @brief Author name
		std::string author;

		/// @brief License
		std::string license;

		/// @brief Story chapters
		std::vector<NoLifeNoCry::ChapterData> chapters;
	};
}
