#include <iostream>

#include "GameWindow.hpp"

/// @brief Constructor
/// @param windowWidth Window width
/// @param windowHeight Window height
/// @param windowName Window name
/// @param windowStyle Window style
NoLifeNoCry::Game::GameWindow::GameWindow(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, NoLifeNoCry::Engine::EWindowStyle windowStyle) : Window(windowWidth, windowHeight, windowName, windowStyle)
{
	OnWindowResized += [](std::size_t width, std::size_t height)
	{
		std::cout << "New window size: (" << width << ", " << height << ")" << std::endl;
	};
	OnFocusLost += []()
	{
		std::cout << "Window lost focus." << std::endl;
	};
	OnFocusGained += []()
	{
		std::cout << "Window gained focus." << std::endl;
	};
	OnTextEntered += [](NoLifeNoCry::Engine::TextData text)
	{
		std::cout << "Text entered: " << text.unicode << std::endl;
	};
	OnKeyboardKeyPressed += [](NoLifeNoCry::Engine::KeyboardKeyData keyboardKey)
	{
		std::cout << "Key pressed: " << (keyboardKey.isSystemKeyUsed ? "Sys+" : "") << (keyboardKey.isControlKeyUsed ? "Ctrl+" : "") << (keyboardKey.isAltKeyUsed ? "Alt+" : "") << static_cast<int>(keyboardKey.keyCode) << std::endl;
	};
	OnKeyboardKeyReleased += [](NoLifeNoCry::Engine::KeyboardKeyData keyboardKey)
	{
		std::cout << "Key released: " << (keyboardKey.isSystemKeyUsed ? "Sys+" : "") << (keyboardKey.isControlKeyUsed ? "Ctrl+" : "") << (keyboardKey.isAltKeyUsed ? "Alt+" : "") << static_cast<int>(keyboardKey.keyCode) << std::endl;
	};
	OnMouseWheelScrolled += [](NoLifeNoCry::Engine::MouseWheelData mouseWheel)
	{
		std::cout << "Mouse wheel scrolled: " << static_cast<int>(mouseWheel.wheel) << " : " << mouseWheel.delta << " at (" << mouseWheel.x << ", " << mouseWheel.y << ")" << std::endl;
	};
	OnMouseButtonPressed += [](NoLifeNoCry::Engine::MouseButtonData mouseButton)
	{
		std::cout << "Mouse button pressed: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.x << ", " << mouseButton.y << ")" << std::endl;
	};
	OnMouseButtonReleased += [](NoLifeNoCry::Engine::MouseButtonData mouseButton)
	{
		std::cout << "Mouse button released: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.x << ", " << mouseButton.y << ")" << std::endl;
	};
	OnMouseMoved += [](NoLifeNoCry::Engine::MouseMovementData mouseMovement)
	{
		std::cout << "Mouse moved: (" << mouseMovement.x << ", " << mouseMovement.y << ")" << std::endl;
	};
	OnMouseEntered += []()
	{
		std::cout << "Mouse has entered the window." << std::endl;
	};
	OnMouseLeft += []()
	{
		std::cout << "Mouse has left the window." << std::endl;
	};
	OnJoystickButtonPressed += [](NoLifeNoCry::Engine::JoystickButtonData joystickButton)
	{
		std::cout << "Joystick button pressed: " << joystickButton.button << " at joystick ID " << joystickButton.joystickID << std::endl;
	};
	OnJoystickButtonReleased += [](NoLifeNoCry::Engine::JoystickButtonData joystickButton)
	{
		std::cout << "Joystick button released: " << joystickButton.button << " at joystick ID " << joystickButton.joystickID << std::endl;
	};
	OnJoystickMoved += [](NoLifeNoCry::Engine::JoystickMovementData joystickMovement)
	{
		std::cout << "Joystick moved: " << joystickMovement.position << " with axis " << static_cast<int>(joystickMovement.axis) << " at joystick ID " << joystickMovement.joystickID << std::endl;
	};
	OnJoystickConnected += [](NoLifeNoCry::Engine::JoystickConnectionData joystickConnection)
	{
		std::cout << "Joystick ID " << joystickConnection.joystickID << " has been connected." << std::endl;
	};
	OnJoystickDisconnected += [](NoLifeNoCry::Engine::JoystickConnectionData joystickConnection)
	{
		std::cout << "Joystick ID " << joystickConnection.joystickID << " has been disconnected." << std::endl;
	};
	OnTouchBegan += [](NoLifeNoCry::Engine::TouchData touch)
	{
		std::cout << "Touch began: Finger " << touch.finger << " at (" << touch.x << ", " << touch.y << ")" << std::endl;
	};
	OnTouchMoved += [](NoLifeNoCry::Engine::TouchData touch)
	{
		std::cout << "Touch moved: Finger " << touch.finger << " at (" << touch.x << ", " << touch.y << ")" << std::endl;
	};
	OnTouchEnded += [](NoLifeNoCry::Engine::TouchData touch)
	{
		std::cout << "Touch ended: Finger " << touch.finger << " at (" << touch.x << ", " << touch.y << ")" << std::endl;
	};
	OnSensorChanged += [](NoLifeNoCry::Engine::SensorData sensor)
	{
		std::cout << "Sensor changed: Type " << static_cast<int>(sensor.type) << " at (" << sensor.x << ", " << sensor.y << ", " << sensor.z << ")" << std::endl;
	};
}

/// @brief Destructor
NoLifeNoCry::Game::GameWindow::~GameWindow()
{
	// ...
}

/// @brief Start game
/// @return Game exit code
NoLifeNoCry::Engine::EExitCode NoLifeNoCry::Game::GameWindow::Start()
{
	NoLifeNoCry::Engine::EExitCode ret(NoLifeNoCry::Engine::EExitCode::FailedCreatingWindow);
	if (IsOpen())
	{
		ret = NoLifeNoCry::Engine::EExitCode::Success;
		while (ProcessMessages());
	}
	return ret;
}
