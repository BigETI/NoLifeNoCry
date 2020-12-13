#pragma once

#include <list>
#include <memory>
#include <String.hpp>
#include <Graphic/Font.hpp>
#include <UI/Button.hpp>
#include <UI/Control.hpp>
#include <UI/Panel.hpp>

namespace DirtMachine::UI
{
	class ContextMenu : public DirtMachine::UI::Panel
	{
	public:

		ContextMenu() = delete;
		ContextMenu(const DirtMachine::UI::ContextMenu&) = delete;
		ContextMenu(DirtMachine::UI::ContextMenu&&) = delete;

		ContextMenu(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* menuItemTitleTextFont, unsigned int menuItemTitleTextCharacterSize, float menuItemTitleTextPadding, DirtMachine::UI::Control* parent);

		virtual ~ContextMenu();

		virtual const DirtMachine::Graphic::Font* GetMenuItemTitleTextFont() const;

		virtual void SetMenuItemTitleTextFont(const DirtMachine::Graphic::Font* newMenuItemTitleTextFont);

		virtual unsigned int GetMenuItemTitleTextCharacterSize() const;

		virtual void SetMenuItemTitleTextCharacterSize(unsigned int newMenuItemTitleTextCharacterSize);

		virtual float GetMenuItemTitleTextPadding() const;

		virtual void SetMenuItemTitleTextPadding(float newMenuItemTitleTextPadding);

		virtual std::shared_ptr<DirtMachine::UI::Button> CreateMenuItem(const DirtMachine::String& title);

		virtual bool RemoveMenuItem(const std::shared_ptr<DirtMachine::UI::Button> menuItem);

		DirtMachine::UI::ContextMenu& operator = (const DirtMachine::UI::ContextMenu&) = delete;
		DirtMachine::UI::ContextMenu& operator = (DirtMachine::UI::ContextMenu&&) = delete;

	private:
		
		const DirtMachine::Graphic::Font* menuItemTitleTextFont;
		
		unsigned int menuItemTitleTextCharacterSize;

		float menuItemTitleTextPadding;

		std::list<std::shared_ptr<DirtMachine::UI::Button>> menuItems;

		void UpdateLayout();
	};
}
