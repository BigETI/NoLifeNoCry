#pragma once

#include <UI/Button.hpp>
#include <UI/ContextMenu.hpp>

namespace DirtMachine::UI
{
	class MenuButton : public DirtMachine::UI::Button
	{
	public:

		MenuButton() = delete;
		MenuButton(const DirtMachine::UI::MenuButton&) = delete;
		MenuButton(DirtMachine::UI::MenuButton&&) = delete;

		MenuButton(const glm::ivec2& position, float roation, const glm::uvec2& size, const DirtMachine::String& labelTextString, const DirtMachine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, float labelTextPadding, DirtMachine::UI::Control* parent);

		virtual ~MenuButton();

		DirtMachine::UI::ContextMenu& GetContextMenu();

		const DirtMachine::UI::ContextMenu& GetContextMenu() const;

		DirtMachine::UI::MenuButton& operator = (const DirtMachine::UI::MenuButton&) = delete;
		DirtMachine::UI::MenuButton& operator = (DirtMachine::UI::MenuButton&&) = delete;

	private:

		std::shared_ptr<DirtMachine::UI::ContextMenu> contextMenu;
	};
}
