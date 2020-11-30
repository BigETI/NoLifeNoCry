#pragma once

#include <glm/vec2.hpp>
#include <Event.hpp>
#include <Input/Data/MouseButtonData.hpp>
#include <Input/Data/MouseMovementData.hpp>
#include <Input/Data/MouseWheelData.hpp>
#include <UI/Control.hpp>

namespace NoLifeNoCry::Engine::UI
{
	class InteractableControl : public NoLifeNoCry::Engine::UI::Control
	{
	public:

		NoLifeNoCry::Engine::Event<> OnMouseEntered;

		NoLifeNoCry::Engine::Event<> OnMouseLeft;

		NoLifeNoCry::Engine::Event<> OnMouseHovered;

		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::MouseButtonData> OnMouseButtonPressed;

		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::MouseButtonData> OnMouseButtonReleased;

		InteractableControl(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, bool isEnabled, bool isSelectable, bool isDraggable, NoLifeNoCry::Engine::UI::Control* parent);

		virtual ~InteractableControl();

		virtual bool IsSelectable() const;

		virtual void SetSelectable(bool selectableState);

		virtual bool IsDraggable() const;

		virtual void SetDraggable(bool draggableState);

		virtual bool IsMouseOnControl() const;
		
		virtual bool ProcessMouseWheelScrolled(const NoLifeNoCry::Engine::Input::Data::MouseWheelData& mouseWheelData) override;

		virtual bool ProcessMouseButtonPressed(const NoLifeNoCry::Engine::Input::Data::MouseButtonData& mouseButtonData) override;

		virtual bool ProcessMouseButtonReleased(const NoLifeNoCry::Engine::Input::Data::MouseButtonData& mouseButtonData) override;

		virtual bool ProcessMouseMoved(const NoLifeNoCry::Engine::Input::Data::MouseMovementData& mouseMovementData) override;

	private:

		bool isSelectable;

		bool isDraggable;

		bool isMouseOnControl;
	};
}
