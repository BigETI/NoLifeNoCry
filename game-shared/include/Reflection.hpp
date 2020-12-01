#pragma once

#include <rttr/registration.h>
#include <ChapterData.hpp>
#include <PageData.hpp>
#include <SaveGameData.hpp>
#include <StoryData.hpp>

/// @brief No Life, No Cry namespace
namespace NoLifeNoCry
{
	RTTR_REGISTRATION
	{
		rttr::registration::class_<NoLifeNoCry::ChapterData>("Chapter")
			.constructor<>()
			.property("Name", &NoLifeNoCry::ChapterData::name)
			.property("Description", &NoLifeNoCry::ChapterData::description)
			.property("Pages", &NoLifeNoCry::ChapterData::pages);
		rttr::registration::class_<NoLifeNoCry::PageData>("Page")
			.constructor<>()
			.property("SceneName", &NoLifeNoCry::PageData::sceneName);
		rttr::registration::class_<NoLifeNoCry::SaveGameData>("SaveGame")
			.constructor<>()
			.property("CreationDateTime", &NoLifeNoCry::SaveGameData::creationDateTime)
			.property("LastSavedDateTime", &NoLifeNoCry::SaveGameData::lastSavedDateTime)
			.property("StoryName", &NoLifeNoCry::SaveGameData::storyName)
			.property("ChapterIndex", &NoLifeNoCry::SaveGameData::chapterIndex)
			.property("PageIndex", &NoLifeNoCry::SaveGameData::pageIndex)
			.property("Variables", &NoLifeNoCry::SaveGameData::variables);
		rttr::registration::class_<NoLifeNoCry::StoryData>("SaveGames")
			.constructor<>()
			.property("Name", &NoLifeNoCry::StoryData::name)
			.property("Description", &NoLifeNoCry::StoryData::description)
			.property("Author", &NoLifeNoCry::StoryData::author)
			.property("License", &NoLifeNoCry::StoryData::license)
			.property("Chapters", &NoLifeNoCry::StoryData::chapters);
	}
}
