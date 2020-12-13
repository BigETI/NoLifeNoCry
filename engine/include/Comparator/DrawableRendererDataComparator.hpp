#pragma once

#include <Data/DrawableRendererData.hpp>

namespace DirtMachine::Comparator
{
	struct DrawableRendererDataComparator
	{
		bool operator()(const DirtMachine::Data::DrawableRendererData& left, const DirtMachine::Data::DrawableRendererData& right) const;
	};
}
