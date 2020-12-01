#include <Page.hpp>

/// @brief Constructor
/// @param pageData 
/// @return 
NoLifeNoCry::Page::Page(const NoLifeNoCry::PageData& pageData) : sceneName(pageData.sceneName)
{
	// ...
}

/// @brief Get scene name
/// @return Scene name
const std::string& NoLifeNoCry::Page::GetSceneName() const
{
	return sceneName;
}
