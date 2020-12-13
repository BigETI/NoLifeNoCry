#include <glm/common.hpp>
#include <UI/TabListView.hpp>

DirtMachine::UI::TabListView::TabListView(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* tabButtonLabelTextFont, unsigned int tabButtonLabelTextCharacterSize, float tabButtonLabelTextPadding, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Panel(position, rotation, size, parent),
	tabButtonLabelTextFont(tabButtonLabelTextFont),
	tabButtonLabelTextCharacterSize(tabButtonLabelTextCharacterSize),
	tabButtonLabelTextPadding(tabButtonLabelTextPadding)
{
	buttonsPanel = CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U));
	viewPanel = CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, GetSize());
	OnTransformationChanged += [this]()
	{
		UpdateLayout();
	};
	buttonsPanel->OnTransformationChanged += [this]()
	{
		glm::uvec2 current_size(GetSize());
		glm::uvec2 buttons_panel_size(buttonsPanel->GetSize());
		viewPanel->SetLocalPosition(glm::ivec2(0, buttons_panel_size.y));
		viewPanel->SetSize(glm::uvec2(current_size.x, static_cast<unsigned int>(glm::max(static_cast<int>(current_size.y) - static_cast<int>(buttons_panel_size.y), 0))));
	};
	viewPanel->OnTransformationChanged += [this]()
	{
		glm::uvec2 view_panel_size(viewPanel->GetSize());
		for (std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>> page : pages)
		{
			std::get<0>(page)->SetSize(view_panel_size);
		}
	};
}

DirtMachine::UI::TabListView::~TabListView()
{
	// ...
}

const DirtMachine::Graphic::Font* DirtMachine::UI::TabListView::GetTabButtonLabelTextFont() const
{
	return tabButtonLabelTextFont;
}

void DirtMachine::UI::TabListView::SetTabButtonLabelTextFont(const DirtMachine::Graphic::Font* newTabButtonLabelTextFont)
{
	if (tabButtonLabelTextFont != newTabButtonLabelTextFont)
	{
		tabButtonLabelTextFont = newTabButtonLabelTextFont;
		for (std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>> page : pages)
		{
			std::get<1>(page)->GetLabel().SetTextFont(tabButtonLabelTextFont);
		}
		UpdateLayout();
	}
}

unsigned int DirtMachine::UI::TabListView::GetTabButtonLabelTextCharacterSize() const
{
	return tabButtonLabelTextCharacterSize;
}

void DirtMachine::UI::TabListView::SetTabButtonLabelTextCharacterSize(unsigned int newTabButtonLabelTextCharacterSize)
{
	if (tabButtonLabelTextCharacterSize != newTabButtonLabelTextCharacterSize)
	{
		tabButtonLabelTextCharacterSize = newTabButtonLabelTextCharacterSize;
		for (std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>> page : pages)
		{
			std::get<1>(page)->GetLabel().SetTextCharacterSize(tabButtonLabelTextCharacterSize);
		}
		UpdateLayout();
	}
}

float DirtMachine::UI::TabListView::GetTabButtonLabelTextPadding() const
{
	return tabButtonLabelTextPadding;
}

void DirtMachine::UI::TabListView::SetTabButtonLabelTextPadding(float newTabButtonLabelTextPadding)
{
	if (tabButtonLabelTextPadding != newTabButtonLabelTextPadding)
	{
		tabButtonLabelTextPadding = newTabButtonLabelTextPadding;
		UpdateLayout();
	}
}

DirtMachine::UI::Panel& DirtMachine::UI::TabListView::GetButtonsPanel()
{
	return *buttonsPanel;
}

const DirtMachine::UI::Panel& DirtMachine::UI::TabListView::GetButtonsPanel() const
{
	return *buttonsPanel;
}

std::shared_ptr<DirtMachine::UI::TabListViewPage> DirtMachine::UI::TabListView::CreatePage(const DirtMachine::String& tabListViewPageTitle)
{
	std::shared_ptr<DirtMachine::UI::Button> tab_list_view_page_button(buttonsPanel->CreateChild<DirtMachine::UI::Button>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U), tabListViewPageTitle, tabButtonLabelTextFont, tabButtonLabelTextCharacterSize));
	std::shared_ptr<DirtMachine::UI::TabListViewPage> ret(viewPanel->CreateChild<DirtMachine::UI::TabListViewPage>(glm::ivec2(0, 0), 0.0f, viewPanel->GetSize(), pages.size() == static_cast<std::size_t>(0), tab_list_view_page_button));
	pages.push_back(std::make_tuple(ret, tab_list_view_page_button));
	tab_list_view_page_button->OnMouseButtonPressed += [this, ret](DirtMachine::Input::Data::MouseButtonData mouseButtonData)
	{
		if (mouseButtonData.button == DirtMachine::Input::EMouseButton::Left)
		{
			ShowPage(ret);
		}
	};
	UpdateLayout();
	return ret;
}

bool DirtMachine::UI::TabListView::RemovePage(const std::shared_ptr<DirtMachine::UI::TabListViewPage> tabListViewPage)
{
	bool ret(false);
	for (std::list<std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>>>::const_iterator iterator(pages.begin()), end(pages.end()); iterator != end; iterator++)
	{
		if (std::get<0>(*iterator) == tabListViewPage)
		{
			pages.erase(iterator);
			ret = true;
			UpdateLayout();
			break;
		}
	}
	return ret;
}

bool DirtMachine::UI::TabListView::ShowPage(const std::shared_ptr<DirtMachine::UI::TabListViewPage> tabListViewPage)
{
	bool ret(false);
	for (std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>>& page : pages)
	{
		std::shared_ptr<DirtMachine::UI::TabListViewPage>& tab_list_view_page(std::get<0>(page));
		bool is_visible(tab_list_view_page == tabListViewPage);
		tab_list_view_page->SetVisibleState(is_visible);
		ret = ret || is_visible;
	}
	return ret;
}

void DirtMachine::UI::TabListView::UpdateLayout()
{
	glm::uvec2 buttons_panel_size(GetSize().x, 0U);
	glm::ivec2 button_position(0, 0);
	int remaining_width(static_cast<int>(buttons_panel_size.x));
	bool is_first(true);
	for (std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>> page : pages)
	{
		DirtMachine::UI::Button& tab_list_view_page_button(*std::get<1>(page));
		glm::vec2 last_tab_list_view_page_button_text_character_position(tab_list_view_page_button.GetLabel().FindTextCharacterPosition(tab_list_view_page_button.GetLabel().GetTextString().getSize()));
		glm::uvec2 tab_list_view_page_button_size(static_cast<unsigned int>(glm::max(last_tab_list_view_page_button_text_character_position.x + (tabButtonLabelTextPadding * 2.0f), 0.0f)), static_cast<unsigned int>(glm::max(last_tab_list_view_page_button_text_character_position.y + static_cast<float>(tabButtonLabelTextCharacterSize) + (tabButtonLabelTextPadding * 2.0f), 0.0f)));
		tab_list_view_page_button.SetLocalPosition(button_position);
		tab_list_view_page_button.SetSize(tab_list_view_page_button_size);
		button_position.x += static_cast<int>(tab_list_view_page_button_size.x);
		remaining_width -= static_cast<int>(tab_list_view_page_button_size.x);
		if (is_first)
		{
			buttons_panel_size.y = tab_list_view_page_button_size.y;
			is_first = false;
		}
		if (remaining_width <= 0)
		{
			remaining_width = static_cast<int>(buttons_panel_size.x);
			button_position = glm::ivec2(0, static_cast<int>(buttons_panel_size.y));
			buttons_panel_size.y += tab_list_view_page_button_size.y;
		}
	}
	buttonsPanel->SetSize(buttons_panel_size);
}
