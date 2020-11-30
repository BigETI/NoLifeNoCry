#include <UI/Panel.hpp>

NoLifeNoCry::Engine::UI::Panel::Panel(const glm::ivec2& position, float rotation, const glm::uvec2& size, NoLifeNoCry::Engine::UI::Control* parent) :
	NoLifeNoCry::Engine::UI::Control(position, rotation, size, true, true, parent)
{
	if (backgroundTexture.Create(1U, 1U))
	{
		NoLifeNoCry::Engine::Graphic::Colour pixel(0xFF, 0xFF, 0xFF, 0xFF);
		backgroundTexture.SetRepeated(true);
		backgroundTexture.SetSmooth(false);
		backgroundTexture.Update(reinterpret_cast<const std::uint8_t*>(&pixel));
		backgroundSprite.SetTexture(backgroundTexture);
		backgroundSprite.SetTextureRect(NoLifeNoCry::Engine::Graphic::Rectangle<int>(sf::Vector2i(0, 0), sf::Vector2i(static_cast<int>(size.x), static_cast<int>(size.y))));
		backgroundSprite.SetColor(GetPrimaryBackgroundColour());
	}
	OnTransformationChanged += [this]()
	{
		glm::uvec2 new_size(GetSize());
		backgroundSprite.SetTextureRect(NoLifeNoCry::Engine::Graphic::Rectangle<int>(sf::Vector2i(0, 0), sf::Vector2i(static_cast<int>(new_size.x), static_cast<int>(new_size.y))));
	};
	OnPrimaryBackgroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		backgroundSprite.SetColor(colour);
	};
}

NoLifeNoCry::Engine::UI::Panel::~Panel()
{
	// ...
}

void NoLifeNoCry::Engine::UI::Panel::Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const
{
	renderTarget.draw(reinterpret_cast<const sf::Drawable&>(backgroundSprite));
	NoLifeNoCry::Engine::UI::Control::Draw(renderTarget);
}
