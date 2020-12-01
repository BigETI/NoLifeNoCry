#pragma once

#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <SaveGameData.hpp>
#include <Story.hpp>
#include <Chapter.hpp>
#include <Page.hpp>

/// @brief No Life, No Cry namespace
namespace NoLifeNoCry
{
	/// @brief Save game class
	class SaveGame
	{
	public:

		SaveGame() = delete;
		SaveGame(const SaveGame&) = delete;
		SaveGame(SaveGame&&) = delete;

		/// @brief Constructor
		/// @param saveGameFilePath Save game file path
		/// @param creationDateTime Creation date and time
		/// @param lastSavedDateTime Last saved date and time
		/// @param storyName Story name
		/// @param chapterIndex Chapter index
		/// @param pageIndex Page index
		/// @param variables Variables
		SaveGame(const std::filesystem::path& saveGameFilePath, const std::string& creationDateTime, const std::string lastSavedDateTime, const std::string& storyName, std::size_t chapterIndex, std::size_t pageIndex, const std::map<std::string, std::string>& variables);

		/// @brief Load save game
		/// @param saveGameFilePath Save game file path
		/// @return Save game if successful, otherwise "nullptr"
		static std::shared_ptr<SaveGame> Load(const std::filesystem::path& saveGameFilePath);

		/// @brief Load all save games
		/// @param saveGamesDirectoryPath Save games directory path
		/// @param result Result
		/// @return Save games
		static std::vector<std::shared_ptr<SaveGame>>& LoadAll(const std::filesystem::path& saveGamesDirectoryPath, std::vector<std::shared_ptr<SaveGame>>& result);

		/// @brief Get creation date and time
		/// @return Creation date and time
		const std::string& GetCreationDateTime() const;

		/// @brief Get last saved date and time
		/// @return Last saved date and time
		const std::string& GetLastSavedDateTime() const;

		/// @brief Get story name to access story from assets
		/// @return Story name
		const std::string& GetStoryName() const;

		/// @brief Get story
		/// @return Story
		const Story& GetStory() const;

		/// @brief Get story chapter
		/// @return Story chapter
		const Chapter& GetChapter() const;

		/// @brief Get page in story chapter
		/// @return Page in story chapter
		const Page& GetPage() const;

		/// @brief Save save game
		/// @return "true" if save game was successfully saved, otherwise "false"
		bool Save();

		/// @brief Save save game
		/// @param saveGameFilePath Save game file path
		/// @return "true" if save game was successfully saved, otherwise "false"
		bool Save(const std::filesystem::path& path);

		SaveGame& operator=(const SaveGame&) = delete;
		SaveGame& operator=(SaveGame&&) = delete;

	private:

		/// @brief Save game file path
		std::filesystem::path saveGameFilePath;

		/// @brief Save game data
		NoLifeNoCry::SaveGameData saveGameData;

		/// @brief Story
		NoLifeNoCry::Story story;

		/// @brief Chapter
		const NoLifeNoCry::Chapter* chapter;

		/// @brief page
		const NoLifeNoCry::Page* page;
	};
}
