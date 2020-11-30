#include <filesystem>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <UI/Window.hpp>

/// @brief Constructor
/// @param windowWidth Window width
/// @param windowHeight Window height
/// @param windowName Window name
/// @param windowStyle Window style
NoLifeNoCry::Engine::UI::Window::Window(std::size_t width, std::size_t height, const std::string& title, NoLifeNoCry::Engine::EWindowStyle style) :
	sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), title, static_cast<sf::Uint32>(style)), NoLifeNoCry::Engine::UI::Control({ 0, 0 }, 0.0f, GetSize(), true, true),
	title(title),
	style(style),
	lastMessagesProcessedTimePoint(std::chrono::high_resolution_clock::now()),
	isMouseOnWindow(false)
{
	sf::Vector2u window_size(getSize());
	NoLifeNoCry::Engine::UI::Control::SetSize({ window_size.x, window_size.y });
	if (!defaultFont.loadFromFile("./defaults/Roboto/Roboto-Regular.ttf"))
	{
		throw std::filesystem::filesystem_error("Failed to open font file.", "./defaults/Roboto/Roboto-Regular.ttf", "", std::error_code());
	}
}

/// @brief Destructor
NoLifeNoCry::Engine::UI::Window::~Window()
{
	// ...
}

/// @brief Shows a window
void NoLifeNoCry::Engine::UI::Window::Create()
{
	sf::Vector2u window_size(getSize());
	create(sf::VideoMode(window_size.x, window_size.y), title, static_cast<sf::Uint32>(style));
}

/// @brief Is window open
/// @return "true" if window is open (not to be confused with is window showing), otherwise "false"
bool NoLifeNoCry::Engine::UI::Window::IsOpen() const
{
	return isOpen();
}

/// @brief Get window handle
/// @return Window handle
NoLifeNoCry::Engine::WindowHandle NoLifeNoCry::Engine::UI::Window::GetWindowHandle() const
{
	return getSystemHandle();
}

/// @brief Get window size
/// @return Window size
glm::uvec2 NoLifeNoCry::Engine::UI::Window::GetSize() const
{
	return NoLifeNoCry::Engine::UI::Control::GetSize();
}

/// @brief Set window size
/// @param newSize New window size
void NoLifeNoCry::Engine::UI::Window::SetSize(const glm::uvec2& newSize)
{
	NoLifeNoCry::Engine::UI::Control::SetSize(newSize);
	setSize({ newSize.x, newSize.y });
}

/// @brief Get user interface
/// @return User interface
NoLifeNoCry::Engine::UI::Control& NoLifeNoCry::Engine::UI::Window::GetUI()
{
	return *this;
}

/// @brief Process messages
/// @return "true" if messages have been successfully processed, otherwise "false"
bool NoLifeNoCry::Engine::UI::Window::ProcessMessages()
{
	bool ret(isOpen());
	if (ret)
	{
		sf::Event event;
		sf::View view;
		sf::FloatRect viewport;
		while (pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				OnWindowClosed();
				close();
				break;
			case sf::Event::Resized:
				NoLifeNoCry::Engine::UI::Control::SetSize({ static_cast<std::size_t>(event.size.width), static_cast<std::size_t>(event.size.height) });
				setSize({ event.size.width, event.size.height });
				view = getView();
				view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
				view.setCenter(static_cast<float>(event.size.width) * 0.5f, static_cast<float>(event.size.height) * 0.5f);
				setView(view);
				OnWindowResized(static_cast<std::size_t>(event.size.width), static_cast<std::size_t>(event.size.height));
				break;
			case sf::Event::LostFocus:
				OnFocusLost();
				break;
			case sf::Event::GainedFocus:
				OnFocusGained();
				break;
			case sf::Event::TextEntered:
				NoLifeNoCry::Engine::Input::Data::TextData text_data({ static_cast<std::uint32_t>(event.text.unicode) });
				ProcessTextEntered(text_data);
				OnTextEntered(text_data);
				break;
			case sf::Event::KeyPressed:
				NoLifeNoCry::Engine::Input::Data::KeyboardKeyData keyboard_key_pressed_data({ static_cast<NoLifeNoCry::Engine::Input::EKeyboardKey>(event.key.code), event.key.alt, event.key.control, event.key.shift, event.key.system });
				ProcessKeyPressed(keyboard_key_pressed_data);
				OnKeyboardKeyPressed(keyboard_key_pressed_data);
				break;
			case sf::Event::KeyReleased:
				NoLifeNoCry::Engine::Input::Data::KeyboardKeyData keyboard_key_released_data({ static_cast<NoLifeNoCry::Engine::Input::EKeyboardKey>(event.key.code), event.key.alt, event.key.control, event.key.shift, event.key.system });
				ProcessKeyReleased(keyboard_key_released_data);
				OnKeyboardKeyReleased(keyboard_key_released_data);
				break;
			case sf::Event::MouseWheelScrolled:
				lastMousePosition = glm::ivec2(event.mouseWheelScroll.x, event.mouseWheelScroll.y);
				NoLifeNoCry::Engine::Input::Data::MouseWheelData mouse_wheel_data({ static_cast<NoLifeNoCry::Engine::Input::EMouseWheel>(event.mouseWheelScroll.wheel), event.mouseWheelScroll.delta, lastMousePosition });
				ProcessMouseWheelScrolled(mouse_wheel_data);
				OnMouseWheelScrolled(mouse_wheel_data);
				break;
			case sf::Event::MouseButtonPressed:
				lastMousePosition = glm::ivec2(event.mouseButton.x, event.mouseButton.y);
				NoLifeNoCry::Engine::Input::Data::MouseButtonData mouse_button_pressed_data({ static_cast<NoLifeNoCry::Engine::Input::EMouseButton>(event.mouseButton.button), lastMousePosition });
				ProcessMouseButtonPressed(mouse_button_pressed_data);
				OnMouseButtonPressed(mouse_button_pressed_data);
				break;
			case sf::Event::MouseButtonReleased:
				lastMousePosition = glm::ivec2(event.mouseButton.x, event.mouseButton.y);
				NoLifeNoCry::Engine::Input::Data::MouseButtonData mouse_button_released_data({ static_cast<NoLifeNoCry::Engine::Input::EMouseButton>(event.mouseButton.button), lastMousePosition });
				ProcessMouseButtonReleased(mouse_button_released_data);
				OnMouseButtonReleased(mouse_button_released_data);
				break;
			case sf::Event::MouseMoved:
				lastMousePosition = glm::ivec2(event.mouseMove.x, event.mouseMove.y);
				NoLifeNoCry::Engine::Input::Data::MouseMovementData mouse_movement_data({ lastMousePosition });
				ProcessMouseMoved(mouse_movement_data);
				OnMouseMoved(mouse_movement_data);
				break;
			case sf::Event::MouseEntered:
				isMouseOnWindow = true;
				ProcessWindowMouseEntered();
				OnMouseEntered();
				break;
			case sf::Event::MouseLeft:
				isMouseOnWindow = false;
				ProcessWindowMouseLeft();
				OnMouseLeft();
				break;
			case sf::Event::JoystickButtonPressed:
				NoLifeNoCry::Engine::Input::Data::JoystickButtonData joystick_button_pressed_data({ event.joystickButton.joystickId, event.joystickButton.button });
				ProcessJoystickButtonPressed(joystick_button_pressed_data);
				OnJoystickButtonPressed(joystick_button_pressed_data);
				break;
			case sf::Event::JoystickButtonReleased:
				NoLifeNoCry::Engine::Input::Data::JoystickButtonData joystick_button_released_data({ event.joystickButton.joystickId, event.joystickButton.button });
				ProcessJoystickButtonReleased(joystick_button_released_data);
				OnJoystickButtonReleased(joystick_button_released_data);
				break;
			case sf::Event::JoystickMoved:
				NoLifeNoCry::Engine::Input::Data::JoystickMovementData joystick_movement_data({ event.joystickMove.joystickId, static_cast<NoLifeNoCry::Engine::Input::EJoystickAxis>(event.joystickMove.axis), event.joystickMove.position });
				ProcessJoystickMoved(joystick_movement_data);
				OnJoystickMoved(joystick_movement_data);
				break;
			case sf::Event::JoystickConnected:
				NoLifeNoCry::Engine::Input::Data::JoystickConnectionData joystick_connection_connected_data({ event.joystickConnect.joystickId });
				ProcessJoystickConnected(joystick_connection_connected_data);
				OnJoystickConnected(joystick_connection_connected_data);
				break;
			case sf::Event::JoystickDisconnected:
				NoLifeNoCry::Engine::Input::Data::JoystickConnectionData joystick_connection_disconnected_data({ event.joystickConnect.joystickId });
				ProcessJoystickDisconnected(joystick_connection_disconnected_data);
				OnJoystickDisconnected(joystick_connection_disconnected_data);
				break;
			case sf::Event::TouchBegan:
				NoLifeNoCry::Engine::Input::Data::TouchData touch_began_data({ event.touch.finger, { event.touch.x, event.touch.y } });
				ProcessTouchBegan(touch_began_data);
				OnTouchBegan(touch_began_data);
				break;
			case sf::Event::TouchMoved:
				NoLifeNoCry::Engine::Input::Data::TouchData touch_moved_data({ event.touch.finger, { event.touch.x, event.touch.y } });
				ProcessTouchMoved(touch_moved_data);
				OnTouchMoved(touch_moved_data);
				break;
			case sf::Event::TouchEnded:
				NoLifeNoCry::Engine::Input::Data::TouchData touch_ended_data({ event.touch.finger, { event.touch.x, event.touch.y } });
				ProcessTouchEnded(touch_moved_data);
				OnTouchEnded(touch_ended_data);
				break;
			case sf::Event::SensorChanged:
				NoLifeNoCry::Engine::Input::Data::SensorData sensor_changed_data({ static_cast<NoLifeNoCry::Engine::Input::ESensorType>(event.sensor.type), { event.sensor.x, event.sensor.y, event.sensor.z } });
				ProcessSensorChanged(sensor_changed_data);
				OnSensorChanged(sensor_changed_data);
				break;
			}
		}
		std::chrono::high_resolution_clock::time_point now(std::chrono::high_resolution_clock::now());
		const auto& delta(now - lastMessagesProcessedTimePoint);
		lastMessagesProcessedTimePoint = now;
		OnWindowMessagesProcessed(delta.count() * 0.000000001);
	}
	return ret;
}

/// @brief Draw
void NoLifeNoCry::Engine::UI::Window::Draw()
{
	clear(sf::Color(10, 10, 10));
	//clear();
	PushDrawingState(*this);
	NoLifeNoCry::Engine::UI::Control::Draw(*this);
	PopDrawingState(*this);
	display();
}

/// @brief Start editor
/// @return Exit code
NoLifeNoCry::Engine::EExitCode NoLifeNoCry::Engine::UI::Window::Start()
{
	NoLifeNoCry::Engine::EExitCode ret(NoLifeNoCry::Engine::EExitCode::FailedCreatingWindow);
	if (IsOpen())
	{

		ret = NoLifeNoCry::Engine::EExitCode::Success;
		OnWindowStarted();
		while (ProcessMessages())
		{
			Draw();
		}
		OnWindowStopped();
	}
	return ret;
}

/// @brief Get default font
/// @return 
const NoLifeNoCry::Engine::Graphic::Font* NoLifeNoCry::Engine::UI::Window::GetDefaultFont() const
{
	return &defaultFont;
}

/// @brief Is mouse on window
/// @return "true" is mouse is on window, otherwise "false"
bool NoLifeNoCry::Engine::UI::Window::IsMouseOnWindow() const
{
	return isMouseOnWindow;
}

bool NoLifeNoCry::Engine::UI::Window::IsWindowFocused() const
{
	return hasFocus();
}

/// @brief Get mouse position
/// @return Mouse position
glm::ivec2 NoLifeNoCry::Engine::UI::Window::GetMousePosition() const
{
	return lastMousePosition;
}

/// @brief Process mouse entering window event
/// @return "true" if event is being handled by this control, otherwise "false"
bool NoLifeNoCry::Engine::UI::Window::ProcessWindowMouseEntered()
{
	NoLifeNoCry::Engine::UI::Control::ProcessWindowMouseEntered();
	return true;
}

/// @brief Process mouse leaving window event
/// @return "true" if event is being handled by this control, otherwise "false"
bool NoLifeNoCry::Engine::UI::Window::ProcessWindowMouseLeft()
{
	NoLifeNoCry::Engine::UI::Control::ProcessWindowMouseLeft();
	return true;
}
