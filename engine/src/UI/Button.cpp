#include <UI/Button.hpp>

NoLifeNoCry::Engine::UI::Button::Button(glm::ivec2 position, float rotation, glm::uvec2 size, const std::string& labelTextString, const NoLifeNoCry::Engine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, NoLifeNoCry::Engine::UI::Control* parent) :
	NoLifeNoCry::Engine::UI::InteractableControl(position, rotation, size, true, true, true, false, parent),
	backgroundPanel(nullptr),
	label(nullptr)
{
	backgroundPanel = CreateChild<NoLifeNoCry::Engine::UI::Panel>(glm::ivec2(0, 0), 0.0f, size);
	label = CreateChild<NoLifeNoCry::Engine::UI::Label>(labelTextString, labelTextFont, labelTextCharacterSize, NoLifeNoCry::Engine::UI::ETextAlignment::BottomRight, glm::ivec2(0, 0), 0.0f, size);
	OnTransformationChanged += [this]()
	{
		glm::uvec2 size(GetSize());
		backgroundPanel->SetSize(size);
		label->SetSize(size);
	};
}

NoLifeNoCry::Engine::UI::Button::~Button()
{
	// ...
}

NoLifeNoCry::Engine::UI::Label& NoLifeNoCry::Engine::UI::Button::GetLabel()
{
	return *label;
}

const NoLifeNoCry::Engine::UI::Label& NoLifeNoCry::Engine::UI::Button::GetLabel() const
{
	return *label;
}
