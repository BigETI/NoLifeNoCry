#include <Page.hpp>

/// @brief Constructor
/// @param pageData 
/// @return 
NoLifeNoCry::Game::Page::Page(const NoLifeNoCry::Game::PageData& pageData) : sceneName(pageData.sceneName)
{
	// ...
}

/// @brief Get scene name
/// @return Scene name
const std::string& NoLifeNoCry::Game::Page::GetSceneName() const
{
	return sceneName;
}
