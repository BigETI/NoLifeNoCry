#pragma once

#include <list>
#include <memory>
#include <String.hpp>
#include <UI/Control.hpp>
#include <UI/MenuButton.hpp>
#include <UI/Panel.hpp>

namespace DirtMachine::UI
{
	class MenuBar : public DirtMachine::UI::Panel
	{
	public:

		MenuBar() = delete;
		MenuBar(const DirtMachine::UI::MenuBar&) = delete;
		MenuBar(DirtMachine::UI::MenuBar&&) = delete;

		MenuBar(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* menuItemTitleTextFont, unsigned int menuItemTitleTextCharacterSize, float menuItemTitleTextPadding, DirtMachine::UI::Control* parent);

		virtual ~MenuBar();

		virtual const DirtMachine::Graphic::Font* GetMenuItemTitleTextFont() const;

		virtual void SetMenuItemTitleTextFont(const DirtMachine::Graphic::Font* newMenuItemTitleTextFont);

		virtual unsigned int GetMenuItemTitleTextCharacterSize() const;

		virtual void SetMenuItemTitleTextCharacterSize(unsigned int newMenuItemTitleTextCharacterSize);

		virtual float GetMenuItemTitleTextPadding() const;

		virtual void SetMenuItemTitleTextPadding(float newMenuItemTitleTextPadding);

		virtual std::shared_ptr<DirtMachine::UI::MenuButton> CreateMenuButton(const DirtMachine::String& title);

		virtual bool RemoveMenuButton(const std::shared_ptr<DirtMachine::UI::MenuButton> menuButton);

		DirtMachine::UI::MenuBar& operator = (const DirtMachine::UI::MenuBar&) = delete;
		DirtMachine::UI::MenuBar& operator = (DirtMachine::UI::MenuBar&&) = delete;

	private:

		const DirtMachine::Graphic::Font* menuItemTitleTextFont;

		unsigned int menuItemTitleTextCharacterSize;

		float menuItemTitleTextPadding;

		std::list<std::shared_ptr<DirtMachine::UI::MenuButton>> menuButtons;

		void UpdateLayout();
	};
}
