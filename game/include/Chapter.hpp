#pragma once

#include <string>
#include <vector>
#include <Page.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	/// @brief Chapter class
	class Chapter
	{
	public:

		/// @brief Get Chapter name
		/// @return Chapter name
		const std::string& GetName() const;

		/// @brief Get chapter page count
		/// @return Chapter page count
		std::size_t GetPageCount() const;

		/// @brief Get chapter page
		/// @param chapterIndex Chapter index
		/// @return Chapter page
		const NoLifeNoCry::Game::Page& GetPage(std::size_t chapterIndex) const;

	private:

		/// @brief Chapter name
		std::string name;

		/// @brief Chapter pages
		std::vector<NoLifeNoCry::Game::Page> pages;
	};
}
