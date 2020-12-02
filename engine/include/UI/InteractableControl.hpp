#pragma once

#include <glm/vec2.hpp>
#include <Event.hpp>
#include <Input/Data/MouseButtonData.hpp>
#include <Input/Data/MouseMovementData.hpp>
#include <Input/Data/MouseWheelData.hpp>
#include <UI/Control.hpp>

namespace DirtMachine::UI
{
	class InteractableControl : public DirtMachine::UI::Control
	{
	public:

		DirtMachine::Event<> OnMouseEntered;

		DirtMachine::Event<> OnMouseLeft;

		DirtMachine::Event<> OnMouseHovered;

		DirtMachine::Event<DirtMachine::Input::Data::MouseButtonData> OnMouseButtonPressed;

		DirtMachine::Event<DirtMachine::Input::Data::MouseButtonData> OnMouseButtonReleased;

		InteractableControl(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, bool isEnabled, bool isSelectable, bool isDraggable, DirtMachine::UI::Control* parent);

		virtual ~InteractableControl();

		virtual bool IsSelectable() const;

		virtual void SetSelectableState(bool selectableState);

		virtual bool IsDraggable() const;

		virtual void SetDraggableState(bool draggableState);

		virtual bool IsMouseOnControl() const;
		
		virtual bool ProcessMouseWheelScrolled(const DirtMachine::Input::Data::MouseWheelData& mouseWheelData) override;

		virtual bool ProcessMouseButtonPressed(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData) override;

		virtual bool ProcessMouseButtonReleased(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData) override;

		virtual bool ProcessMouseMoved(const DirtMachine::Input::Data::MouseMovementData& mouseMovementData) override;

	private:

		bool isSelectable;

		bool isDraggable;

		bool isMouseOnControl;
	};
}
