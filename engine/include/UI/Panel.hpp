#pragma once

#include <glm/vec2.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/RenderTarget.hpp>
#include <Graphic/Sprite.hpp>
#include <Graphic/Texture.hpp>
#include <UI/Control.hpp>

namespace DirtMachine::UI
{
	class Panel : public DirtMachine::UI::Control
	{
	public:

		Panel(const glm::ivec2& position, float rotation, const glm::uvec2& size, DirtMachine::UI::Control* parent);

		virtual ~Panel();

		virtual void Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const override;

	private:

		DirtMachine::Graphic::Texture backgroundTexture;

		DirtMachine::Graphic::Sprite backgroundSprite;
	};
}
