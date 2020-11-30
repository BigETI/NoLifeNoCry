#pragma once

#include <glm/vec2.hpp>
#include <Graphic/Image.hpp>
#include <Graphic/RenderTarget.hpp>
#include <Graphic/Sprite.hpp>
#include <Graphic/Texture.hpp>
#include <UI/Control.hpp>

namespace NoLifeNoCry::Engine::UI
{
	class Image : public NoLifeNoCry::Engine::UI::Control
	{
	public:

		Image(const NoLifeNoCry::Engine::Graphic::Image& image, bool isRepeating, bool isSmooth, bool isSRGB, const glm::ivec2& position, float rotation, const glm::uvec2& size, NoLifeNoCry::Engine::UI::Control* parent);

		virtual ~Image();

		virtual void SetImage(const NoLifeNoCry::Engine::Graphic::Image& image);

		virtual void Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const override;

	private:

		NoLifeNoCry::Engine::Graphic::Texture texture;

		NoLifeNoCry::Engine::Graphic::Sprite sprite;
	};
}
