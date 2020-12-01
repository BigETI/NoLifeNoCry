#pragma once

#include <type_traits>
#include <memory>
#include <vector>
#include <glm/vec2.hpp>
#include <Event.hpp>
#include <Input/Data/JoystickButtonData.hpp>
#include <Input/Data/JoystickConnectionData.hpp>
#include <Input/Data/JoystickMovementData.hpp>
#include <Input/Data/KeyboardKeyData.hpp>
#include <Input/Data/MouseButtonData.hpp>
#include <Input/Data/MouseMovementData.hpp>
#include <Input/Data/MouseWheelData.hpp>
#include <Input/Data/SensorData.hpp>
#include <Input/Data/TextData.hpp>
#include <Input/Data/TouchData.hpp>
#include <Graphic/Colour.hpp>
#include <Graphic/RenderTarget.hpp>

namespace DirtMachine::UI
{
	class Control
	{
	public:

		DirtMachine::Event<> OnTransformationChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnPrimaryBackgroundColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnSecondaryBackgroundColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnHighlightBackgroundColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnPrimaryForegroundColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnSecondaryForegroundColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnHighlightForegroundColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnPrimaryTextColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnSecondaryTextColourChanged;

		DirtMachine::Event<const DirtMachine::Graphic::Colour&> OnHighlightTextColourChanged;

		Control() = delete;
		Control(const Control&) = delete;
		Control(Control&&) = delete;

		Control(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, bool isEnabled, Control* parent = nullptr);

		virtual ~Control();

		virtual const glm::ivec2& GetLocalPosition() const;

		virtual void SetLocalPosition(const glm::ivec2& newPosition);

		virtual glm::ivec2 GetGlobalPosition() const;

		virtual void SetGlobalPosition(const glm::ivec2& newPosition);

		virtual glm::uvec2 GetSize() const;

		virtual void SetSize(const glm::uvec2& newSize);

		virtual bool IsVisible() const;

		virtual void SetVisible(bool visibleState);

		virtual bool IsEnabled() const;

		virtual void SetEnabled(bool enabledState);

		virtual const DirtMachine::Graphic::Colour& GetPrimaryBackgroundColour() const;

		virtual void SetPrimaryBackgroundColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetPrimaryBackgroundColour();

		virtual const DirtMachine::Graphic::Colour& GetSecondaryBackgroundColour() const;

		virtual void SetSecondaryBackgroundColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetSecondaryBackgroundColour();
		 
		virtual const DirtMachine::Graphic::Colour& GetHighlightBackgroundColour() const;

		virtual void SetHighlightBackgroundColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetHighlightBackgroundColour();
		 											 
		virtual const DirtMachine::Graphic::Colour& GetPrimaryForegroundColour() const;

		virtual void SetPrimaryForegroundColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetPrimaryForegroundColour();
		 											 
		virtual const DirtMachine::Graphic::Colour& GetSecondaryForegroundColour() const;

		virtual void SetSecondaryForegroundColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetSecondaryForegroundColour();
		 											 
		virtual const DirtMachine::Graphic::Colour& GetHighlightForegroundColour() const;

		virtual void SetHighlightForegroundColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetHighlightForegroundColour();
		 											 
		virtual const DirtMachine::Graphic::Colour& GetPrimaryTextColour() const;

		virtual void SetPrimaryTextColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetPrimaryTextColour();
		 											 
		virtual const DirtMachine::Graphic::Colour& GetSecondaryTextColour() const;

		virtual void SetSecondaryTextColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetSecondaryTextColour();
		 											 
		virtual const DirtMachine::Graphic::Colour& GetHighlightTextColour() const;

		virtual void SetHighlightTextColour(const DirtMachine::Graphic::Colour& colour);

		virtual void ResetHighlightTextColour();

		bool HasParent() const;

		Control* GetParent() const;

		std::size_t GetChildCount() const;

		Control& GetChild(std::size_t index);

		const Control& GetChild(std::size_t index) const;

		template <typename T, typename... TArguments>
		std::shared_ptr<T> CreateChild(TArguments... arguments)
		{
			static_assert(std::is_convertible<T*, Control*>::value, "Children type must inherit from \"Control\".");
			std::shared_ptr<T> ret(std::make_shared<T>(std::forward<TArguments>(arguments)..., this));
			children.push_back(ret);
			return ret;
		}

		template <typename T>
		bool RemoveChild(std::shared_ptr<T> child)
		{
			bool ret(false);
			for (std::size_t index(static_cast<std::size_t>(0)), move_index; index != children.size(); index++)
			{
				if (children[index] == child)
				{
					for (move_index = static_cast<std::size_t>(index); (move_index + static_cast<std::size_t>(1)) != children.size(); move_index++)
					{
						children[move_index] = children[move_index + static_cast<std::size_t>(1)];
					}
					children.pop_back();
					break;
				}
			}
			return ret;
		}

		/// @brief Is mouse on window
		/// @return "true" is mouse is on window, otherwise "false"
		virtual bool IsMouseOnWindow() const;

		virtual bool IsWindowFocused() const;

		virtual glm::ivec2 GetMousePosition() const;

		virtual void Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const;
		
		virtual bool ProcessTextEntered(const DirtMachine::Input::Data::TextData& textData);

		virtual bool ProcessKeyPressed(const DirtMachine::Input::Data::KeyboardKeyData& keyboardKeyData);
		
		virtual bool ProcessKeyReleased(const DirtMachine::Input::Data::KeyboardKeyData& keyboardKeyData);

		virtual bool ProcessMouseWheelScrolled(const DirtMachine::Input::Data::MouseWheelData& mouseWheelData);

		virtual bool ProcessMouseButtonPressed(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData);

		virtual bool ProcessMouseButtonReleased(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData);

		virtual bool ProcessMouseMoved(const DirtMachine::Input::Data::MouseMovementData& mouseMovementData);
		
		virtual bool ProcessWindowMouseEntered();

		virtual bool ProcessWindowMouseLeft();

		virtual bool ProcessJoystickButtonPressed(const DirtMachine::Input::Data::JoystickButtonData& joystickButtonData);
		
		virtual bool ProcessJoystickButtonReleased(const DirtMachine::Input::Data::JoystickButtonData& joystickButtonData);

		virtual bool ProcessJoystickMoved(const DirtMachine::Input::Data::JoystickMovementData& joystickMovementData);

		virtual bool ProcessJoystickConnected(const DirtMachine::Input::Data::JoystickConnectionData& joystickConnectionData);

		virtual bool ProcessJoystickDisconnected(const DirtMachine::Input::Data::JoystickConnectionData& joystickConnectionData);

		virtual bool ProcessTouchBegan(const DirtMachine::Input::Data::TouchData& touchData);

		virtual bool ProcessTouchMoved(const DirtMachine::Input::Data::TouchData& touchData);

		virtual bool ProcessTouchEnded(const DirtMachine::Input::Data::TouchData& touchData);

		virtual bool ProcessSensorChanged(const DirtMachine::Input::Data::SensorData& sensorData);

		Control& operator=(const Control&) = delete;
		Control& operator=(Control&&) = delete;

	protected:

		virtual void PushDrawingState(DirtMachine::Graphic::RenderTarget& renderTarget);

		virtual void PopDrawingState(DirtMachine::Graphic::RenderTarget& renderTarget);

	private:

		static DirtMachine::Graphic::Colour defaultPrimaryBackgroundColour;

		static DirtMachine::Graphic::Colour defaultSecondaryBackgroundColour;

		static DirtMachine::Graphic::Colour defaultHighlightBackgroundColour;

		static DirtMachine::Graphic::Colour defaultPrimaryForegroundColour;

		static DirtMachine::Graphic::Colour defaultSecondaryForegroundColour;

		static DirtMachine::Graphic::Colour defaultHighlightForegroundColour;

		static DirtMachine::Graphic::Colour defaultPrimaryTextColour;

		static DirtMachine::Graphic::Colour defaultSecondaryTextColour;

		static DirtMachine::Graphic::Colour defaultHighlightTextColour;

		glm::ivec2 position;

		float rotation;

		glm::uvec2 size;

		bool isVisible;

		bool isEnabled;

		DirtMachine::Graphic::Colour* primaryBackgroundColour;

		DirtMachine::Graphic::Colour* secondaryBackgroundColour;

		DirtMachine::Graphic::Colour* highlightBackgroundColour;

		DirtMachine::Graphic::Colour* primaryForegroundColour;

		DirtMachine::Graphic::Colour* secondaryForegroundColour;

		DirtMachine::Graphic::Colour* highlightForegroundColour;

		DirtMachine::Graphic::Colour* primaryTextColour;

		DirtMachine::Graphic::Colour* secondaryTextColour;

		DirtMachine::Graphic::Colour* highlightTextColour;

		Control* parent;

		std::vector<std::shared_ptr<Control>> children;

		sf::View originalView;
	};
}
