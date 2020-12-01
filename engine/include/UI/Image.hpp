#pragma once

#include <glm/vec2.hpp>
#include <Graphic/Image.hpp>
#include <Graphic/RenderTarget.hpp>
#include <Graphic/Sprite.hpp>
#include <Graphic/Texture.hpp>
#include <UI/Control.hpp>

namespace DirtMachine::UI
{
	class Image : public DirtMachine::UI::Control
	{
	public:

		Image(const DirtMachine::Graphic::Image& image, bool isRepeating, bool isSmooth, bool isSRGB, const glm::ivec2& position, float rotation, const glm::uvec2& size, DirtMachine::UI::Control* parent);

		virtual ~Image();

		virtual void SetImage(const DirtMachine::Graphic::Image& image);

		virtual void Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const override;

	private:

		DirtMachine::Graphic::Texture texture;

		DirtMachine::Graphic::Sprite sprite;
	};
}
