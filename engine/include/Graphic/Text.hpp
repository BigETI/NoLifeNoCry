#pragma once

#include <cstdint>
#include <glm/vec2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/ETextStyle.hpp>
#include <Graphic/Font.hpp>
#include <Graphic/Rectangle.hpp>

namespace NoLifeNoCry::Engine::Graphic
{
	class Text : sf::Text
	{
    public:
        Text();

        Text(const std::string& string, const NoLifeNoCry::Engine::Graphic::Font& font, unsigned int characterSize = 30);

        void SetString(const std::string& string);

        void SetFont(const NoLifeNoCry::Engine::Graphic::Font& font);

        void SetCharacterSize(unsigned int size);

        void SetLineSpacing(float spacingFactor);

        void SetLetterSpacing(float spacingFactor);

        void SetStyle(uint32_t style);

        void SetFillColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

        void SetOutlineColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

        void SetOutlineThickness(float thickness);

        std::string GetString() const;

        const NoLifeNoCry::Engine::Graphic::Font* GetFont() const;

        unsigned int GetCharacterSize() const;

        float GetLetterSpacing() const;

        float GetLineSpacing() const;

        std::uint32_t GetStyle() const;

        const NoLifeNoCry::Engine::Graphic::Colour& GetFillColour() const;

        const NoLifeNoCry::Engine::Graphic::Colour& GetOutlineColour() const;

        float GetOutlineThickness() const;

        glm::vec2 FindCharacterPosition(std::size_t index) const;

        NoLifeNoCry::Engine::Graphic::Rectangle<float> GetLocalBounds() const;

        NoLifeNoCry::Engine::Graphic::Rectangle<float> GetGlobalBounds() const;
	};
}
