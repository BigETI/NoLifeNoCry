#include <glm/common.hpp>
#include <Input/Data/MouseButtonData.hpp>
#include <Input/EMouseButton.hpp>
#include <UI/ContextMenu.hpp>
#include <UI/ETextAlignment.hpp>

DirtMachine::UI::ContextMenu::ContextMenu(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* menuItemTitleTextFont, unsigned int menuItemTitleTextCharacterSize, float menuItemTitleTextPadding, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Panel(position, rotation, size, parent),
	menuItemTitleTextFont(menuItemTitleTextFont),
	menuItemTitleTextCharacterSize(menuItemTitleTextCharacterSize),
	menuItemTitleTextPadding(menuItemTitleTextPadding)
{
	// ...
}

DirtMachine::UI::ContextMenu::~ContextMenu()
{
	// ...
}

const DirtMachine::Graphic::Font* DirtMachine::UI::ContextMenu::GetMenuItemTitleTextFont() const
{
	return menuItemTitleTextFont;
}

void DirtMachine::UI::ContextMenu::SetMenuItemTitleTextFont(const DirtMachine::Graphic::Font* newMenuItemTitleTextFont)
{
	if (menuItemTitleTextFont != newMenuItemTitleTextFont)
	{
		menuItemTitleTextFont = newMenuItemTitleTextFont;
		for (std::shared_ptr<DirtMachine::UI::Button> menu_item : menuItems)
		{
			menu_item->GetLabel().SetTextFont(menuItemTitleTextFont);
		}
		UpdateLayout();
	}
}

unsigned int DirtMachine::UI::ContextMenu::GetMenuItemTitleTextCharacterSize() const
{
	return menuItemTitleTextCharacterSize;
}

void DirtMachine::UI::ContextMenu::SetMenuItemTitleTextCharacterSize(unsigned int newMenuItemTitleTextCharacterSize)
{
	if (menuItemTitleTextCharacterSize != newMenuItemTitleTextCharacterSize)
	{
		menuItemTitleTextCharacterSize = newMenuItemTitleTextCharacterSize;
		for (std::shared_ptr<DirtMachine::UI::Button> menu_item : menuItems)
		{
			menu_item->GetLabel().SetTextCharacterSize(menuItemTitleTextCharacterSize);
		}
		UpdateLayout();
	}
}

float DirtMachine::UI::ContextMenu::GetMenuItemTitleTextPadding() const
{
	return menuItemTitleTextPadding;
}

void DirtMachine::UI::ContextMenu::SetMenuItemTitleTextPadding(float newMenuItemTitleTextPadding)
{
	if (menuItemTitleTextPadding != newMenuItemTitleTextPadding)
	{
		menuItemTitleTextPadding = newMenuItemTitleTextPadding;
		UpdateLayout();
	}
}

std::shared_ptr<DirtMachine::UI::Button> DirtMachine::UI::ContextMenu::CreateMenuItem(const DirtMachine::String& title)
{
	std::shared_ptr<DirtMachine::UI::Button> ret(CreateChild<DirtMachine::UI::Button>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U), title, menuItemTitleTextFont, menuItemTitleTextCharacterSize));
	menuItems.push_back(ret);
	ret->GetLabel().SetTextAlignment(DirtMachine::UI::ETextAlignment::CenterLeft);
	ret->OnMouseButtonReleased += [this](const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
	{
		if (mouseButtonData.button == DirtMachine::Input::EMouseButton::Left)
		{
			SetVisibleState(false);
		}
	};
	UpdateLayout();
	return ret;
}

bool DirtMachine::UI::ContextMenu::RemoveMenuItem(const std::shared_ptr<DirtMachine::UI::Button> menuItem)
{
	bool ret(menuItems.remove(menuItem) > 0ULL);
	if (ret)
	{
		UpdateLayout();
	}
	return ret;
}

void DirtMachine::UI::ContextMenu::UpdateLayout()
{
	glm::uvec2 new_menu_item_size(0U, static_cast<unsigned int>(glm::max(static_cast<float>(menuItemTitleTextCharacterSize) + (menuItemTitleTextPadding * 2.0f), 0.0f)));
	glm::uvec2 new_size(0U, new_menu_item_size.y * static_cast<unsigned int>(menuItems.size()));
	glm::ivec2 new_menu_item_position(static_cast<int>(menuItemTitleTextPadding), 0);
	for (std::shared_ptr<DirtMachine::UI::Button> menu_item : menuItems)
	{
		glm::vec2 last_menu_item_text_character_position(menu_item->GetLabel().FindTextCharacterPosition(menu_item->GetLabel().GetTextString().getSize()));
		unsigned int width = static_cast<unsigned int>(glm::max(last_menu_item_text_character_position.x + (menuItemTitleTextPadding * 2.0f), 0.0f));
		if (new_menu_item_size.x < width)
		{
			new_menu_item_size.x = width;
			new_size.x = width;
		}
		menu_item->SetLocalPosition(new_menu_item_position);
		new_menu_item_position.y += static_cast<int>(new_menu_item_size.y);
	}
	SetSize(new_size);
	for (std::shared_ptr<DirtMachine::UI::Button> menu_item : menuItems)
	{
		menu_item->SetSize(new_menu_item_size);
	}
}
