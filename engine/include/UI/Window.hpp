#pragma once

#include <chrono>
#include <cstdint>
#include <list>
#include <map>
#include <memory>
#include <glm/vec2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <EExitCode.hpp>
#include <EWindowStyle.hpp>
#include <Event.hpp>
#include <Graphic/Font.hpp>
#include <Graphic/Renderer.hpp>
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
#include <Scripting/Scene.hpp>
#include <String.hpp>
#include <UI/Control.hpp>
#include <WindowHandle.hpp>

/// @brief Dirt Machine game engine UI namespace
namespace DirtMachine::UI
{
	/// @brief Window class
	class Window : sf::RenderWindow, DirtMachine::UI::Control
	{
	public:

		/// @brief On window started
		DirtMachine::Event<> OnWindowStarted;

		/// @brief On window stopped
		DirtMachine::Event<> OnWindowStopped;

		/// @brief On window messages processed
		DirtMachine::Event<double> OnWindowMessagesProcessed;

		/// @brief On window closed
		DirtMachine::Event<> OnWindowClosed;

		/// @brief On window resized
		DirtMachine::Event<std::size_t, std::size_t> OnWindowResized;

		/// @brief On focus lost
		DirtMachine::Event<> OnFocusLost;

		/// @brief On focus gained
		DirtMachine::Event<> OnFocusGained;

		/// @brief On text entered
		DirtMachine::Event<DirtMachine::Input::Data::TextData> OnTextEntered;

		/// @brief On keyboard key pressed
		DirtMachine::Event<DirtMachine::Input::Data::KeyboardKeyData> OnKeyboardKeyPressed;

		/// @brief On keyboard key released
		DirtMachine::Event<DirtMachine::Input::Data::KeyboardKeyData> OnKeyboardKeyReleased;

		/// @brief On mouse wheel scrolled
		DirtMachine::Event<DirtMachine::Input::Data::MouseWheelData> OnMouseWheelScrolled;

		/// @brief On mouse button pressed
		DirtMachine::Event<DirtMachine::Input::Data::MouseButtonData> OnMouseButtonPressed;

		/// @brief On mouse button released
		DirtMachine::Event<DirtMachine::Input::Data::MouseButtonData> OnMouseButtonReleased;

		/// @brief On mouse moved
		DirtMachine::Event<DirtMachine::Input::Data::MouseMovementData> OnMouseMoved;

		/// @brief On mouse entered
		DirtMachine::Event<> OnMouseEntered;

		/// @brief On mouse left
		DirtMachine::Event<> OnMouseLeft;

		/// @brief On joystick button pressed
		DirtMachine::Event<DirtMachine::Input::Data::JoystickButtonData> OnJoystickButtonPressed;

		/// @brief On joystick button released
		DirtMachine::Event<DirtMachine::Input::Data::JoystickButtonData> OnJoystickButtonReleased;

		/// @brief On joystick moved
		DirtMachine::Event<DirtMachine::Input::Data::JoystickMovementData> OnJoystickMoved;

		/// @brief On joystick connected
		DirtMachine::Event<DirtMachine::Input::Data::JoystickConnectionData> OnJoystickConnected;

		/// @brief On joystick disconnected
		DirtMachine::Event<DirtMachine::Input::Data::JoystickConnectionData> OnJoystickDisconnected;

		/// @brief On touch began
		DirtMachine::Event<DirtMachine::Input::Data::TouchData> OnTouchBegan;

		/// @brief On touch moved
		DirtMachine::Event<DirtMachine::Input::Data::TouchData> OnTouchMoved;

		/// @brief On touch ended
		DirtMachine::Event<DirtMachine::Input::Data::TouchData> OnTouchEnded;

		/// @brief On sensor changed
		DirtMachine::Event<DirtMachine::Input::Data::SensorData> OnSensorChanged;

		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		Window(std::size_t width, std::size_t height, const DirtMachine::String& title, DirtMachine::EWindowStyle style);

		/// @brief Destructor
		virtual ~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;

		/// @brief Creates a window
		void Create();

		/// @brief Is window open
		/// @return "true" if window is open (not to be confused with is window showing), otherwise "false"
		bool IsOpen() const;

		/// @brief Close window
		void Close();

		/// @brief Get window handle
		/// @return Window handle
		DirtMachine::WindowHandle GetWindowHandle() const;

		/// @brief Get window size
		/// @return Window size
		glm::uvec2 GetSize() const;

		/// @brief Set window size
		/// @param newSize New window size
		void SetSize(const glm::uvec2& newSize) override;

		/// @brief Get user interface
		/// @return User interface
		DirtMachine::UI::Control& GetUI();

		/// @brief Refresh window
		/// @return "true" if messages have been successfully processed, otherwise "false"
		bool Refresh();

		/// @brief Process messages
		/// @return "true" if messages have been successfully processed, otherwise "false"
		bool ProcessMessages();

		/// @brief Draw
		void Draw();

		/// @brief Start window process
		/// @return Exit code
		DirtMachine::EExitCode Start();

		/// @brief Get default font
		/// @return 
		virtual const DirtMachine::Graphic::Font* GetDefaultFont() const;
		
		/// @brief Add scene
		/// @param sceneID Scene ID
		/// @return Scene if successfull, otherwise "null"
		virtual std::shared_ptr<DirtMachine::Scripting::Scene> AddScene(const DirtMachine::String& sceneID);

		/// @brief Gets scene by scene ID
		/// @param sceneID Scene ID
		/// @return Scene if successful, otherwise "null"
		virtual std::shared_ptr<DirtMachine::Scripting::Scene> GetScene(const DirtMachine::String& sceneID) const;

		/// @brief Require scene
		/// @param sceneID Scene ID
		/// @return Scene
		/// @summary Creates scene if it does not exist
		virtual std::shared_ptr<DirtMachine::Scripting::Scene> RequireScene(const DirtMachine::String& sceneID);

		/// @brief Removes scene by scene ID
		/// @param sceneID Scene ID
		/// @return "true" if successful, otherwise "false"
		bool RemoveScene(const DirtMachine::String& sceneID);

		/// @brief Gets the current renderer
		/// @return Current renderer
		virtual DirtMachine::Graphic::Renderer& GetRenderer();

		/// @brief Gets the current renderer
		/// @return Renderer
		virtual const DirtMachine::Graphic::Renderer& GetRenderer() const;

		template <typename T>
		std::shared_ptr<T> CreateWindow(std::size_t width, std::size_t height, const DirtMachine::String& title, DirtMachine::EWindowStyle style)
		{
			static_assert(std::is_convertible<T*, DirtMachine::UI::Window*>::value, "Children type must inherit from \"Control\".");
			std::shared_ptr<T> ret(std::make_shared<T>(width, height, title, style));
			startingWindows.push_back(ret);
			return ret;
		}

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
		DirtMachine::String title;

		/// @brief Window style
		DirtMachine::EWindowStyle style;

		/// @brief Default font
		DirtMachine::Graphic::Font defaultFont;

		/// @brief Last messages processed time point
		std::chrono::high_resolution_clock::time_point lastMessagesProcessedTimePoint;

		/// @brief Is mouse on window
		bool isMouseOnWindow;

		/// @brief Last mouse position
		glm::ivec2 lastMousePosition;

		/// @brief Scenes
		std::map<DirtMachine::String, std::shared_ptr<DirtMachine::Scripting::Scene>> scenes;

		/// @brief Renderer
		DirtMachine::Graphic::Renderer renderer;

		/// @brief Starting windows
		std::list<std::shared_ptr<DirtMachine::UI::Window>> startingWindows;

		/// @brief Windows
		std::list<std::shared_ptr<DirtMachine::UI::Window>> windows;
	};
}
