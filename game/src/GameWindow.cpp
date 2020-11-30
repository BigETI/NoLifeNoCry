#include <iostream>
#include <rttr/registration.h>
#include <GameWindow.hpp>
#include <Serialiser/Asset.hpp>
#include <Story.hpp>
#include <StoryData.hpp>

/// @brief Constructor
/// @param windowWidth Window width
/// @param windowHeight Window height
/// @param windowName Window name
/// @param windowStyle Window style
NoLifeNoCry::Game::GameWindow::GameWindow(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, NoLifeNoCry::Engine::EWindowStyle windowStyle) : NoLifeNoCry::Engine::UI::Window(windowWidth, windowHeight, windowName, windowStyle)
{
	OnWindowStarted += []()
	{
		std::cout << "Window has started." << std::endl;
	};
	OnWindowStopped += []()
	{
		std::cout << "Window has stopped." << std::endl;
	};
	OnWindowMessagesProcessed += [](double deltaTime)
	{
		std::cout << "Window has processed messaged. Delta time: " << deltaTime << std::endl;
	};
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
	OnTextEntered += [](NoLifeNoCry::Engine::Input::Data::TextData text)
	{
		std::cout << "Text entered: " << text.unicode << std::endl;
	};
	OnKeyboardKeyPressed += [](NoLifeNoCry::Engine::Input::Data::KeyboardKeyData keyboardKey)
	{
		std::cout << "Key pressed: " << (keyboardKey.isSystemKeyUsed ? "Sys+" : "") << (keyboardKey.isControlKeyUsed ? "Ctrl+" : "") << (keyboardKey.isAltKeyUsed ? "Alt+" : "") << static_cast<int>(keyboardKey.keyCode) << std::endl;
	};
	OnKeyboardKeyReleased += [](NoLifeNoCry::Engine::Input::Data::KeyboardKeyData keyboardKey)
	{
		std::cout << "Key released: " << (keyboardKey.isSystemKeyUsed ? "Sys+" : "") << (keyboardKey.isControlKeyUsed ? "Ctrl+" : "") << (keyboardKey.isAltKeyUsed ? "Alt+" : "") << static_cast<int>(keyboardKey.keyCode) << std::endl;
	};
	OnMouseWheelScrolled += [](NoLifeNoCry::Engine::Input::Data::MouseWheelData mouseWheel)
	{
		std::cout << "Mouse wheel scrolled: " << static_cast<int>(mouseWheel.wheel) << " : " << mouseWheel.delta << " at (" << mouseWheel.position.x << ", " << mouseWheel.position.y << ")" << std::endl;
	};
	OnMouseButtonPressed += [](NoLifeNoCry::Engine::Input::Data::MouseButtonData mouseButton)
	{
		std::cout << "Mouse button pressed: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.position.x << ", " << mouseButton.position.y << ")" << std::endl;
	};
	OnMouseButtonReleased += [](NoLifeNoCry::Engine::Input::Data::MouseButtonData mouseButton)
	{
		std::cout << "Mouse button released: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.position.x << ", " << mouseButton.position.y << ")" << std::endl;
	};
	OnMouseMoved += [](NoLifeNoCry::Engine::Input::Data::MouseMovementData mouseMovement)
	{
		std::cout << "Mouse moved: (" << mouseMovement.position.x << ", " << mouseMovement.position.y << ")" << std::endl;
	};
	OnMouseEntered += []()
	{
		std::cout << "Mouse has entered the window." << std::endl;
	};
	OnMouseLeft += []()
	{
		std::cout << "Mouse has left the window." << std::endl;
	};
	OnJoystickButtonPressed += [](NoLifeNoCry::Engine::Input::Data::JoystickButtonData joystickButton)
	{
		std::cout << "Joystick button pressed: " << joystickButton.button << " at joystick ID " << joystickButton.joystickID << std::endl;
	};
	OnJoystickButtonReleased += [](NoLifeNoCry::Engine::Input::Data::JoystickButtonData joystickButton)
	{
		std::cout << "Joystick button released: " << joystickButton.button << " at joystick ID " << joystickButton.joystickID << std::endl;
	};
	OnJoystickMoved += [](NoLifeNoCry::Engine::Input::Data::JoystickMovementData joystickMovement)
	{
		std::cout << "Joystick moved: " << joystickMovement.position << " with axis " << static_cast<int>(joystickMovement.axis) << " at joystick ID " << joystickMovement.joystickID << std::endl;
	};
	OnJoystickConnected += [](NoLifeNoCry::Engine::Input::Data::JoystickConnectionData joystickConnection)
	{
		std::cout << "Joystick ID " << joystickConnection.joystickID << " has been connected." << std::endl;
	};
	OnJoystickDisconnected += [](NoLifeNoCry::Engine::Input::Data::JoystickConnectionData joystickConnection)
	{
		std::cout << "Joystick ID " << joystickConnection.joystickID << " has been disconnected." << std::endl;
	};
	OnTouchBegan += [](NoLifeNoCry::Engine::Input::Data::TouchData touch)
	{
		std::cout << "Touch began: Finger " << touch.finger << " at (" << touch.position.x << ", " << touch.position.y << ")" << std::endl;
	};
	OnTouchMoved += [](NoLifeNoCry::Engine::Input::Data::TouchData touch)
	{
		std::cout << "Touch moved: Finger " << touch.finger << " at (" << touch.position.x << ", " << touch.position.y << ")" << std::endl;
	};
	OnTouchEnded += [](NoLifeNoCry::Engine::Input::Data::TouchData touch)
	{
		std::cout << "Touch ended: Finger " << touch.finger << " at (" << touch.position.x << ", " << touch.position.y << ")" << std::endl;
	};
	OnSensorChanged += [](NoLifeNoCry::Engine::Input::Data::SensorData sensor)
	{
		std::cout << "Sensor changed: Type " << static_cast<int>(sensor.type) << " at (" << sensor.value.x << ", " << sensor.value.y << ", " << sensor.value.z << ")" << std::endl;
	};

	SaveGame::LoadAll("./saves/", saveGames);
}

/// @brief Destructor
NoLifeNoCry::Game::GameWindow::~GameWindow()
{
	// ...
}
