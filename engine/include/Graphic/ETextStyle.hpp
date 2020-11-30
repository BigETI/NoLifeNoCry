#pragma once

#include <SFML/Graphics/Text.hpp>

namespace NoLifeNoCry::Engine::Graphic
{
    enum class TextStyle
    {
        Regular = sf::Text::Style::Regular,

        Bold = sf::Text::Style::Bold,

        Italic = sf::Text::Style::Italic,

        Underlined = sf::Text::Style::Underlined,

        StrikeThrough = sf::Text::Style::StrikeThrough
    };
}
