#include <Graphic/Sprite.hpp>

DirtMachine::Graphic::Sprite::Sprite() : sf::Sprite()
{
	// ...
}

DirtMachine::Graphic::Sprite::Sprite(const DirtMachine::Graphic::Texture& texture) : sf::Sprite(reinterpret_cast<const sf::Texture&>(texture))
{
	// ...
}

DirtMachine::Graphic::Sprite::Sprite(const DirtMachine::Graphic::Texture& texture, const DirtMachine::Graphic::Rectangle<int>& rectangle) : sf::Sprite(reinterpret_cast<const sf::Texture&>(texture), rectangle)
{
	// ...
}

void DirtMachine::Graphic::Sprite::SetTexture(const DirtMachine::Graphic::Texture& texture, bool resetRect)
{
	setTexture(reinterpret_cast<const sf::Texture&>(texture), resetRect);
}

void DirtMachine::Graphic::Sprite::SetTextureRect(const DirtMachine::Graphic::Rectangle<int>& rectangle)
{
	setTextureRect(rectangle);
}

void DirtMachine::Graphic::Sprite::SetColor(const DirtMachine::Graphic::Colour& color)
{
	setColor(color);
}

const sf::Texture* DirtMachine::Graphic::Sprite::GetTexture() const
{
	return getTexture();
}

const DirtMachine::Graphic::Rectangle<int>& DirtMachine::Graphic::Sprite::GetTextureRect() const
{
	return getTextureRect();
}

const DirtMachine::Graphic::Colour& DirtMachine::Graphic::Sprite::GetColor() const
{
	return getColor();
}

DirtMachine::Graphic::Rectangle<float> DirtMachine::Graphic::Sprite::GetLocalBounds() const
{
	return getLocalBounds();
}

DirtMachine::Graphic::Rectangle<float> DirtMachine::Graphic::Sprite::GetGlobalBounds() const
{
	return getGlobalBounds();
}
