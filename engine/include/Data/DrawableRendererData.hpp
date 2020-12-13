#pragma once

#include <cstdint>
#include <Graphic/Drawable.hpp>
#include <Graphic/RenderStates.hpp>

namespace DirtMachine::Data
{
	struct DrawableRendererData
	{
		const DirtMachine::Graphic::Drawable* drawable;

		std::size_t layer;

		int priority;

		DirtMachine::Graphic::RenderStates renderStates;
	};
}
