#include <UI/Label.hpp>

NoLifeNoCry::Engine::UI::Label::Label(const NoLifeNoCry::Engine::String& textString, const NoLifeNoCry::Engine::Graphic::Font* textFont, unsigned int textCharacterSize, NoLifeNoCry::Engine::UI::ETextAlignment textAlignment, const glm::ivec2& position, float rotation, const glm::uvec2& size, NoLifeNoCry::Engine::UI::Control* parent) :
	NoLifeNoCry::Engine::UI::Control(position, rotation, size, true, true, parent),
	text(textString, *textFont, textCharacterSize),
	textAlignment(textAlignment)
{
	OnPrimaryTextColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		text.SetFillColour(colour);
	};
	OnSecondaryTextColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		text.SetOutlineColour(colour);
	};
	text.SetCharacterSize(textCharacterSize);
	text.SetFillColour(GetPrimaryTextColour());
	text.SetOutlineColour(GetSecondaryTextColour());
}

NoLifeNoCry::Engine::UI::Label::~Label()
{
	// ...
}

void NoLifeNoCry::Engine::UI::Label::SetTextString(const NoLifeNoCry::Engine::String& textString)
{
	text.SetString(textString);
}

NoLifeNoCry::Engine::String NoLifeNoCry::Engine::UI::Label::GetTextString() const
{
	return text.GetString();
}

void NoLifeNoCry::Engine::UI::Label::SetTextAlignment(NoLifeNoCry::Engine::UI::ETextAlignment newTextAlignment)
{
	textAlignment = newTextAlignment;
}

NoLifeNoCry::Engine::UI::ETextAlignment NoLifeNoCry::Engine::UI::Label::GetTextAlignment() const
{
	return textAlignment;
}

void NoLifeNoCry::Engine::UI::Label::SetTextFont(const NoLifeNoCry::Engine::Graphic::Font& newTextFont)
{
	text.SetFont(newTextFont);
}

const sf::Font* NoLifeNoCry::Engine::UI::Label::GetTextFont() const
{
	return text.GetFont();
}

void NoLifeNoCry::Engine::UI::Label::SetTextCharacterSize(unsigned int textCharacterSize)
{
	text.SetCharacterSize(textCharacterSize);
}

unsigned int NoLifeNoCry::Engine::UI::Label::GetTextCharacterSize() const
{
	return text.GetCharacterSize();
}

void NoLifeNoCry::Engine::UI::Label::SetTextLineSpacing(float textSpacingFactor)
{
	text.SetLineSpacing(textSpacingFactor);
}

float NoLifeNoCry::Engine::UI::Label::GetTextLineSpacing() const
{
	return text.GetLineSpacing();
}

void NoLifeNoCry::Engine::UI::Label::SetTextLetterSpacing(float textSpacingFactor)
{
	text.SetLetterSpacing(textSpacingFactor);
}

float NoLifeNoCry::Engine::UI::Label::GetTextLetterSpacing() const
{
	return text.GetLetterSpacing();
}

void NoLifeNoCry::Engine::UI::Label::SetTextStyle(uint32_t textStyle)
{
	text.SetStyle(textStyle);
}

uint32_t NoLifeNoCry::Engine::UI::Label::GetTextStyle() const
{
	return text.GetStyle();
}

void NoLifeNoCry::Engine::UI::Label::SetTextOutlineThickness(float textOutlineThickness)
{
	text.SetOutlineThickness(textOutlineThickness);
}

float NoLifeNoCry::Engine::UI::Label::GetTextOutlineThickness() const
{
	return text.GetOutlineThickness();
}

glm::vec2 NoLifeNoCry::Engine::UI::Label::FindTextCharacterPosition(std::size_t textCharacterIndex) const
{
	return text.FindCharacterPosition(textCharacterIndex);
}

NoLifeNoCry::Engine::Graphic::Rectangle<float> NoLifeNoCry::Engine::UI::Label::GetTextLocalBounds() const
{
	return text.GetLocalBounds();
}

NoLifeNoCry::Engine::Graphic::Rectangle<float> NoLifeNoCry::Engine::UI::Label::GetTextGlobalBounds() const
{
	return text.GetGlobalBounds();
}

void NoLifeNoCry::Engine::UI::Label::Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const
{
	sf::View view(renderTarget.getView());
	//NoLifeNoCry::Engine::Graphic::Rectangle<float> local_bounds(text.GetGlobalBounds());
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
	NoLifeNoCry::Engine::UI::Control::Draw(renderTarget);
}
