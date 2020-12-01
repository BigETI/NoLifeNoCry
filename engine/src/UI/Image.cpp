#include <UI/Image.hpp>

DirtMachine::UI::Image::Image(const DirtMachine::Graphic::Image& image, bool isRepeating, bool isSmooth, bool isSRGB, const glm::ivec2& position, float rotation, const glm::uvec2& size, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Control(position, rotation, size, true, true, parent)
{
	if (texture.Create(size.x, size.y))
	{
		texture.SetRepeated(isRepeating);
		texture.SetSmooth(isSmooth);
		texture.SetSRGB(isSRGB);
		sprite.SetTextureRect(DirtMachine::Graphic::Rectangle<int>(sf::Vector2i(0, 0), sf::Vector2i(static_cast<int>(size.x), static_cast<int>(size.y))));
		sprite.SetTexture(texture);
	}
	OnTransformationChanged += [this]()
	{
		glm::uvec2 size(GetSize());
		sprite.SetTextureRect(DirtMachine::Graphic::Rectangle<int>(sf::Vector2i(0, 0), sf::Vector2i(static_cast<int>(size.x), static_cast<int>(size.y))));
	};
}

DirtMachine::UI::Image::~Image()
{
	// ...
}

void DirtMachine::UI::Image::SetImage(const DirtMachine::Graphic::Image& image)
{
	texture.Update(image);
	sprite.SetTexture(texture, false);
}

void DirtMachine::UI::Image::Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const
{
	renderTarget.draw(reinterpret_cast<const sf::Drawable&>(sprite));
	DirtMachine::UI::Control::Draw(renderTarget);
}
