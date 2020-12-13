#pragma once

#include <memory>
#include <queue>
#include <Comparator/DrawableRendererDataComparator.hpp>
#include <Data/DrawableRendererData.hpp>
#include <Graphic/Drawable.hpp>
#include <Graphic/RenderStates.hpp>
#include <Graphic/RenderTarget.hpp>

namespace DirtMachine::Graphic
{
	class Renderer : public DirtMachine::Graphic::Drawable
	{
	public:

		Renderer();

		Renderer(const DirtMachine::Graphic::Renderer&) = delete;
		Renderer(DirtMachine::Graphic::Renderer&&) = delete;

		virtual ~Renderer();

		virtual void Enqueue(const DirtMachine::Graphic::Drawable* drawable, std::size_t layer, int priority, const DirtMachine::Graphic::RenderStates& renderStates);

		DirtMachine::Graphic::Renderer& operator = (const DirtMachine::Graphic::Renderer&) = delete;
		DirtMachine::Graphic::Renderer& operator = (DirtMachine::Graphic::Renderer&&) = delete;

	protected:

		virtual void draw(DirtMachine::Graphic::RenderTarget& target, DirtMachine::Graphic::RenderStates states) const;

	private:

		std::unique_ptr<std::priority_queue<DirtMachine::Data::DrawableRendererData, std::vector<DirtMachine::Data::DrawableRendererData>, DirtMachine::Comparator::DrawableRendererDataComparator>> drawableDataQueue;
	};
}
