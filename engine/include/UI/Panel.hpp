#pragma once

#include <glm/vec2.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/RenderTarget.hpp>
#include <Graphic/Sprite.hpp>
#include <Graphic/Texture.hpp>
#include <UI/Control.hpp>

namespace NoLifeNoCry::Engine::UI
{
	class Panel : public NoLifeNoCry::Engine::UI::Control
	{
	public:

		Panel(const glm::ivec2& position, float rotation, const glm::uvec2& size, NoLifeNoCry::Engine::UI::Control* parent);

		virtual ~Panel();

		virtual void Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const override;

	private:

		NoLifeNoCry::Engine::Graphic::Texture backgroundTexture;

		NoLifeNoCry::Engine::Graphic::Sprite backgroundSprite;
	};
}
