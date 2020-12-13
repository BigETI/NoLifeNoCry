#include <filesystem>
#include <UI/ProjectFilesTabListView.hpp>

DirtyFinger::UI::ProjectFilesTabListView::ProjectFilesTabListView(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* tabButtonLabelTextFont, unsigned int tabButtonLabelTextCharacterSize, float tabButtonLabelTextPadding, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::TabListView(position, rotation, size, tabButtonLabelTextFont, tabButtonLabelTextCharacterSize, tabButtonLabelTextPadding, parent)
{
	assetsTabListViewPage = CreatePage("Assets");
	sceneTabListViewPage = CreatePage("Scenes");
	float label_height(static_cast<float>(tabButtonLabelTextCharacterSize) + (tabButtonLabelTextPadding * 2.0f));
	assetsTabListViewPage->CreateChild<DirtMachine::UI::Label>(glm::ivec2(static_cast<int>(tabButtonLabelTextPadding), 0), 0.0f, glm::uvec2(size.x, static_cast<unsigned int>(label_height)), "Assets path", tabButtonLabelTextFont, tabButtonLabelTextCharacterSize, DirtMachine::UI::ETextAlignment::CenterLeft);
	directoryPathInputField = assetsTabListViewPage->CreateChild<DirtMachine::UI::InputField>(glm::ivec2(static_cast<int>(tabButtonLabelTextPadding), static_cast<int>(label_height)), 0.0f, glm::uvec2(size.x, static_cast<unsigned int>(label_height)), DirtMachine::String(), "Please specify a project path...", tabButtonLabelTextFont, tabButtonLabelTextCharacterSize, false);
	directoryPathInputField->OnTextStringChanged += [this](const DirtMachine::String& string)
	{
		std::filesystem::path project_directory_path(string);
		if (std::filesystem::is_directory(project_directory_path))
		{
			// TODO: List directories
		}
	};
	directoryPathInputField->InsertTextIntoSelection("./assets");
}

DirtyFinger::UI::ProjectFilesTabListView::~ProjectFilesTabListView()
{
	// ...
}

std::filesystem::path DirtyFinger::UI::ProjectFilesTabListView::GetProjectDirectoryPath()
{
	return static_cast<std::filesystem::path>(directoryPathInputField->GetText());
}

void DirtyFinger::UI::ProjectFilesTabListView::SetProjectDirectoryPath(const std::filesystem::path& newProjectDirectoryPath)
{
	directoryPathInputField->SetText(DirtMachine::String(newProjectDirectoryPath));
}
