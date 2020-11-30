#include <Graphic/Text.hpp>

NoLifeNoCry::Engine::Graphic::Text::Text() : sf::Text()
{
	// ...
}

NoLifeNoCry::Engine::Graphic::Text::Text(const std::string& string, const NoLifeNoCry::Engine::Graphic::Font& font, unsigned int characterSize) : sf::Text(string, reinterpret_cast<const NoLifeNoCry::Engine::Graphic::Font&>(font), characterSize)
{
	// ...
}

void NoLifeNoCry::Engine::Graphic::Text::SetString(const std::string& string)
{
	setString(string);
}

void NoLifeNoCry::Engine::Graphic::Text::SetFont(const NoLifeNoCry::Engine::Graphic::Font& font)
{
	setFont(font);
}

void NoLifeNoCry::Engine::Graphic::Text::SetCharacterSize(unsigned int size)
{
	setCharacterSize(size);
}

void NoLifeNoCry::Engine::Graphic::Text::SetLineSpacing(float spacingFactor)
{
	setLineSpacing(spacingFactor);
}

void NoLifeNoCry::Engine::Graphic::Text::SetLetterSpacing(float spacingFactor)
{
	setLetterSpacing(spacingFactor);
}

void NoLifeNoCry::Engine::Graphic::Text::SetStyle(uint32_t style)
{
	setStyle(style);
}

void NoLifeNoCry::Engine::Graphic::Text::SetFillColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	setFillColor(colour);
}

void NoLifeNoCry::Engine::Graphic::Text::SetOutlineColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	setOutlineColor(colour);
}

void NoLifeNoCry::Engine::Graphic::Text::SetOutlineThickness(float thickness)
{
	setOutlineThickness(thickness);
}

std::string NoLifeNoCry::Engine::Graphic::Text::GetString() const
{
	return getString();
}

const NoLifeNoCry::Engine::Graphic::Font* NoLifeNoCry::Engine::Graphic::Text::GetFont() const
{
	return getFont();
}

unsigned int NoLifeNoCry::Engine::Graphic::Text::GetCharacterSize() const
{
	return getCharacterSize();
}

float NoLifeNoCry::Engine::Graphic::Text::GetLetterSpacing() const
{
	return getLetterSpacing();
}

float NoLifeNoCry::Engine::Graphic::Text::GetLineSpacing() const
{
	return getLineSpacing();
}

std::uint32_t NoLifeNoCry::Engine::Graphic::Text::GetStyle() const
{
	return static_cast<std::uint32_t>(getStyle());
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::Graphic::Text::GetFillColour() const
{
	return getFillColor();
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::Graphic::Text::GetOutlineColour() const
{
	return getOutlineColor();
}

float NoLifeNoCry::Engine::Graphic::Text::GetOutlineThickness() const
{
	return getOutlineThickness();
}

glm::vec2 NoLifeNoCry::Engine::Graphic::Text::FindCharacterPosition(std::size_t index) const
{
	sf::Vector2f position(findCharacterPos(index));
	return { position.x, position.y };
}

NoLifeNoCry::Engine::Graphic::Rectangle<float> NoLifeNoCry::Engine::Graphic::Text::GetLocalBounds() const
{
	return getLocalBounds();
}

NoLifeNoCry::Engine::Graphic::Rectangle<float> NoLifeNoCry::Engine::Graphic::Text::GetGlobalBounds() const
{
	return getGlobalBounds();
}
