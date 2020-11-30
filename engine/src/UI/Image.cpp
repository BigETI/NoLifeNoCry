#include <UI/Image.hpp>

NoLifeNoCry::Engine::UI::Image::Image(const NoLifeNoCry::Engine::Graphic::Image& image, bool isRepeating, bool isSmooth, bool isSRGB, const glm::ivec2& position, float rotation, const glm::uvec2& size, NoLifeNoCry::Engine::UI::Control* parent) :
	NoLifeNoCry::Engine::UI::Control(position, rotation, size, true, true, parent)
{
	if (texture.Create(size.x, size.y))
	{
		texture.SetRepeated(isRepeating);
		texture.SetSmooth(isSmooth);
		texture.SetSRGB(isSRGB);
		sprite.SetTextureRect(NoLifeNoCry::Engine::Graphic::Rectangle<int>(sf::Vector2i(0, 0), sf::Vector2i(static_cast<int>(size.x), static_cast<int>(size.y))));
		sprite.SetTexture(texture);
	}
	OnTransformationChanged += [this]()
	{
		glm::uvec2 size(GetSize());
		sprite.SetTextureRect(NoLifeNoCry::Engine::Graphic::Rectangle<int>(sf::Vector2i(0, 0), sf::Vector2i(static_cast<int>(size.x), static_cast<int>(size.y))));
	};
}

NoLifeNoCry::Engine::UI::Image::~Image()
{
	// ...
}

void NoLifeNoCry::Engine::UI::Image::SetImage(const NoLifeNoCry::Engine::Graphic::Image& image)
{
	texture.Update(image);
	sprite.SetTexture(texture, false);
}

void NoLifeNoCry::Engine::UI::Image::Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const
{
	renderTarget.draw(reinterpret_cast<const sf::Drawable&>(sprite));
	NoLifeNoCry::Engine::UI::Control::Draw(renderTarget);
}
