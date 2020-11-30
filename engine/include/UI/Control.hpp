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

namespace NoLifeNoCry::Engine::UI
{
	class Control
	{
	public:

		NoLifeNoCry::Engine::Event<> OnTransformationChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnPrimaryBackgroundColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnSecondaryBackgroundColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnHighlightBackgroundColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnPrimaryForegroundColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnSecondaryForegroundColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnHighlightForegroundColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnPrimaryTextColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnSecondaryTextColourChanged;

		NoLifeNoCry::Engine::Event<const NoLifeNoCry::Engine::Graphic::Colour&> OnHighlightTextColourChanged;

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

		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetPrimaryBackgroundColour() const;

		virtual void SetPrimaryBackgroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetPrimaryBackgroundColour();

		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetSecondaryBackgroundColour() const;

		virtual void SetSecondaryBackgroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetSecondaryBackgroundColour();
		 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetHighlightBackgroundColour() const;

		virtual void SetHighlightBackgroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetHighlightBackgroundColour();
		 											 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetPrimaryForegroundColour() const;

		virtual void SetPrimaryForegroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetPrimaryForegroundColour();
		 											 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetSecondaryForegroundColour() const;

		virtual void SetSecondaryForegroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetSecondaryForegroundColour();
		 											 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetHighlightForegroundColour() const;

		virtual void SetHighlightForegroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetHighlightForegroundColour();
		 											 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetPrimaryTextColour() const;

		virtual void SetPrimaryTextColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetPrimaryTextColour();
		 											 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetSecondaryTextColour() const;

		virtual void SetSecondaryTextColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

		virtual void ResetSecondaryTextColour();
		 											 
		virtual const NoLifeNoCry::Engine::Graphic::Colour& GetHighlightTextColour() const;

		virtual void SetHighlightTextColour(const NoLifeNoCry::Engine::Graphic::Colour& colour);

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

		virtual void Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const;
		
		virtual bool ProcessTextEntered(const NoLifeNoCry::Engine::Input::Data::TextData& textData);

		virtual bool ProcessKeyPressed(const NoLifeNoCry::Engine::Input::Data::KeyboardKeyData& keyboardKeyData);
		
		virtual bool ProcessKeyReleased(const NoLifeNoCry::Engine::Input::Data::KeyboardKeyData& keyboardKeyData);

		virtual bool ProcessMouseWheelScrolled(const NoLifeNoCry::Engine::Input::Data::MouseWheelData& mouseWheelData);

		virtual bool ProcessMouseButtonPressed(const NoLifeNoCry::Engine::Input::Data::MouseButtonData& mouseButtonData);

		virtual bool ProcessMouseButtonReleased(const NoLifeNoCry::Engine::Input::Data::MouseButtonData& mouseButtonData);

		virtual bool ProcessMouseMoved(const NoLifeNoCry::Engine::Input::Data::MouseMovementData& mouseMovementData);
		
		virtual bool ProcessWindowMouseEntered();

		virtual bool ProcessWindowMouseLeft();

		virtual bool ProcessJoystickButtonPressed(const NoLifeNoCry::Engine::Input::Data::JoystickButtonData& joystickButtonData);
		
		virtual bool ProcessJoystickButtonReleased(const NoLifeNoCry::Engine::Input::Data::JoystickButtonData& joystickButtonData);

		virtual bool ProcessJoystickMoved(const NoLifeNoCry::Engine::Input::Data::JoystickMovementData& joystickMovementData);

		virtual bool ProcessJoystickConnected(const NoLifeNoCry::Engine::Input::Data::JoystickConnectionData& joystickConnectionData);

		virtual bool ProcessJoystickDisconnected(const NoLifeNoCry::Engine::Input::Data::JoystickConnectionData& joystickConnectionData);

		virtual bool ProcessTouchBegan(const NoLifeNoCry::Engine::Input::Data::TouchData& touchData);

		virtual bool ProcessTouchMoved(const NoLifeNoCry::Engine::Input::Data::TouchData& touchData);

		virtual bool ProcessTouchEnded(const NoLifeNoCry::Engine::Input::Data::TouchData& touchData);

		virtual bool ProcessSensorChanged(const NoLifeNoCry::Engine::Input::Data::SensorData& sensorData);

		Control& operator=(const Control&) = delete;
		Control& operator=(Control&&) = delete;

	protected:

		virtual void PushDrawingState(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget);

		virtual void PopDrawingState(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget);

	private:

		static NoLifeNoCry::Engine::Graphic::Colour defaultPrimaryBackgroundColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultSecondaryBackgroundColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultHighlightBackgroundColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultPrimaryForegroundColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultSecondaryForegroundColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultHighlightForegroundColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultPrimaryTextColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultSecondaryTextColour;

		static NoLifeNoCry::Engine::Graphic::Colour defaultHighlightTextColour;

		glm::ivec2 position;

		float rotation;

		glm::uvec2 size;

		bool isVisible;

		bool isEnabled;

		NoLifeNoCry::Engine::Graphic::Colour* primaryBackgroundColour;

		NoLifeNoCry::Engine::Graphic::Colour* secondaryBackgroundColour;

		NoLifeNoCry::Engine::Graphic::Colour* highlightBackgroundColour;

		NoLifeNoCry::Engine::Graphic::Colour* primaryForegroundColour;

		NoLifeNoCry::Engine::Graphic::Colour* secondaryForegroundColour;

		NoLifeNoCry::Engine::Graphic::Colour* highlightForegroundColour;

		NoLifeNoCry::Engine::Graphic::Colour* primaryTextColour;

		NoLifeNoCry::Engine::Graphic::Colour* secondaryTextColour;

		NoLifeNoCry::Engine::Graphic::Colour* highlightTextColour;

		Control* parent;

		std::vector<std::shared_ptr<Control>> children;

		sf::View originalView;
	};
}
