#pragma once

#include <string>
#include <SFML/Window.hpp>

#include "EWindowStyle.hpp"
#include "Event.hpp"
#include "JoystickButtonData.hpp"
#include "JoystickConnectionData.hpp"
#include "JoystickMovementData.hpp"
#include "KeyboardKeyData.hpp"
#include "MouseButtonData.hpp"
#include "MouseMovementData.hpp"
#include "MouseWheelData.hpp"
#include "SensorData.hpp"
#include "TextData.hpp"
#include "TouchData.hpp"

/// @brief No Life, No Cry engine namespace
namespace NoLifeNoCry::Engine
{
	/// @brief Window class
	class Window : sf::Window
	{
	public:

		/// @brief On window closed
		NoLifeNoCry::Engine::Event<> OnWindowClosed;

		/// @brief On window resized
		NoLifeNoCry::Engine::Event<std::size_t, std::size_t> OnWindowResized;

		/// @brief On focus lost
		NoLifeNoCry::Engine::Event<> OnFocusLost;

		/// @brief On focus gained
		NoLifeNoCry::Engine::Event<> OnFocusGained;

		/// @brief On text entered
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::TextData> OnTextEntered;

		/// @brief On keyboard key pressed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::KeyboardKeyData> OnKeyboardKeyPressed;

		/// @brief On keyboard key released
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::KeyboardKeyData> OnKeyboardKeyReleased;

		/// @brief On mouse wheel scrolled
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::MouseWheelData> OnMouseWheelScrolled;

		/// @brief On mouse button pressed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::MouseButtonData> OnMouseButtonPressed;

		/// @brief On mouse button released
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::MouseButtonData> OnMouseButtonReleased;

		/// @brief On mouse moved
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::MouseMovementData> OnMouseMoved;

		/// @brief On mouse entered
		NoLifeNoCry::Engine::Event<> OnMouseEntered;

		/// @brief On mouse left
		NoLifeNoCry::Engine::Event<> OnMouseLeft;

		/// @brief On joystick button pressed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::JoystickButtonData> OnJoystickButtonPressed;

		/// @brief On joystick button released
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::JoystickButtonData> OnJoystickButtonReleased;

		/// @brief On joystick moved
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::JoystickMovementData> OnJoystickMoved;

		/// @brief On joystick connected
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::JoystickConnectionData> OnJoystickConnected;

		/// @brief On joystick disconnected
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::JoystickConnectionData> OnJoystickDisconnected;

		/// @brief On touch began
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::TouchData> OnTouchBegan;

		/// @brief On touch moved
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::TouchData> OnTouchMoved;

		/// @brief On touch ended
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::TouchData> OnTouchEnded;

		/// @brief On sensor changed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::SensorData> OnSensorChanged;

		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		Window(std::size_t width, std::size_t height, const std::string& title, NoLifeNoCry::Engine::EWindowStyle style);

		/// @brief Destructor
		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;

		/// @brief Creates a window
		void Create();

		/// @brief Is window open
		/// @return "true" if window is open (not to be confused with is window showing), otherwise "false"
		bool IsOpen() const;

		/// @brief Has window focus
		/// @return "true" if window has focus, otherwise "false"
		bool HasFocus() const;

		/// @brief Process messages
		/// @return "true" if messages have been successfully processed, otherwise "false"
		bool ProcessMessages();

		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

	private:

		/// @brief Window title
		std::string title;

		/// @brief Window style
		NoLifeNoCry::Engine::EWindowStyle style;
	};
}
