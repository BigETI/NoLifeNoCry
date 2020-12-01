#pragma once

#include <cstdint>
#include <glm/vec2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/ETextStyle.hpp>
#include <Graphic/Font.hpp>
#include <Graphic/Rectangle.hpp>

namespace DirtMachine::Graphic
{
	class Text : sf::Text
	{
    public:
        Text();

        Text(const std::string& string, const DirtMachine::Graphic::Font& font, unsigned int characterSize = 30);

        void SetString(const std::string& string);

        void SetFont(const DirtMachine::Graphic::Font& font);

        void SetCharacterSize(unsigned int size);

        void SetLineSpacing(float spacingFactor);

        void SetLetterSpacing(float spacingFactor);

        void SetStyle(uint32_t style);

        void SetFillColour(const DirtMachine::Graphic::Colour& colour);

        void SetOutlineColour(const DirtMachine::Graphic::Colour& colour);

        void SetOutlineThickness(float thickness);

        std::string GetString() const;

        const DirtMachine::Graphic::Font* GetFont() const;

        unsigned int GetCharacterSize() const;

        float GetLetterSpacing() const;

        float GetLineSpacing() const;

        std::uint32_t GetStyle() const;

        const DirtMachine::Graphic::Colour& GetFillColour() const;

        const DirtMachine::Graphic::Colour& GetOutlineColour() const;

        float GetOutlineThickness() const;

        glm::vec2 FindCharacterPosition(std::size_t index) const;

        DirtMachine::Graphic::Rectangle<float> GetLocalBounds() const;

        DirtMachine::Graphic::Rectangle<float> GetGlobalBounds() const;
	};
}
