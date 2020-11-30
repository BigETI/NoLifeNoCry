#pragma once

#include <chrono>
#include <string>
#include <glm/vec2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <EExitCode.hpp>
#include <EWindowStyle.hpp>
#include <Event.hpp>
#include <Graphic/Font.hpp>
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
#include <UI/Control.hpp>
#include <WindowHandle.hpp>

/// @brief No Life, No Cry engine UI namespace
namespace NoLifeNoCry::Engine::UI
{
	/// @brief Window class
	class Window : sf::RenderWindow, NoLifeNoCry::Engine::UI::Control
	{
	public:

		/// @brief On window started
		NoLifeNoCry::Engine::Event<> OnWindowStarted;

		/// @brief On window stopped
		NoLifeNoCry::Engine::Event<> OnWindowStopped;

		/// @brief On window messages processed
		NoLifeNoCry::Engine::Event<double> OnWindowMessagesProcessed;

		/// @brief On window closed
		NoLifeNoCry::Engine::Event<> OnWindowClosed;

		/// @brief On window resized
		NoLifeNoCry::Engine::Event<std::size_t, std::size_t> OnWindowResized;

		/// @brief On focus lost
		NoLifeNoCry::Engine::Event<> OnFocusLost;

		/// @brief On focus gained
		NoLifeNoCry::Engine::Event<> OnFocusGained;

		/// @brief On text entered
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::TextData> OnTextEntered;

		/// @brief On keyboard key pressed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::KeyboardKeyData> OnKeyboardKeyPressed;

		/// @brief On keyboard key released
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::KeyboardKeyData> OnKeyboardKeyReleased;

		/// @brief On mouse wheel scrolled
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::MouseWheelData> OnMouseWheelScrolled;

		/// @brief On mouse button pressed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::MouseButtonData> OnMouseButtonPressed;

		/// @brief On mouse button released
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::MouseButtonData> OnMouseButtonReleased;

		/// @brief On mouse moved
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::MouseMovementData> OnMouseMoved;

		/// @brief On mouse entered
		NoLifeNoCry::Engine::Event<> OnMouseEntered;

		/// @brief On mouse left
		NoLifeNoCry::Engine::Event<> OnMouseLeft;

		/// @brief On joystick button pressed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::JoystickButtonData> OnJoystickButtonPressed;

		/// @brief On joystick button released
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::JoystickButtonData> OnJoystickButtonReleased;

		/// @brief On joystick moved
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::JoystickMovementData> OnJoystickMoved;

		/// @brief On joystick connected
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::JoystickConnectionData> OnJoystickConnected;

		/// @brief On joystick disconnected
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::JoystickConnectionData> OnJoystickDisconnected;

		/// @brief On touch began
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::TouchData> OnTouchBegan;

		/// @brief On touch moved
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::TouchData> OnTouchMoved;

		/// @brief On touch ended
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::TouchData> OnTouchEnded;

		/// @brief On sensor changed
		NoLifeNoCry::Engine::Event<NoLifeNoCry::Engine::Input::Data::SensorData> OnSensorChanged;

		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		Window(std::size_t width, std::size_t height, const std::string& title, NoLifeNoCry::Engine::EWindowStyle style);

		/// @brief Destructor
		virtual ~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;

		/// @brief Creates a window
		void Create();

		/// @brief Is window open
		/// @return "true" if window is open (not to be confused with is window showing), otherwise "false"
		bool IsOpen() const;

		/// @brief Get window handle
		/// @return Window handle
		NoLifeNoCry::Engine::WindowHandle GetWindowHandle() const;

		/// @brief Get window size
		/// @return Window size
		glm::uvec2 GetSize() const;

		/// @brief Set window size
		/// @param newSize New window size
		void SetSize(const glm::uvec2& newSize) override;

		/// @brief Get user interface
		/// @return User interface
		NoLifeNoCry::Engine::UI::Control& GetUI();

		/// @brief Process messages
		/// @return "true" if messages have been successfully processed, otherwise "false"
		bool ProcessMessages();

		/// @brief Draw
		void Draw();

		/// @brief Start window process
		/// @return Exit code
		NoLifeNoCry::Engine::EExitCode Start();

		/// @brief Get default font
		/// @return 
		virtual const NoLifeNoCry::Engine::Graphic::Font* GetDefaultFont() const;

		/// @brief Is mouse on window
		/// @return "true" is mouse is on window, otherwise "false"
		virtual bool IsMouseOnWindow() const override;

		/// @brief Is window focused
		/// @return "true" is window is focused, otherwise "false"
		virtual bool IsWindowFocused() const override;

		/// @brief Get mouse position
		/// @return Mouse position
		virtual glm::ivec2 GetMousePosition() const override;

		/// @brief Process mouse entering window event
		/// @return "true" if event is being handled by this control, otherwise "false"
		virtual bool ProcessWindowMouseEntered() override;

		/// @brief Process mouse leaving window event
		/// @return "true" if event is being handled by this control, otherwise "false"
		virtual bool ProcessWindowMouseLeft() override;

		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

	private:

		/// @brief Window title
		std::string title;

		/// @brief Window style
		NoLifeNoCry::Engine::EWindowStyle style;

		/// @brief Default font
		NoLifeNoCry::Engine::Graphic::Font defaultFont;

		/// @brief Last messages processed time point
		std::chrono::high_resolution_clock::time_point lastMessagesProcessedTimePoint;

		/// @brief Is mouse on window
		bool isMouseOnWindow;

		/// @brief Last mouse position
		glm::ivec2 lastMousePosition;
	};
}
