#include <UI/TabListViewPage.hpp>

DirtMachine::UI::TabListViewPage::TabListViewPage(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, std::shared_ptr<DirtMachine::UI::Button> tabListViewPageButton, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Panel(position, rotation, size, parent),
	tabListViewPageButton(tabListViewPageButton)
{
	SetVisibleState(isVisible);
}

DirtMachine::UI::TabListViewPage::~TabListViewPage()
{
	// ...
}

DirtMachine::String DirtMachine::UI::TabListViewPage::GetTitle() const
{
	return tabListViewPageButton->GetLabel().GetTextString();
}

void DirtMachine::UI::TabListViewPage::SetTitle(const DirtMachine::String& title)
{
	tabListViewPageButton->GetLabel().SetTextString(title);
}
