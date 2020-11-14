#include <filesystem>
#include <memory>
#include <Asset.hpp>
#include <Story.hpp>

/// @brief Default constructor
NoLifeNoCry::Game::Story::Story()
{
	// ...
}

/// @brief Copy constructor
/// @param story Story
NoLifeNoCry::Game::Story::Story(const NoLifeNoCry::Game::Story& story) : name(story.name), description(story.description), author(story.author), license(story.license)
{
	// ...
}

/// @brief Move constructor
/// @param story Story
NoLifeNoCry::Game::Story::Story(NoLifeNoCry::Game::Story&& story) noexcept : name(story.name), description(story.description), author(story.author), license(story.license)
{
	// ...
}

/// @brief Constructor
/// @param storyData Story data
NoLifeNoCry::Game::Story::Story(const NoLifeNoCry::Game::StoryData& storyData) : name(storyData.name), description(storyData.description), author(storyData.author), license(storyData.license)
{
	// ...
}

/// @brief Constructor
/// @param storyData Story data
NoLifeNoCry::Game::Story::Story(NoLifeNoCry::Game::StoryData&& storyData) : name(storyData.name), description(storyData.description), author(storyData.author), license(storyData.license)
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Game::Story::~Story()
{
	// ...
}

/// @brief Load story
/// @param storyName Story name
/// @return Story if successful, otherwise "nullptr"
std::shared_ptr<NoLifeNoCry::Game::Story> NoLifeNoCry::Game::Story::Load(const std::string& storyName)
{
	std::shared_ptr<NoLifeNoCry::Engine::Asset<StoryData>> story_asset(NoLifeNoCry::Engine::Asset<StoryData>::Load((std::filesystem::path("./assets/stories") / (storyName + ".xml")).string()));
	return story_asset ? std::make_shared<NoLifeNoCry::Game::Story>(story_asset->properties) : nullptr;
}

/// @brief Get story name
/// @return Story name
const std::string& NoLifeNoCry::Game::Story::GetName() const
{
	return name;
}

/// @brief Get description
/// @return Story description
const std::string& NoLifeNoCry::Game::Story::GetDescription() const
{
	return description;
}

/// @brief Get name of author
/// @return Name of author
const std::string& NoLifeNoCry::Game::Story::GetAuthor() const
{
	return author;
}

/// @brief Get license
/// @return License
const std::string& NoLifeNoCry::Game::Story::GetLicense() const
{
	return license;
}

/// @brief Get story chapter count
/// @return Story chapter count
std::size_t NoLifeNoCry::Game::Story::GetChapterCount() const
{
	return chapters.size();
}

/// @brief Get story chapter
/// @param chapterIndex Chapter index
/// @return Story chapter
const NoLifeNoCry::Game::Chapter& NoLifeNoCry::Game::Story::GetChapter(std::size_t chapterIndex) const
{
	return chapters[chapterIndex];
}

/// @brief Assign operator
/// @param story Story
/// @return Itself
NoLifeNoCry::Game::Story& NoLifeNoCry::Game::Story::operator=(const NoLifeNoCry::Game::Story& story)
{
	name = story.name;
	description = story.description;
	return *this;
}

/// @brief Assign operator
/// @param story Story
/// @return Itself
NoLifeNoCry::Game::Story& NoLifeNoCry::Game::Story::operator=(NoLifeNoCry::Game::Story&& story)
{
	name = story.name;
	description = story.description;
	return *this;
}

/// @brief Assign operator
/// @param storyData Story data
/// @return Itself
NoLifeNoCry::Game::Story& NoLifeNoCry::Game::Story::operator=(const NoLifeNoCry::Game::StoryData& storyData)
{
	name = storyData.name;
	description = storyData.description;
	return *this;
}

/// @brief Assign operator
/// @param storyData Story data
/// @return Itself
NoLifeNoCry::Game::Story& NoLifeNoCry::Game::Story::operator=(NoLifeNoCry::Game::StoryData&& storyData)
{
	name = storyData.name;
	description = storyData.description;
	return *this;
}
