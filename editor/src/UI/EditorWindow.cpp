#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <glm/trigonometric.hpp>
#include <UI/AboutWindow.hpp>
#include <UI/EditorWindow.hpp>
#include <UI/MenuBar.hpp>
#include <UI/ProjectFilesTabListView.hpp>

DirtyFinger::UI::EditorWindow::EditorWindow(std::size_t width, std::size_t height, const DirtMachine::String& title, DirtMachine::EWindowStyle style) :
	DirtMachine::UI::Window(width, height, title, style)
{
	OnWindowStarted += [this]()
	{
		std::cout << "Window has started." << std::endl;
		std::shared_ptr<DirtyFinger::UI::ProjectFilesTabListView> project_files_tab_list_view(GetUI().CreateChild<DirtyFinger::UI::ProjectFilesTabListView>(glm::ivec2(0, 24), 0.0f, glm::uvec2(0U, 0U), GetDefaultFont(), 12U, 6.0f));
		std::shared_ptr<DirtMachine::UI::MenuBar> main_menu_bar(GetUI().CreateChild<DirtMachine::UI::MenuBar>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 24U), GetDefaultFont(), 12U, 6.0f));
		
		//project_files_tab_list_view->SetVisibleState(false);

		std::shared_ptr<DirtMachine::UI::MenuButton> file_menu_button(main_menu_bar->CreateMenuButton("File"));
		file_menu_button->GetContextMenu().CreateMenuItem("New");
		file_menu_button->GetContextMenu().CreateMenuItem("Load");
		std::shared_ptr<DirtMachine::UI::Button> exit_menu_item(file_menu_button->GetContextMenu().CreateMenuItem("Exit ( Alt+F4 )"));
		exit_menu_item->OnMouseButtonReleased += [this](const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
		{
			if (mouseButtonData.button == DirtMachine::Input::EMouseButton::Left)
			{
				Close();
			}
		};
		std::shared_ptr<DirtMachine::UI::MenuButton> edit_menu_button(main_menu_bar->CreateMenuButton("Edit"));
		edit_menu_button->GetContextMenu().CreateMenuItem("Test 1");
		edit_menu_button->GetContextMenu().CreateMenuItem("Test 2");
		edit_menu_button->GetContextMenu().CreateMenuItem("Test 3");
		std::shared_ptr<DirtMachine::UI::MenuButton> settings_menu_button(main_menu_bar->CreateMenuButton("Settings"));
		settings_menu_button->GetContextMenu().CreateMenuItem("Settings 1");
		settings_menu_button->GetContextMenu().CreateMenuItem("Settings 2");
		settings_menu_button->GetContextMenu().CreateMenuItem("Settings 3");
		std::shared_ptr<DirtMachine::UI::MenuButton> help_menu_button(main_menu_bar->CreateMenuButton("Help"));
		std::shared_ptr<DirtMachine::UI::Button> about_menu_item(help_menu_button->GetContextMenu().CreateMenuItem("About"));
		about_menu_item->OnMouseButtonReleased += [this](const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
		{
			if (mouseButtonData.button == DirtMachine::Input::EMouseButton::Left)
			{
				CreateWindow<DirtyFinger::UI::AboutWindow>(static_cast<std::size_t>(400), static_cast<std::size_t>(300), "About - Dirty Finger - Dirt Machine Editor", DirtMachine::EWindowStyle::Default);
			}
		};

		GetUI().OnTransformationChanged += [this, project_files_tab_list_view, main_menu_bar]()
		{
			glm::uvec2 current_size(GetSize());
			project_files_tab_list_view->SetSize(glm::uvec2(glm::min(current_size.x, 200U), current_size.y));
			main_menu_bar->SetSize(glm::uvec2(current_size.x, 24U));
		};
	};
	OnWindowStopped += []()
	{
		std::cout << "Window has stopped." << std::endl;
	};
	OnWindowMessagesProcessed += [this](double deltaTime)
	{
		// TODO
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
DirtyFinger::UI::EditorWindow::~EditorWindow()
{
	// ...
}

const std::filesystem::path DirtyFinger::UI::EditorWindow::configurationFilePath("./editorconfig.xml");
