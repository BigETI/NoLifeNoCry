#include <UI/InteractableControl.hpp>

DirtMachine::UI::InteractableControl::InteractableControl(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, bool isEnabled, bool isSelectable, bool isDraggable, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::Control(position, rotation, size, isVisible, isEnabled, parent),
	isSelectable(isSelectable),
	isDraggable(isDraggable),
	isMouseOnControl(false)
{
	// ...
}

DirtMachine::UI::InteractableControl::~InteractableControl()
{
	// ...
}

bool DirtMachine::UI::InteractableControl::IsSelectable() const
{
	return isSelectable;
}

void DirtMachine::UI::InteractableControl::SetSelectableState(bool selectableState)
{
	isSelectable = selectableState;
}

bool DirtMachine::UI::InteractableControl::IsDraggable() const
{
	return isDraggable;
}

void DirtMachine::UI::InteractableControl::SetDraggableState(bool draggableState)
{
	isDraggable = draggableState;
}

bool DirtMachine::UI::InteractableControl::IsMouseOnControl() const
{
	return isMouseOnControl;
}

bool DirtMachine::UI::InteractableControl::ProcessMouseWheelScrolled(const DirtMachine::Input::Data::MouseWheelData& mouseWheelData)
{
	bool ret(false);
	if (IsMouseOnWindow())
	{
		for (int index(static_cast<int>(GetChildCount()) - 1); index >= 0; index--)
		{
			Control& child(GetChild(static_cast<std::size_t>(index)));
			if (child.IsVisible() && child.IsEnabled())
			{
				ret = child.ProcessMouseWheelScrolled(mouseWheelData);
				if (ret)
				{
					break;
				}
			}
		}
		if (!ret)
		{
			glm::ivec2 local_position = mouseWheelData.position - GetGlobalPosition();
			glm::uvec2 current_size(GetSize());
			ret = (local_position.x >= 0) && (local_position.x <= static_cast<int>(current_size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(current_size.y));
			if (ret)
			{
				OnMouseWheelScrolled(mouseWheelData);
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::InteractableControl::ProcessMouseButtonPressed(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
{
	bool ret(false);
	if (IsMouseOnWindow())
	{
		for (int index(static_cast<int>(GetChildCount()) - 1); index >= 0; index--)
		{
			Control& child(GetChild(static_cast<std::size_t>(index)));
			if (child.IsVisible() && child.IsEnabled())
			{
				ret = child.ProcessMouseButtonPressed(mouseButtonData);
				if (ret)
				{
					break;
				}
			}
		}
		if (!ret)
		{
			glm::ivec2 local_position = mouseButtonData.position - GetGlobalPosition();
			glm::uvec2 current_size(GetSize());
			ret = (local_position.x >= 0) && (local_position.x <= static_cast<int>(current_size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(current_size.y));
			if (ret)
			{
				OnMouseButtonPressed(mouseButtonData);
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::InteractableControl::ProcessMouseButtonReleased(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
{
	bool ret(false);
	if (IsMouseOnWindow())
	{
		for (int index(static_cast<int>(GetChildCount()) - 1); index >= 0; index--)
		{
			Control& child(GetChild(static_cast<std::size_t>(index)));
			if (child.IsVisible() && child.IsEnabled())
			{
				ret = child.ProcessMouseButtonReleased(mouseButtonData);
				if (ret)
				{
					break;
				}
			}
		}
		if (!ret)
		{
			glm::ivec2 global_position(GetGlobalPosition());
			glm::ivec2 local_position = mouseButtonData.position - global_position;
			glm::uvec2 current_size(GetSize());
			ret = (local_position.x >= 0) && (local_position.x <= static_cast<int>(current_size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(current_size.y));
			if (ret)
			{
				OnMouseButtonReleased(mouseButtonData);
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::InteractableControl::ProcessMouseMoved(const DirtMachine::Input::Data::MouseMovementData& mouseMovementData)
{
	bool ret(false);
	if (IsMouseOnWindow())
	{
		for (int index(static_cast<int>(GetChildCount()) - 1); index >= 0; index--)
		{
			Control& child(GetChild(static_cast<std::size_t>(index)));
			if (child.IsVisible() && child.IsEnabled())
			{
				ret = child.ProcessMouseMoved(mouseMovementData);
				if (ret)
				{
					break;
				}
			}
		}
		if (!ret)
		{
			glm::ivec2 local_position = mouseMovementData.position - GetGlobalPosition();
			glm::uvec2 current_size(GetSize());
			ret = (local_position.x >= 0) && (local_position.x <= static_cast<int>(current_size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(current_size.y));
			if (isMouseOnControl != ret)
			{
				isMouseOnControl = ret;
				if (isMouseOnControl)
				{
					OnMouseEntered();
				}
				else
				{
					OnMouseLeft();
				}
			}
			else if (isMouseOnControl)
			{
				OnMouseHovered();
			}
		}
	}
	return ret;
}
