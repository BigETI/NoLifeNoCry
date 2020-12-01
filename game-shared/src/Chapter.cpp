#include <Chapter.hpp>

/// @brief Get Chapter name
/// @return Chapter name
const std::string& NoLifeNoCry::Chapter::GetName() const
{
	return name;
}

/// @brief Get chapter page count
/// @return Chapter page count
std::size_t NoLifeNoCry::Chapter::GetPageCount() const
{
	return pages.size();
}

/// @brief Get chapter page
/// @param chapterIndex Chapter index
/// @return Chapter page
const NoLifeNoCry::Page& NoLifeNoCry::Chapter::GetPage(std::size_t chapterIndex) const
{
	return pages[chapterIndex];
}
