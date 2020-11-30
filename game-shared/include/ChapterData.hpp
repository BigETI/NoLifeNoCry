#pragma once

#include <string>
#include <vector>
#include <rttr/registration.h>
#include <PageData.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	/// @brief Chapter data structure
	struct ChapterData
	{
		/// @brief Chapter name
		std::string name;

		/// @brief Chapter desciption
		std::string description;

		/// @brief Pages
		std::vector<NoLifeNoCry::Game::PageData> pages;
	};
}
