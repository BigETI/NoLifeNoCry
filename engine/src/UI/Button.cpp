#include <UI/Button.hpp>

DirtMachine::UI::Button::Button(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::String& labelTextString, const DirtMachine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::InteractableControl(position, rotation, size, true, true, true, false, parent),
	backgroundPanel(nullptr),
	label(nullptr)
{
	backgroundPanel = CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, size);
	label = CreateChild<DirtMachine::UI::Label>(glm::ivec2(0, 0), 0.0f, size, labelTextString, labelTextFont, labelTextCharacterSize, DirtMachine::UI::ETextAlignment::Center);
	OnTransformationChanged += [this]()
	{
		glm::uvec2 size(GetSize());
		backgroundPanel->SetSize(size);
		label->SetSize(size);
	};
}

DirtMachine::UI::Button::~Button()
{
	// ...
}

DirtMachine::UI::Label& DirtMachine::UI::Button::GetLabel()
{
	return *label;
}

const DirtMachine::UI::Label& DirtMachine::UI::Button::GetLabel() const
{
	return *label;
}
