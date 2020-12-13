#include <Comparator/DrawableRendererDataComparator.hpp>

bool DirtMachine::Comparator::DrawableRendererDataComparator::operator()(const DirtMachine::Data::DrawableRendererData& left, const DirtMachine::Data::DrawableRendererData& right) const
{
	return (left.layer == right.layer) ? (left.priority < right.priority) : (left.layer < right.layer);
}
