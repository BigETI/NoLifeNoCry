#pragma once

#include <filesystem>
#include <memory>
#include <vector>
#include <UI/Button.hpp>
#include <UI/InputField.hpp>
#include <UI/Label.hpp>
#include <UI/TabListView.hpp>
#include <UI/TabListViewPage.hpp>

namespace DirtyFinger::UI
{
	class ProjectFilesTabListView : public DirtMachine::UI::TabListView
	{
	public:

		ProjectFilesTabListView(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* tabButtonLabelTextFont, unsigned int tabButtonLabelTextCharacterSize, float tabButtonLabelTextPadding, DirtMachine::UI::Control* parent);

		virtual ~ProjectFilesTabListView();

		std::filesystem::path GetProjectDirectoryPath();

		void SetProjectDirectoryPath(const std::filesystem::path& newProjectDirectoryPath);

	private:

		std::shared_ptr<DirtMachine::UI::TabListViewPage> assetsTabListViewPage;

		std::shared_ptr<DirtMachine::UI::TabListViewPage> sceneTabListViewPage;

		std::shared_ptr<DirtMachine::UI::InputField> directoryPathInputField;

		std::vector<std::shared_ptr<DirtMachine::UI::Button>> sceneFileButtons;
	};
}
