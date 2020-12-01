#include <UI/Button.hpp>

DirtMachine::UI::Button::Button(glm::ivec2 position, float rotation, glm::uvec2 size, const std::string& labelTextString, const DirtMachine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::InteractableControl(position, rotation, size, true, true, true, false, parent),
	backgroundPanel(nullptr),
	label(nullptr)
{
	backgroundPanel = CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, size);
	label = CreateChild<DirtMachine::UI::Label>(labelTextString, labelTextFont, labelTextCharacterSize, DirtMachine::UI::ETextAlignment::BottomRight, glm::ivec2(0, 0), 0.0f, size);
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
