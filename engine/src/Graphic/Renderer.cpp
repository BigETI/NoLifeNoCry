#include <stdexcept>
#include <Graphic/Renderer.hpp>

DirtMachine::Graphic::Renderer::Renderer() :
	DirtMachine::Graphic::Drawable(),
	drawableDataQueue(std::make_unique<std::priority_queue<DirtMachine::Data::DrawableRendererData, std::vector<DirtMachine::Data::DrawableRendererData>, DirtMachine::Comparator::DrawableRendererDataComparator>>())
{
	// ...
}

DirtMachine::Graphic::Renderer::~Renderer()
{
	// ...
}

void DirtMachine::Graphic::Renderer::Enqueue(const DirtMachine::Graphic::Drawable* drawable, std::size_t layer, int priority, const DirtMachine::Graphic::RenderStates& renderStates)
{
	if (!drawable)
	{
		throw std::invalid_argument("Argument \"drawable\" is null.");
	}
	drawableDataQueue->push({ drawable, layer, priority, renderStates });
}

void DirtMachine::Graphic::Renderer::draw(DirtMachine::Graphic::RenderTarget& target, DirtMachine::Graphic::RenderStates states) const
{
	std::priority_queue<DirtMachine::Data::DrawableRendererData, std::vector<DirtMachine::Data::DrawableRendererData>, DirtMachine::Comparator::DrawableRendererDataComparator>& drawable_data_queue(*drawableDataQueue);
	while (!(drawable_data_queue.empty()))
	{
		const DirtMachine::Data::DrawableRendererData& drawable_data(drawable_data_queue.top());
		DirtMachine::Graphic::RenderStates renderStates(drawable_data.renderStates);
		renderStates.transform.combine(states.transform);
		target.draw(*(drawable_data.drawable), renderStates);
		drawable_data_queue.pop();
	}
}
