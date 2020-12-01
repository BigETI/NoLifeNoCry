#include <filesystem>
#include <memory>
#include <Serialiser/Asset.hpp>
#include <Story.hpp>

/// @brief Default constructor
NoLifeNoCry::Story::Story()
{
	// ...
}

/// @brief Copy constructor
/// @param story Story
NoLifeNoCry::Story::Story(const NoLifeNoCry::Story& story) : name(story.name), description(story.description), author(story.author), license(story.license)
{
	// ...
}

/// @brief Move constructor
/// @param story Story
NoLifeNoCry::Story::Story(NoLifeNoCry::Story&& story) noexcept : name(story.name), description(story.description), author(story.author), license(story.license)
{
	// ...
}

/// @brief Constructor
/// @param storyData Story data
NoLifeNoCry::Story::Story(const NoLifeNoCry::StoryData& storyData) : name(storyData.name), description(storyData.description), author(storyData.author), license(storyData.license)
{
	// ...
}

/// @brief Constructor
/// @param storyData Story data
NoLifeNoCry::Story::Story(NoLifeNoCry::StoryData&& storyData) : name(storyData.name), description(storyData.description), author(storyData.author), license(storyData.license)
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Story::~Story()
{
	// ...
}

/// @brief Load story
/// @param storyName Story name
/// @return Story if successful, otherwise "nullptr"
std::shared_ptr<NoLifeNoCry::Story> NoLifeNoCry::Story::Load(const std::string& storyName)
{
	std::shared_ptr<DirtMachine::Serialiser::Asset<StoryData>> story_asset(DirtMachine::Serialiser::Asset<NoLifeNoCry::StoryData>::Load((std::filesystem::path("./assets/stories") / (storyName + ".xml")).string()));
	return story_asset ? std::make_shared<NoLifeNoCry::Story>(story_asset->properties) : nullptr;
}

/// @brief Get story name
/// @return Story name
const std::string& NoLifeNoCry::Story::GetName() const
{
	return name;
}

/// @brief Get description
/// @return Story description
const std::string& NoLifeNoCry::Story::GetDescription() const
{
	return description;
}

/// @brief Get name of author
/// @return Name of author
const std::string& NoLifeNoCry::Story::GetAuthor() const
{
	return author;
}

/// @brief Get license
/// @return License
const std::string& NoLifeNoCry::Story::GetLicense() const
{
	return license;
}

/// @brief Get story chapter count
/// @return Story chapter count
std::size_t NoLifeNoCry::Story::GetChapterCount() const
{
	return chapters.size();
}

/// @brief Get story chapter
/// @param chapterIndex Chapter index
/// @return Story chapter
const NoLifeNoCry::Chapter& NoLifeNoCry::Story::GetChapter(std::size_t chapterIndex) const
{
	return chapters[chapterIndex];
}

/// @brief Assign operator
/// @param story Story
/// @return Itself
NoLifeNoCry::Story& NoLifeNoCry::Story::operator=(const NoLifeNoCry::Story& story)
{
	name = story.name;
	description = story.description;
	return *this;
}

/// @brief Assign operator
/// @param story Story
/// @return Itself
NoLifeNoCry::Story& NoLifeNoCry::Story::operator=(NoLifeNoCry::Story&& story)
{
	name = story.name;
	description = story.description;
	return *this;
}

/// @brief Assign operator
/// @param storyData Story data
/// @return Itself
NoLifeNoCry::Story& NoLifeNoCry::Story::operator=(const NoLifeNoCry::StoryData& storyData)
{
	name = storyData.name;
	description = storyData.description;
	return *this;
}

/// @brief Assign operator
/// @param storyData Story data
/// @return Itself
NoLifeNoCry::Story& NoLifeNoCry::Story::operator=(NoLifeNoCry::StoryData&& storyData)
{
	name = storyData.name;
	description = storyData.description;
	return *this;
}
