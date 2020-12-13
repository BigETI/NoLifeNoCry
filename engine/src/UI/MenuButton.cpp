#include <Input/Data/MouseButtonData.hpp>
#include <Input/EMouseButton.hpp>
#include <UI/MenuButton.hpp>

DirtMachine::UI::MenuButton::MenuButton(const glm::ivec2& position, float roation, const glm::uvec2& size, const DirtMachine::String& labelTextString, const DirtMachine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, float labelTextPadding, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Button(position, roation, size, labelTextString, labelTextFont, labelTextCharacterSize, parent)
{
	contextMenu = CreateChild<DirtMachine::UI::ContextMenu>(glm::ivec2(0, static_cast<int>(size.y)), 0.0f, glm::uvec2(0U, 0U), labelTextFont, labelTextCharacterSize, labelTextPadding);
	contextMenu->SetVisibleState(false);
	OnTransformationChanged += [this]()
	{
		contextMenu->SetLocalPosition(glm::ivec2(0, /*static_cast<int>(GetSize().y)*/ 24));
	};
}

DirtMachine::UI::MenuButton::~MenuButton()
{
	// ...
}

DirtMachine::UI::ContextMenu& DirtMachine::UI::MenuButton::GetContextMenu()
{
	return *(contextMenu.get());
}

const DirtMachine::UI::ContextMenu& DirtMachine::UI::MenuButton::GetContextMenu() const
{
	return *(contextMenu.get());
}
