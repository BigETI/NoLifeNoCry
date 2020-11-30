#include <Graphic/Sprite.hpp>

NoLifeNoCry::Engine::Graphic::Sprite::Sprite() : sf::Sprite()
{
	// ...
}

NoLifeNoCry::Engine::Graphic::Sprite::Sprite(const NoLifeNoCry::Engine::Graphic::Texture& texture) : sf::Sprite(reinterpret_cast<const sf::Texture&>(texture))
{
	// ...
}

NoLifeNoCry::Engine::Graphic::Sprite::Sprite(const NoLifeNoCry::Engine::Graphic::Texture& texture, const NoLifeNoCry::Engine::Graphic::Rectangle<int>& rectangle) : sf::Sprite(reinterpret_cast<const sf::Texture&>(texture), rectangle)
{
	// ...
}

void NoLifeNoCry::Engine::Graphic::Sprite::SetTexture(const NoLifeNoCry::Engine::Graphic::Texture& texture, bool resetRect)
{
	setTexture(reinterpret_cast<const sf::Texture&>(texture), resetRect);
}

void NoLifeNoCry::Engine::Graphic::Sprite::SetTextureRect(const NoLifeNoCry::Engine::Graphic::Rectangle<int>& rectangle)
{
	setTextureRect(rectangle);
}

void NoLifeNoCry::Engine::Graphic::Sprite::SetColor(const NoLifeNoCry::Engine::Graphic::Colour& color)
{
	setColor(color);
}

const sf::Texture* NoLifeNoCry::Engine::Graphic::Sprite::GetTexture() const
{
	return getTexture();
}

const NoLifeNoCry::Engine::Graphic::Rectangle<int>& NoLifeNoCry::Engine::Graphic::Sprite::GetTextureRect() const
{
	return getTextureRect();
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::Graphic::Sprite::GetColor() const
{
	return getColor();
}

NoLifeNoCry::Engine::Graphic::Rectangle<float> NoLifeNoCry::Engine::Graphic::Sprite::GetLocalBounds() const
{
	return getLocalBounds();
}

NoLifeNoCry::Engine::Graphic::Rectangle<float> NoLifeNoCry::Engine::Graphic::Sprite::GetGlobalBounds() const
{
	return getGlobalBounds();
}
