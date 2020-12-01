#pragma once

#include <cstdint>
#include <string>
#include <glm/vec2.hpp>
#include <Graphic/Sprite.hpp>
#include <Graphic/Text.hpp>
#include <UI/InteractableControl.hpp>
#include <UI/Label.hpp>
#include <UI/Panel.hpp>

namespace DirtMachine::UI
{
	class Button : public DirtMachine::UI::InteractableControl
	{
	public:

		Button(glm::ivec2 position, float rotation, glm::uvec2 size, const std::string& labelTextString, const DirtMachine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, DirtMachine::UI::Control* parent);

		virtual ~Button();

		virtual DirtMachine::UI::Label& GetLabel();

		virtual const DirtMachine::UI::Label& GetLabel() const;

	private:

		std::shared_ptr<DirtMachine::UI::Panel> backgroundPanel;

		std::shared_ptr<DirtMachine::UI::Label> label;
	};
}
