#pragma once

#include <string>
#include <glm/vec2.hpp>
#include <String.hpp>
#include <UI/Control.hpp>
#include <UI/ETextAlignment.hpp>
#include <Graphic/Font.hpp>
#include <Graphic/Text.hpp>

namespace NoLifeNoCry::Engine::UI
{
	class Label : public NoLifeNoCry::Engine::UI::Control
	{
	public:

		Label(const NoLifeNoCry::Engine::String& textString, const NoLifeNoCry::Engine::Graphic::Font* textFont, unsigned int textCharacterSize, NoLifeNoCry::Engine::UI::ETextAlignment textAlignment, const glm::ivec2& position, float rotation, const glm::uvec2& size, NoLifeNoCry::Engine::UI::Control* parent = nullptr);

		virtual ~Label();

		virtual void SetTextString(const NoLifeNoCry::Engine::String& textString);

		virtual NoLifeNoCry::Engine::String GetTextString() const;

		void SetTextAlignment(NoLifeNoCry::Engine::UI::ETextAlignment newTextAlignment);

		virtual NoLifeNoCry::Engine::UI::ETextAlignment GetTextAlignment() const;

		virtual void SetTextFont(const NoLifeNoCry::Engine::Graphic::Font& newTextFont);

		virtual const NoLifeNoCry::Engine::Graphic::Font* GetTextFont() const;

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

		virtual NoLifeNoCry::Engine::Graphic::Rectangle<float> GetTextLocalBounds() const;

		virtual NoLifeNoCry::Engine::Graphic::Rectangle<float> GetTextGlobalBounds() const;

		virtual void Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const override;

	private:

		NoLifeNoCry::Engine::Graphic::Text text;

		NoLifeNoCry::Engine::UI::ETextAlignment textAlignment;
	};
}
