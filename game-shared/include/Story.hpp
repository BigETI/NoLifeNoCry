#pragma once

#include <string>
#include <Chapter.hpp>
#include <StoryData.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	/// @brief Story class
	class Story
	{
	public:

		/// @brief Default constructor
		Story();

		/// @brief Copy constructor
		/// @param story Story
		Story(const Story& story);

		/// @brief Move constructor
		/// @param story Story
		Story(Story&& story) noexcept;
		
		/// @brief Constructor
		/// @param storyData Story data
		Story(const StoryData& storyData);

		/// @brief Constructor
		/// @param storyData Story data
		Story(StoryData&& storyData);

		/// @brief Destructor
		~Story();

		/// @brief Load story
		/// @param storyName Story name
		/// @return Story if successful, otherwise "nullptr"
		static std::shared_ptr<Story> Load(const std::string& storyName);

		/// @brief Get story name
		/// @return Story name
		const std::string& GetName() const;

		/// @brief Get description
		/// @return Story description
		const std::string& GetDescription() const;

		/// @brief Get name of author
		/// @return Name of author
		const std::string& GetAuthor() const;

		/// @brief Get license
		/// @return License
		const std::string& GetLicense() const;

		/// @brief Get story chapter count
		/// @return Story chapter count
		std::size_t GetChapterCount() const;

		/// @brief Get story chapter
		/// @param chapterIndex Chapter index
		/// @return Story chapter
		const NoLifeNoCry::Game::Chapter& GetChapter(std::size_t chapterIndex) const;

		/// @brief Assign operator
		/// @param story Story
		/// @return Itself
		Story& operator=(const Story& story);

		/// @brief Assign operator
		/// @param story Story
		/// @return Itself
		Story& operator=(Story&& story);

		/// @brief Assign operator
		/// @param storyData Story data
		/// @return Itself
		Story& operator=(const StoryData& storyData);

		/// @brief Assign operator
		/// @param storyData Story data
		/// @return Itself
		Story& operator=(StoryData&& storyData);

	private:

		/// @brief Story name
		std::string name;

		/// @brief Story description
		std::string description;

		/// @brief Author name
		std::string author;

		/// @brief License
		std::string license;

		/// @brief Story chapter
		std::vector<NoLifeNoCry::Game::Chapter> chapters;
	};
}
