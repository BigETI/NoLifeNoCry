#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/Rectangle.hpp>
#include <Graphic/Texture.hpp>

namespace NoLifeNoCry::Engine::Graphic
{
	class Sprite : sf::Sprite
	{
    public:
        Sprite();

        explicit Sprite(const NoLifeNoCry::Engine::Graphic::Texture& texture);

        Sprite(const NoLifeNoCry::Engine::Graphic::Texture& texture, const NoLifeNoCry::Engine::Graphic::Rectangle<int>& rectangle);

        void SetTexture(const NoLifeNoCry::Engine::Graphic::Texture& texture, bool resetRect = false);

        void SetTextureRect(const NoLifeNoCry::Engine::Graphic::Rectangle<int>& rectangle);

        void SetColor(const NoLifeNoCry::Engine::Graphic::Colour& color);

        const sf::Texture* GetTexture() const;

        const NoLifeNoCry::Engine::Graphic::Rectangle<int>& GetTextureRect() const;

        const NoLifeNoCry::Engine::Graphic::Colour& GetColor() const;

        NoLifeNoCry::Engine::Graphic::Rectangle<float> GetLocalBounds() const;

        NoLifeNoCry::Engine::Graphic::Rectangle<float> GetGlobalBounds() const;
	};
}
