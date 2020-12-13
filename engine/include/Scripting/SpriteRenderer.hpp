#pragma once

#include <cstdint>
#include <memory>
#include <Data/DrawableRendererData.hpp>
#include <Graphic/RenderStates.hpp>
#include <Graphic/Sprite.hpp>
#include <Scripting/Behaviour.hpp>

namespace DirtMachine::Scripting
{
	class SpriteRenderer : public DirtMachine::Scripting::Behaviour
	{
	public:

		SpriteRenderer() = delete;
		SpriteRenderer(const DirtMachine::Scripting::SpriteRenderer&) = delete;
		SpriteRenderer(DirtMachine::Scripting::SpriteRenderer&&) = delete;

		SpriteRenderer(std::size_t layer, int priority, const DirtMachine::Graphic::Sprite* sprite);

		virtual ~SpriteRenderer();

		virtual std::size_t GetLayer() const;

		virtual void SetLayer(std::size_t newLayer);

		virtual int GetPriority() const;

		virtual void SetPriority(int newPriority);

		virtual const DirtMachine::Graphic::Sprite* GetSprite() const;

		virtual void SetSprite(const DirtMachine::Graphic::Sprite* newSprite);

		virtual void Render(const glm::mat4x4& parentTransformationMatrix, DirtMachine::Graphic::Renderer& renderer) override;

		DirtMachine::Scripting::SpriteRenderer& operator = (const DirtMachine::Scripting::SpriteRenderer&) = delete;
		DirtMachine::Scripting::SpriteRenderer& operator = (DirtMachine::Scripting::SpriteRenderer&&) = delete;

	private:

		std::size_t layer;

		int priority;

		DirtMachine::Graphic::RenderStates renderStates;

		const DirtMachine::Graphic::Sprite* sprite;
	};
}
