#include <chrono>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <rapidxml_utils.hpp>
#include <SaveGame.hpp>
#include <Serialiser/XMLSerialiser.hpp>
#include <Story.hpp>

/// @brief Constructor
/// @param saveGameFilePath Save game file path
/// @param creationDateTime Creation date and time
/// @param lastSavedDateTime Last saved date and time
/// @param storyName Story name
/// @param chapterIndex Chapter index
/// @param pageIndex Page index
/// @param variables Variables
NoLifeNoCry::SaveGame::SaveGame(const std::filesystem::path& saveGameFilePath, const std::string& creationDateTime, const std::string lastSavedDateTime, const std::string& storyName, std::size_t chapterIndex, std::size_t pageIndex, const std::map<std::string, std::string>& variables) : saveGameFilePath(saveGameFilePath), saveGameData({ creationDateTime, lastSavedDateTime, storyName, chapterIndex, pageIndex, variables }), chapter(nullptr), page(nullptr)
{
	std::shared_ptr<NoLifeNoCry::Story> loaded_story(Story::Load(storyName));
	if (!loaded_story)
	{
		std::stringstream message;
		message <<
			"Invalid story name \"" <<
			storyName <<
			"\".";
		throw std::invalid_argument(message.str());
	}
	story = *(loaded_story.get());
	if (chapterIndex < story.GetChapterCount())
	{
		std::stringstream message;
		message <<
			"Invalid chapter index \"" <<
			chapterIndex <<
			"\" at story \"" <<
			storyName <<
			"\".";
		throw std::invalid_argument(message.str());
	}
	chapter = &(story.GetChapter(chapterIndex));
	if (pageIndex < chapter->GetPageCount())
	{
		std::stringstream message;
		message <<
			"Invalid page index \"" <<
			pageIndex <<
			"\" at chapter index \"" <<
			chapterIndex <<
			"\" at story \"" <<
			storyName <<
			"\".";
		throw std::invalid_argument(message.str());
	}
	page = &(chapter->GetPage(pageIndex));
}

/// @brief Load save game
/// @param saveGameFilePath Save game file path
/// @return Save game if successful, otherwise "nullptr"
std::shared_ptr<NoLifeNoCry::SaveGame> NoLifeNoCry::SaveGame::Load(const std::filesystem::path& saveGameFilePath)
{
	std::shared_ptr<NoLifeNoCry::SaveGame> ret(nullptr);
	try
	{
		if (std::filesystem::is_block_file(saveGameFilePath) ||
			std::filesystem::is_character_file(saveGameFilePath) ||
			std::filesystem::is_regular_file(saveGameFilePath))
		{
			std::string save_game_path(saveGameFilePath.string());
			rapidxml::file<> xml_file(save_game_path.c_str());
			rapidxml::xml_document<> xml_document;
			xml_document.parse<0>(xml_file.data());
			std::shared_ptr<NoLifeNoCry::SaveGameData> save_game_data(DirtMachine::Serialiser::XMLSerialiser<NoLifeNoCry::SaveGameData>().DeserialiseObject(&xml_document));
			if (save_game_data)
			{
				ret = std::make_shared<NoLifeNoCry::SaveGame>(saveGameFilePath, save_game_data->creationDateTime, save_game_data->lastSavedDateTime, save_game_data->storyName, save_game_data->chapterIndex, save_game_data->pageIndex, save_game_data->variables);
			}
		}
	}
	catch (const std::exception e)
	{
		std::cerr << "Failed to load save game \"" << saveGameFilePath << "\"" << std::endl <<
			e.what() << std::endl;
	}
	catch (int e)
	{
		std::cerr << "Failed to load save game \"" << saveGameFilePath << "\"" << std::endl <<
			"Error code: " << e << std::endl;
	}
	catch (...)
	{
		std::cerr << "Failed to load save game \"" << saveGameFilePath << "\"" << std::endl <<
			"An unknown error has occured. :(" << std::endl;
	}
	return ret;
}

/// @brief Load all save games
/// @param saveGamesDirectoryPath Save games directory path
/// @param result Result
/// @return Save games
std::vector<std::shared_ptr<NoLifeNoCry::SaveGame>>& NoLifeNoCry::SaveGame::LoadAll(const std::filesystem::path& saveGamesDirectoryPath, std::vector<std::shared_ptr<NoLifeNoCry::SaveGame>>& result)
{
	result.clear();
	for (const std::filesystem::path& save_game_file_path : saveGamesDirectoryPath)
	{
		if (std::filesystem::is_block_file(save_game_file_path) ||
			std::filesystem::is_character_file(save_game_file_path) ||
			std::filesystem::is_regular_file(save_game_file_path))
		{
			std::shared_ptr<NoLifeNoCry::SaveGame> save_game(Load(save_game_file_path));
			if (save_game)
			{
				result.push_back(save_game);
			}
		}
	}
	return result;
}

/// @brief Get creation date and time
/// @return Creation date and time
const std::string& NoLifeNoCry::SaveGame::GetCreationDateTime() const
{
	return saveGameData.creationDateTime;
}

/// @brief Get last saved date and time
/// @return Last saved date and time
const std::string& NoLifeNoCry::SaveGame::GetLastSavedDateTime() const
{
	return saveGameData.lastSavedDateTime;
}

/// @brief Get story name to access story from assets
/// @return Story name
const std::string& NoLifeNoCry::SaveGame::GetStoryName() const
{
	return saveGameData.storyName;
}

/// @brief Get story
/// @return Story
const NoLifeNoCry::Story& NoLifeNoCry::SaveGame::GetStory() const
{
	return story;
}

/// @brief Get story chapter
/// @return Story chapter
const NoLifeNoCry::Chapter& NoLifeNoCry::SaveGame::GetChapter() const
{
	return *chapter;
}

/// @brief Get page in story chapter
/// @return Page in story chapter
const NoLifeNoCry::Page& NoLifeNoCry::SaveGame::GetPage() const
{
	return *page;
}

/// @brief Save save game
/// @return "true" if save game was successfully saved, otherwise "false"
bool NoLifeNoCry::SaveGame::Save()
{
	return Save(saveGameFilePath);
}

/// @brief Save save game
/// @param path Save game file path
/// @return "true" if save game was successfully saved, otherwise "false"
bool NoLifeNoCry::SaveGame::Save(const std::filesystem::path& path)
{
	bool ret(false);
	try
	{
		bool does_directory_exist(true);
		if (path.has_root_directory())
		{
			std::filesystem::path directory_path(path.root_directory());
			if (!(std::filesystem::is_directory(directory_path)))
			{
				does_directory_exist = std::filesystem::create_directories(directory_path);
			}
		}
		if (does_directory_exist)
		{
			std::shared_ptr<rapidxml::xml_document<>> xml_document(DirtMachine::Serialiser::XMLSerialiser<SaveGameData>().SerialiseObject(saveGameData));
			if (xml_document)
			{
				std::ofstream output_file_stream(path);
				if (output_file_stream.is_open())
				{
					output_file_stream << *(xml_document.get());
					ret = true;
				}
			}
		}
	}
	catch (const std::exception e)
	{
		std::cerr << "Failed to save save game \"" << path << "\"" << std::endl <<
			e.what() << std::endl;
	}
	catch (int e)
	{
		std::cerr << "Failed to save save game \"" << path << "\"" << std::endl <<
			"Error code: " << e << std::endl;
	}
	catch (...)
	{
		std::cerr << "Failed to save save game \"" << path << "\"" << std::endl <<
			"An unknown error has occured. :(" << std::endl;
	}
	return ret;
}
