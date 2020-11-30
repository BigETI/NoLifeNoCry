#pragma once

#include <cstdint>
#include <string>
#include <glm/vec2.hpp>
#include <Graphic/Sprite.hpp>
#include <Graphic/Text.hpp>
#include <UI/InteractableControl.hpp>
#include <UI/Label.hpp>
#include <UI/Panel.hpp>

namespace NoLifeNoCry::Engine::UI
{
	class Button : public NoLifeNoCry::Engine::UI::InteractableControl
	{
	public:

		Button(glm::ivec2 position, float rotation, glm::uvec2 size, const std::string& labelTextString, const NoLifeNoCry::Engine::Graphic::Font* labelTextFont, unsigned int labelTextCharacterSize, NoLifeNoCry::Engine::UI::Control* parent);

		virtual ~Button();

		virtual NoLifeNoCry::Engine::UI::Label& GetLabel();

		virtual const NoLifeNoCry::Engine::UI::Label& GetLabel() const;

	private:

		std::shared_ptr<NoLifeNoCry::Engine::UI::Panel> backgroundPanel;

		std::shared_ptr<NoLifeNoCry::Engine::UI::Label> label;
	};
}
