#pragma once

#include <rttr/registration.h>
#include <ChapterData.hpp>
#include <PageData.hpp>
#include <SaveGameData.hpp>
#include <StoryData.hpp>

/// @brief No Life, No Cry game namespace
namespace NoLifeNoCry::Game
{
	RTTR_REGISTRATION
	{
		rttr::registration::class_<NoLifeNoCry::Game::ChapterData>("Chapter")
			.constructor<>()
			.property("Name", &NoLifeNoCry::Game::ChapterData::name)
			.property("Description", &NoLifeNoCry::Game::ChapterData::description)
			.property("Pages", &NoLifeNoCry::Game::ChapterData::pages);
		rttr::registration::class_<NoLifeNoCry::Game::PageData>("Page")
			.constructor<>()
			.property("SceneName", &NoLifeNoCry::Game::PageData::sceneName);
		rttr::registration::class_<NoLifeNoCry::Game::SaveGameData>("SaveGame")
			.constructor<>()
			.property("CreationDateTime", &NoLifeNoCry::Game::SaveGameData::creationDateTime)
			.property("LastSavedDateTime", &NoLifeNoCry::Game::SaveGameData::lastSavedDateTime)
			.property("StoryName", &NoLifeNoCry::Game::SaveGameData::storyName)
			.property("ChapterIndex", &NoLifeNoCry::Game::SaveGameData::chapterIndex)
			.property("PageIndex", &NoLifeNoCry::Game::SaveGameData::pageIndex)
			.property("Variables", &NoLifeNoCry::Game::SaveGameData::variables);
		rttr::registration::class_<NoLifeNoCry::Game::StoryData>("SaveGames")
			.constructor<>()
			.property("Name", &NoLifeNoCry::Game::StoryData::name)
			.property("Description", &NoLifeNoCry::Game::StoryData::description)
			.property("Author", &NoLifeNoCry::Game::StoryData::author)
			.property("License", &NoLifeNoCry::Game::StoryData::license)
			.property("Chapters", &NoLifeNoCry::Game::StoryData::chapters);
	}
}
