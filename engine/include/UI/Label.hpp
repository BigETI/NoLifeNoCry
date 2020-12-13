#pragma once

#include <string>
#include <glm/vec2.hpp>
#include <String.hpp>
#include <UI/Control.hpp>
#include <UI/ETextAlignment.hpp>
#include <Graphic/Font.hpp>
#include <Graphic/Text.hpp>

namespace DirtMachine::UI
{
	class Label : public DirtMachine::UI::Control
	{
	public:

		Label(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::String& textString, const DirtMachine::Graphic::Font* textFont, unsigned int textCharacterSize, DirtMachine::UI::ETextAlignment textAlignment, DirtMachine::UI::Control* parent = nullptr);

		virtual ~Label();

		virtual void SetTextString(const DirtMachine::String& textString);

		virtual DirtMachine::String GetTextString() const;

		void SetTextAlignment(DirtMachine::UI::ETextAlignment newTextAlignment);

		virtual DirtMachine::UI::ETextAlignment GetTextAlignment() const;

		virtual void SetTextFont(const DirtMachine::Graphic::Font* newTextFont);

		virtual const DirtMachine::Graphic::Font* GetTextFont() const;

		virtual void SetTextCharacterSize(unsigned int textCharacterSize);

		virtual unsigned int GetTextCharacterSize() const;

		virtual void SetTextLineSpacing(float textSpacingFactor);

		virtual float GetTextLineSpacing() const;

		virtual void SetTextLetterSpacing(float textSpacingFactor);

		virtual float GetTextLetterSpacing() const;

		virtual void SetTextStyle(uint32_t textStyle);

		virtual uint32_t GetTextStyle() const;

		virtual void SetTextOutlineThickness(float textOutlineThickness);

		virtual float GetTextOutlineThickness() const;

		virtual glm::vec2 FindTextCharacterPosition(std::size_t textCharacterIndex) const;

		virtual DirtMachine::Graphic::Rectangle<float> GetTextLocalBounds() const;

		virtual DirtMachine::Graphic::Rectangle<float> GetTextGlobalBounds() const;

		virtual void Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const override;

	private:

		DirtMachine::Graphic::Text text;

		DirtMachine::UI::ETextAlignment textAlignment;
	};
}
