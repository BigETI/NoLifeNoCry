#pragma once

#include <string>
#include <PageData.hpp>

/// @brief No Life, No Cry namespace
namespace NoLifeNoCry
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
		Page(const NoLifeNoCry::PageData& pageData);

		/// @brief Get scene name
		/// @return Scene name
		const std::string& GetSceneName() const;

	private:

		/// @brief Scene name
		std::string sceneName;
	};
}
