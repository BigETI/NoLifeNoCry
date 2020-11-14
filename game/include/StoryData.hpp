#pragma once

#include <string>
#include <ChapterData.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
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
		std::vector<NoLifeNoCry::Game::ChapterData> chapters;
	};
}
