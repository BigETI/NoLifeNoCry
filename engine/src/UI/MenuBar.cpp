#include <iostream>
#include <glm/common.hpp>
#include <UI/MenuBar.hpp>

DirtMachine::UI::MenuBar::MenuBar(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* menuItemTitleTextFont, unsigned int menuItemTitleTextCharacterSize, float menuItemTitleTextPadding, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Panel(position, rotation, size, parent),
	menuItemTitleTextFont(menuItemTitleTextFont),
	menuItemTitleTextCharacterSize(menuItemTitleTextCharacterSize),
	menuItemTitleTextPadding(menuItemTitleTextPadding)
{

}

DirtMachine::UI::MenuBar::~MenuBar()
{
	// ...
}

const DirtMachine::Graphic::Font* DirtMachine::UI::MenuBar::GetMenuItemTitleTextFont() const
{
	return menuItemTitleTextFont;
}

void DirtMachine::UI::MenuBar::SetMenuItemTitleTextFont(const DirtMachine::Graphic::Font* newMenuItemTitleTextFont)
{
	if (menuItemTitleTextFont != newMenuItemTitleTextFont)
	{
		for (std::shared_ptr<DirtMachine::UI::Button> menu_button : menuButtons)
		{
			menu_button->GetLabel().SetTextFont(menuItemTitleTextFont);
		}
		UpdateLayout();
	}
}

unsigned int DirtMachine::UI::MenuBar::GetMenuItemTitleTextCharacterSize() const
{
	return menuItemTitleTextCharacterSize;
}

void DirtMachine::UI::MenuBar::SetMenuItemTitleTextCharacterSize(unsigned int newMenuItemTitleTextCharacterSize)
{
	if (menuItemTitleTextCharacterSize != newMenuItemTitleTextCharacterSize)
	{
		menuItemTitleTextCharacterSize = newMenuItemTitleTextCharacterSize;
		for (std::shared_ptr<DirtMachine::UI::Button> menu_button : menuButtons)
		{
			menu_button->GetLabel().SetTextCharacterSize(menuItemTitleTextCharacterSize);
		}
		UpdateLayout();
	}
}

float DirtMachine::UI::MenuBar::GetMenuItemTitleTextPadding() const
{
	return menuItemTitleTextPadding;
}

void DirtMachine::UI::MenuBar::SetMenuItemTitleTextPadding(float newMenuItemTitleTextPadding)
{
	if (menuItemTitleTextPadding != newMenuItemTitleTextPadding)
	{
		menuItemTitleTextPadding = newMenuItemTitleTextPadding;
		UpdateLayout();
	}
}

std::shared_ptr<DirtMachine::UI::MenuButton> DirtMachine::UI::MenuBar::CreateMenuButton(const DirtMachine::String& title)
{
	std::shared_ptr<DirtMachine::UI::MenuButton> ret(CreateChild<DirtMachine::UI::MenuButton>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U), title, menuItemTitleTextFont, menuItemTitleTextCharacterSize, menuItemTitleTextPadding));
	menuButtons.push_back(ret);
	ret->OnMouseButtonReleased += [this, ret](const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
	{
		if (mouseButtonData.button == DirtMachine::Input::EMouseButton::Left)
		{
			for (std::shared_ptr<DirtMachine::UI::MenuButton> menu_button : menuButtons)
			{
				menu_button->GetContextMenu().SetVisibleState((menu_button == ret) && !(menu_button->GetContextMenu().IsVisible()));
			}
		}
	};
	UpdateLayout();
	return ret;
}

bool DirtMachine::UI::MenuBar::RemoveMenuButton(const std::shared_ptr<DirtMachine::UI::MenuButton> menuButton)
{
	bool ret(menuButtons.remove(menuButton) > 0ULL);
	if (ret)
	{
		UpdateLayout();
	}
	return ret;
}

void DirtMachine::UI::MenuBar::UpdateLayout()
{
	glm::ivec2 new_menu_button_position(0, 0);
	glm::uvec2 new_menu_button_size(0, static_cast<unsigned int>(glm::max(static_cast<float>(menuItemTitleTextCharacterSize) + (menuItemTitleTextPadding * 2.0f), 0.0f)));
	for (std::shared_ptr<DirtMachine::UI::Button> menu_button : menuButtons)
	{
		glm::vec2 last_menu_item_text_character_position(menu_button->GetLabel().FindTextCharacterPosition(menu_button->GetLabel().GetTextString().getSize()));
		new_menu_button_size.x = static_cast<unsigned int>(glm::max(last_menu_item_text_character_position.x + (menuItemTitleTextPadding * 2.0f), 0.0f));
		menu_button->SetLocalPosition(new_menu_button_position);
		menu_button->SetSize(new_menu_button_size);
		new_menu_button_position.x += static_cast<int>(new_menu_button_size.x);
	}
}
