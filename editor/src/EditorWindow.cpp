#define _USE_MATH_DEFINES
#include <iostream>
#include <EditorWindow.hpp>
#include <glm/trigonometric.hpp>
#include <cmath>

/// @brief Constructor
/// @param windowWidth Window width
/// @param windowHeight Window height
/// @param windowName Window name
/// @param windowStyle Window style
DirtyFinger::EditorWindow::EditorWindow(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, DirtMachine::EWindowStyle windowStyle) :
	DirtMachine::UI::Window(windowWidth, windowHeight, windowName, windowStyle),
	time(0.0),
	testButton(nullptr),
	testInputField(nullptr)
{
	OnWindowStarted += [this]()
	{
		std::cout << "Window has started." << std::endl;
		testButton = GetUI().CreateChild<DirtMachine::UI::Button>(glm::ivec2(0, 0), 0.0f, glm::uvec2(200U, 100U), "Hi", GetDefaultFont(), 24U);
		testInputField = GetUI().CreateChild<DirtMachine::UI::InputField>(glm::ivec2(100, 100), 0.0f, glm::uvec2(200, 120), "Delete me!", "Hint...", GetDefaultFont(), 16U, false);
		//testButton->GetLabel().SetTextString("Hi!");
		testButton->OnMouseEntered += []()
		{
			std::cout << "Mouse has entered button." << std::endl;
		};
		testButton->OnMouseHovered += []()
		{
			//std::cout << "Mouse has hovered over button." << std::endl;
		};
		testButton->OnMouseLeft += []()
		{
			std::cout << "Mouse has left button." << std::endl;
		};
		testButton->OnMouseButtonPressed += [](DirtMachine::Input::Data::MouseButtonData mouseButton)
		{
			std::cout << "Mouse button pressed: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.position.x << ", " << mouseButton.position.y << ")" << std::endl;
		};
		testButton->OnMouseButtonReleased += [](DirtMachine::Input::Data::MouseButtonData mouseButton)
		{
			std::cout << "Mouse button released: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.position.x << ", " << mouseButton.position.y << ")" << std::endl;
		};
	};
	OnWindowStopped += []()
	{
		std::cout << "Window has stopped." << std::endl;
	};
	OnWindowMessagesProcessed += [this](double deltaTime)
	{
		time += deltaTime;
		glm::vec2 normalized_position((glm::sin(time * M_PI) + 1.0) * 0.5, (glm::cos(time * M_PI) + 1.0) * 0.5);
		if (testButton)
		{
			testButton->SetLocalPosition({ static_cast<int>(normalized_position.x * (GetSize().x - testButton->GetSize().x)), static_cast<int>(normalized_position.y * (GetSize().y - testButton->GetSize().y)) });
		}
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
	OnTextEntered += [](DirtMachine::Input::Data::TextData text)
	{
		std::cout << "Text entered: " << text.unicode << std::endl;
	};
	OnKeyboardKeyPressed += [this](DirtMachine::Input::Data::KeyboardKeyData keyboardKey)
	{
		std::cout << "Key pressed: " << (keyboardKey.isSystemKeyUsed ? "Sys+" : "") << (keyboardKey.isControlKeyUsed ? "Ctrl+" : "") << (keyboardKey.isAltKeyUsed ? "Alt+" : "") << static_cast<int>(keyboardKey.keyCode) << std::endl;
	};
	OnKeyboardKeyReleased += [](DirtMachine::Input::Data::KeyboardKeyData keyboardKey)
	{
		std::cout << "Key released: " << (keyboardKey.isSystemKeyUsed ? "Sys+" : "") << (keyboardKey.isControlKeyUsed ? "Ctrl+" : "") << (keyboardKey.isAltKeyUsed ? "Alt+" : "") << static_cast<int>(keyboardKey.keyCode) << std::endl;
	};
	OnMouseWheelScrolled += [](DirtMachine::Input::Data::MouseWheelData mouseWheel)
	{
		std::cout << "Mouse wheel scrolled: " << static_cast<int>(mouseWheel.wheel) << " : " << mouseWheel.delta << " at (" << mouseWheel.position.x << ", " << mouseWheel.position.y << ")" << std::endl;
	};
	OnMouseButtonPressed += [](DirtMachine::Input::Data::MouseButtonData mouseButton)
	{
		//std::cout << "Mouse button pressed: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.position.x << ", " << mouseButton.position.y << ")" << std::endl;
	};
	OnMouseButtonReleased += [](DirtMachine::Input::Data::MouseButtonData mouseButton)
	{
		//std::cout << "Mouse button released: " << static_cast<int>(mouseButton.button) << " at (" << mouseButton.position.x << ", " << mouseButton.position.y << ")" << std::endl;
	};
	OnMouseMoved += [](DirtMachine::Input::Data::MouseMovementData mouseMovement)
	{
		//std::cout << "Mouse moved: (" << mouseMovement.position.x << ", " << mouseMovement.position.y << ")" << std::endl;
	};
	OnMouseEntered += []()
	{
		std::cout << "Mouse has entered the window." << std::endl;
	};
	OnMouseLeft += []()
	{
		std::cout << "Mouse has left the window." << std::endl;
	};
	OnJoystickButtonPressed += [](DirtMachine::Input::Data::JoystickButtonData joystickButton)
	{
		std::cout << "Joystick button pressed: " << joystickButton.button << " at joystick ID " << joystickButton.joystickID << std::endl;
	};
	OnJoystickButtonReleased += [](DirtMachine::Input::Data::JoystickButtonData joystickButton)
	{
		std::cout << "Joystick button released: " << joystickButton.button << " at joystick ID " << joystickButton.joystickID << std::endl;
	};
	OnJoystickMoved += [](DirtMachine::Input::Data::JoystickMovementData joystickMovement)
	{
		std::cout << "Joystick moved: " << joystickMovement.position << " with axis " << static_cast<int>(joystickMovement.axis) << " at joystick ID " << joystickMovement.joystickID << std::endl;
	};
	OnJoystickConnected += [](DirtMachine::Input::Data::JoystickConnectionData joystickConnection)
	{
		std::cout << "Joystick ID " << joystickConnection.joystickID << " has been connected." << std::endl;
	};
	OnJoystickDisconnected += [](DirtMachine::Input::Data::JoystickConnectionData joystickConnection)
	{
		std::cout << "Joystick ID " << joystickConnection.joystickID << " has been disconnected." << std::endl;
	};
	OnTouchBegan += [](DirtMachine::Input::Data::TouchData touch)
	{
		std::cout << "Touch began: Finger " << touch.finger << " at (" << touch.position.x << ", " << touch.position.y << ")" << std::endl;
	};
	OnTouchMoved += [](DirtMachine::Input::Data::TouchData touch)
	{
		std::cout << "Touch moved: Finger " << touch.finger << " at (" << touch.position.x << ", " << touch.position.y << ")" << std::endl;
	};
	OnTouchEnded += [](DirtMachine::Input::Data::TouchData touch)
	{
		std::cout << "Touch ended: Finger " << touch.finger << " at (" << touch.position.x << ", " << touch.position.y << ")" << std::endl;
	};
	OnSensorChanged += [](DirtMachine::Input::Data::SensorData sensor)
	{
		std::cout << "Sensor changed: Type " << static_cast<int>(sensor.type) << " at (" << sensor.value.x << ", " << sensor.value.y << ", " << sensor.value.z << ")" << std::endl;
	};
}

/// @brief Destructor
DirtyFinger::EditorWindow::~EditorWindow()
{
	// ...
}

const std::filesystem::path DirtyFinger::EditorWindow::configurationFilePath("./editorconfig.xml");
