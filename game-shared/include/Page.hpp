#pragma once

#include <string>
#include <PageData.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	/// @brief Page class
	class Page
	{
	public:

		Page() = delete;
		Page(const Page&) = delete;
		Page(Page&&) = delete;

		/// @brief Constructor
		/// @param pageData 
		/// @return 
		Page(const NoLifeNoCry::Game::PageData& pageData);

		/// @brief Get scene name
		/// @return Scene name
		const std::string& GetSceneName() const;

	private:

		/// @brief Scene name
		std::string sceneName;
	};
}
