#include <Graphic/Text.hpp>

DirtMachine::Graphic::Text::Text() : sf::Text()
{
	// ...
}

DirtMachine::Graphic::Text::Text(const std::string& string, const DirtMachine::Graphic::Font& font, unsigned int characterSize) : sf::Text(string, reinterpret_cast<const DirtMachine::Graphic::Font&>(font), characterSize)
{
	// ...
}

void DirtMachine::Graphic::Text::SetString(const std::string& string)
{
	setString(string);
}

void DirtMachine::Graphic::Text::SetFont(const DirtMachine::Graphic::Font* font)
{
	setFont(*font);
}

void DirtMachine::Graphic::Text::SetCharacterSize(unsigned int size)
{
	setCharacterSize(size);
}

void DirtMachine::Graphic::Text::SetLineSpacing(float spacingFactor)
{
	setLineSpacing(spacingFactor);
}

void DirtMachine::Graphic::Text::SetLetterSpacing(float spacingFactor)
{
	setLetterSpacing(spacingFactor);
}

void DirtMachine::Graphic::Text::SetStyle(uint32_t style)
{
	setStyle(style);
}

void DirtMachine::Graphic::Text::SetFillColour(const DirtMachine::Graphic::Colour& colour)
{
	setFillColor(colour);
}

void DirtMachine::Graphic::Text::SetOutlineColour(const DirtMachine::Graphic::Colour& colour)
{
	setOutlineColor(colour);
}

void DirtMachine::Graphic::Text::SetOutlineThickness(float thickness)
{
	setOutlineThickness(thickness);
}

std::string DirtMachine::Graphic::Text::GetString() const
{
	return getString();
}

const DirtMachine::Graphic::Font* DirtMachine::Graphic::Text::GetFont() const
{
	return getFont();
}

unsigned int DirtMachine::Graphic::Text::GetCharacterSize() const
{
	return getCharacterSize();
}

float DirtMachine::Graphic::Text::GetLetterSpacing() const
{
	return getLetterSpacing();
}

float DirtMachine::Graphic::Text::GetLineSpacing() const
{
	return getLineSpacing();
}

std::uint32_t DirtMachine::Graphic::Text::GetStyle() const
{
	return static_cast<std::uint32_t>(getStyle());
}

const DirtMachine::Graphic::Colour& DirtMachine::Graphic::Text::GetFillColour() const
{
	return getFillColor();
}

const DirtMachine::Graphic::Colour& DirtMachine::Graphic::Text::GetOutlineColour() const
{
	return getOutlineColor();
}

float DirtMachine::Graphic::Text::GetOutlineThickness() const
{
	return getOutlineThickness();
}

glm::vec2 DirtMachine::Graphic::Text::FindCharacterPosition(std::size_t index) const
{
	sf::Vector2f position(findCharacterPos(index));
	return { position.x, position.y };
}

DirtMachine::Graphic::Rectangle<float> DirtMachine::Graphic::Text::GetLocalBounds() const
{
	return getLocalBounds();
}

DirtMachine::Graphic::Rectangle<float> DirtMachine::Graphic::Text::GetGlobalBounds() const
{
	return getGlobalBounds();
}
