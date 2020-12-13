#pragma once

#include <glm/vec2.hpp>
#include <String.hpp>
#include <Graphic/Font.hpp>
#include <UI/InteractableControl.hpp>
#include <UI/Label.hpp>
#include <UI/Panel.hpp>

namespace DirtMachine::UI
{
	class Button : public DirtMachine::UI::InteractableControl
	{
	public:

		Button(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::String& labelTextString, const DirtMachine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, DirtMachine::UI::Control* parent);

		virtual ~Button();

		virtual DirtMachine::UI::Label& GetLabel();

		virtual const DirtMachine::UI::Label& GetLabel() const;

	private:

		std::shared_ptr<DirtMachine::UI::Panel> backgroundPanel;

		std::shared_ptr<DirtMachine::UI::Label> label;
	};
}
