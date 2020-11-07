#include "Window.hpp"

/// @brief Constructor
/// @param windowWidth Window width
/// @param windowHeight Window height
/// @param windowName Window name
/// @param windowStyle Window style
NoLifeNoCry::Engine::Window::Window(std::size_t width, std::size_t height, const std::string& title, NoLifeNoCry::Engine::EWindowStyle style) : sf::Window(sf::VideoMode(static_cast<unsigned int>(width), static_cast<unsigned int>(height)), title, static_cast<sf::Uint32>(style)), title(title), style(style)
{
	// ...
}

/// @brief Destructor
NoLifeNoCry::Engine::Window::~Window()
{
	// ...
}

/// @brief Shows a window
void NoLifeNoCry::Engine::Window::Create()
{
	sf::Vector2u size(getSize());
	create(sf::VideoMode(size.x, size.y), title, static_cast<sf::Uint32>(style));
}

/// @brief Is window open
/// @return "true" if window is open (not to be confused with is window showing), otherwise "false"
bool NoLifeNoCry::Engine::Window::IsOpen() const
{
	return isOpen();
}

/// @brief Has window focus
/// @return "true" if window has focus, otherwise "false"
bool NoLifeNoCry::Engine::Window::HasFocus() const
{
	return hasFocus();
}

/// @brief Process messages
/// @return "true" if messages have been successfully processed, otherwise "false"
bool NoLifeNoCry::Engine::Window::ProcessMessages()
{
	bool ret(isOpen());
	if (ret)
	{
		sf::Event event;
		while (pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				OnWindowClosed();
				close();
				break;
			case sf::Event::Resized:
				OnWindowResized(static_cast<std::size_t>(event.size.width), static_cast<std::size_t>(event.size.height));
				break;
			case sf::Event::LostFocus:
				OnFocusLost();
				break;
			case sf::Event::GainedFocus:
				OnFocusGained();
				break;
			case sf::Event::TextEntered:
				OnTextEntered(NoLifeNoCry::Engine::TextData{ static_cast<std::uint32_t>(event.text.unicode) });
				break;
			case sf::Event::KeyPressed:
				OnKeyboardKeyPressed(NoLifeNoCry::Engine::KeyboardKeyData{ static_cast<NoLifeNoCry::Engine::EKeyboardKey>(event.key.code), event.key.alt, event.key.control, event.key.shift, event.key.system });
				break;
			case sf::Event::KeyReleased:
				OnKeyboardKeyReleased(NoLifeNoCry::Engine::KeyboardKeyData{ static_cast<NoLifeNoCry::Engine::EKeyboardKey>(event.key.code), event.key.alt, event.key.control, event.key.shift, event.key.system });
				break;
			case sf::Event::MouseWheelScrolled:
				OnMouseWheelScrolled(NoLifeNoCry::Engine::MouseWheelData{ static_cast<NoLifeNoCry::Engine::EMouseWheel>(event.mouseWheelScroll.wheel), event.mouseWheelScroll.delta, event.mouseWheelScroll.x, event.mouseWheelScroll.y });
				break;
			case sf::Event::MouseButtonPressed:
				OnMouseButtonPressed(NoLifeNoCry::Engine::MouseButtonData{ static_cast<NoLifeNoCry::Engine::EMouseButton>(event.mouseButton.button), event.mouseButton.x, event.mouseButton.y });
				break;
			case sf::Event::MouseButtonReleased:
				OnMouseButtonReleased(NoLifeNoCry::Engine::MouseButtonData{ static_cast<NoLifeNoCry::Engine::EMouseButton>(event.mouseButton.button), event.mouseButton.x, event.mouseButton.y });
				break;
			case sf::Event::MouseMoved:
				OnMouseMoved(NoLifeNoCry::Engine::MouseMovementData{ event.mouseMove.x, event.mouseMove.y });
				break;
			case sf::Event::MouseEntered:
				OnMouseEntered();
				break;
			case sf::Event::MouseLeft:
				OnMouseLeft();
				break;
			case sf::Event::JoystickButtonPressed:
				OnJoystickButtonPressed(NoLifeNoCry::Engine::JoystickButtonData{ event.joystickButton.joystickId, event.joystickButton.button });
				break;
			case sf::Event::JoystickButtonReleased:
				OnJoystickButtonReleased(NoLifeNoCry::Engine::JoystickButtonData{ event.joystickButton.joystickId, event.joystickButton.button });
				break;
			case sf::Event::JoystickMoved:
				OnJoystickMoved(NoLifeNoCry::Engine::JoystickMovementData{ event.joystickMove.joystickId, static_cast<NoLifeNoCry::Engine::EJoystickAxis>(event.joystickMove.axis), event.joystickMove.position });
				break;
			case sf::Event::JoystickConnected:
				OnJoystickConnected(NoLifeNoCry::Engine::JoystickConnectionData{ event.joystickConnect.joystickId });
				break;
			case sf::Event::JoystickDisconnected:
				OnJoystickDisconnected(NoLifeNoCry::Engine::JoystickConnectionData{ event.joystickConnect.joystickId });
				break;
			case sf::Event::TouchBegan:
				OnTouchBegan(NoLifeNoCry::Engine::TouchData{ event.touch.finger, event.touch.x, event.touch.y });
				break;
			case sf::Event::TouchMoved:
				OnTouchMoved(NoLifeNoCry::Engine::TouchData{ event.touch.finger, event.touch.x, event.touch.y });
				break;
			case sf::Event::TouchEnded:
				OnTouchEnded(NoLifeNoCry::Engine::TouchData{ event.touch.finger, event.touch.x, event.touch.y });
				break;
			case sf::Event::SensorChanged:
				OnSensorChanged(NoLifeNoCry::Engine::SensorData{ static_cast<NoLifeNoCry::Engine::ESensorType>(event.sensor.type), event.sensor.x, event.sensor.y, event.sensor.z });
				break;
			}
		}
	}
	return ret;
}
