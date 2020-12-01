#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/Rectangle.hpp>
#include <Graphic/Texture.hpp>

namespace DirtMachine::Graphic
{
	class Sprite : sf::Sprite
	{
    public:
        Sprite();

        explicit Sprite(const DirtMachine::Graphic::Texture& texture);

        Sprite(const DirtMachine::Graphic::Texture& texture, const DirtMachine::Graphic::Rectangle<int>& rectangle);

        void SetTexture(const DirtMachine::Graphic::Texture& texture, bool resetRect = false);

        void SetTextureRect(const DirtMachine::Graphic::Rectangle<int>& rectangle);

        void SetColor(const DirtMachine::Graphic::Colour& color);

        const sf::Texture* GetTexture() const;

        const DirtMachine::Graphic::Rectangle<int>& GetTextureRect() const;

        const DirtMachine::Graphic::Colour& GetColor() const;

        DirtMachine::Graphic::Rectangle<float> GetLocalBounds() const;

        DirtMachine::Graphic::Rectangle<float> GetGlobalBounds() const;
	};
}
