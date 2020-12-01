#pragma once

#include <map>
#include <string>

/// @brief No Life, No Cry namespace
namespace NoLifeNoCry
{
	/// @brief Save game data structure
	struct SaveGameData
	{
		/// @brief Creation date and time
		std::string creationDateTime;

		/// @brief Last saved date and time
		std::string lastSavedDateTime;

		/// @brief Story name
		std::string storyName;

		/// @brief Chapter index
		std::size_t chapterIndex = static_cast<std::size_t>(0);

		/// @brief Page index
		std::size_t pageIndex = static_cast<std::size_t>(0);

		/// @brief Variables
		std::map<std::string, std::string> variables;
	};
}
