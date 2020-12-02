#include <UI/Label.hpp>

DirtMachine::UI::Label::Label(const DirtMachine::String& textString, const DirtMachine::Graphic::Font* textFont, unsigned int textCharacterSize, DirtMachine::UI::ETextAlignment textAlignment, const glm::ivec2& position, float rotation, const glm::uvec2& size, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Control(position, rotation, size, true, true, parent),
	text(textString, *textFont, textCharacterSize),
	textAlignment(textAlignment)
{
	OnPrimaryTextColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		text.SetFillColour(colour);
	};
	OnSecondaryTextColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		text.SetOutlineColour(colour);
	};
	text.SetCharacterSize(textCharacterSize);
	text.SetFillColour(GetPrimaryTextColour());
	text.SetOutlineColour(GetSecondaryTextColour());
}

DirtMachine::UI::Label::~Label()
{
	// ...
}

void DirtMachine::UI::Label::SetTextString(const DirtMachine::String& textString)
{
	text.SetString(textString);
}

DirtMachine::String DirtMachine::UI::Label::GetTextString() const
{
	return text.GetString();
}

void DirtMachine::UI::Label::SetTextAlignment(DirtMachine::UI::ETextAlignment newTextAlignment)
{
	textAlignment = newTextAlignment;
}

DirtMachine::UI::ETextAlignment DirtMachine::UI::Label::GetTextAlignment() const
{
	return textAlignment;
}

void DirtMachine::UI::Label::SetTextFont(const DirtMachine::Graphic::Font* newTextFont)
{
	text.SetFont(newTextFont);
}

const sf::Font* DirtMachine::UI::Label::GetTextFont() const
{
	return text.GetFont();
}

void DirtMachine::UI::Label::SetTextCharacterSize(unsigned int textCharacterSize)
{
	text.SetCharacterSize(textCharacterSize);
}

unsigned int DirtMachine::UI::Label::GetTextCharacterSize() const
{
	return text.GetCharacterSize();
}

void DirtMachine::UI::Label::SetTextLineSpacing(float textSpacingFactor)
{
	text.SetLineSpacing(textSpacingFactor);
}

float DirtMachine::UI::Label::GetTextLineSpacing() const
{
	return text.GetLineSpacing();
}

void DirtMachine::UI::Label::SetTextLetterSpacing(float textSpacingFactor)
{
	text.SetLetterSpacing(textSpacingFactor);
}

float DirtMachine::UI::Label::GetTextLetterSpacing() const
{
	return text.GetLetterSpacing();
}

void DirtMachine::UI::Label::SetTextStyle(uint32_t textStyle)
{
	text.SetStyle(textStyle);
}

uint32_t DirtMachine::UI::Label::GetTextStyle() const
{
	return text.GetStyle();
}

void DirtMachine::UI::Label::SetTextOutlineThickness(float textOutlineThickness)
{
	text.SetOutlineThickness(textOutlineThickness);
}

float DirtMachine::UI::Label::GetTextOutlineThickness() const
{
	return text.GetOutlineThickness();
}

glm::vec2 DirtMachine::UI::Label::FindTextCharacterPosition(std::size_t textCharacterIndex) const
{
	return text.FindCharacterPosition(textCharacterIndex);
}

DirtMachine::Graphic::Rectangle<float> DirtMachine::UI::Label::GetTextLocalBounds() const
{
	return text.GetLocalBounds();
}

DirtMachine::Graphic::Rectangle<float> DirtMachine::UI::Label::GetTextGlobalBounds() const
{
	return text.GetGlobalBounds();
}

void DirtMachine::UI::Label::Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const
{
	sf::View view(renderTarget.getView());
	//DirtMachine::Graphic::Rectangle<float> local_bounds(text.GetGlobalBounds());
	glm::vec2 last_character_position(text.FindCharacterPosition(text.GetString().length()));
	unsigned int character_size(text.GetCharacterSize());
	glm::vec2 label_string_size(last_character_position.x, last_character_position.y + character_size);
	glm::uvec2 label_size(GetSize());
	switch (textAlignment)
	{
	case ETextAlignment::TopCenter:
		view.move({ (label_string_size.x - label_size.x) * 0.5f, 0.0f });
		break;
	case ETextAlignment::TopRight:
		view.move({ label_string_size.x - label_size.x, 0.0f });
		break;
	case ETextAlignment::CenterLeft:
		view.move({ 0.0f, (label_string_size.y - label_size.y) * 0.5f });
		break;
	case ETextAlignment::Center:
		view.move({ (label_string_size.x - label_size.x) * 0.5f, (label_string_size.y - label_size.y) * 0.5f });
		break;
	case ETextAlignment::CenterRight:
		view.move({ label_string_size.x - label_size.x, (label_string_size.y - label_size.y) * 0.5f });
		break;
	case ETextAlignment::BottomLeft:
		view.move({ 0.0f, label_string_size.y - label_size.y });
		break;
	case ETextAlignment::BottomCenter:
		view.move({ (label_string_size.x - label_size.x) * 0.5f, label_string_size.y - label_size.y });
		break;
	case ETextAlignment::BottomRight:
		view.move({ label_string_size.x - label_size.x, label_string_size.y - label_size.y });
		break;
	}
	renderTarget.setView(view);
	renderTarget.draw(reinterpret_cast<const sf::Drawable&>(text));
	DirtMachine::UI::Control::Draw(renderTarget);
}
