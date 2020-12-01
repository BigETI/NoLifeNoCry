#pragma once

#include <EExitCode.hpp>
#include <UI/Button.hpp>
#include <UI/InputField.hpp>
#include <UI/Window.hpp>

namespace DirtyFinger
{
	class EditorWindow : public DirtMachine::UI::Window
	{
	public:
		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		EditorWindow(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, DirtMachine::EWindowStyle windowStyle);

		/// @brief Destructor
		~EditorWindow();

		EditorWindow(const EditorWindow&) = delete;
		EditorWindow(EditorWindow&&) = delete;

		EditorWindow& operator=(const EditorWindow&) = delete;
		EditorWindow& operator=(EditorWindow&&) = delete;

	private:

		std::shared_ptr<DirtMachine::UI::Button> testButton;

		std::shared_ptr<DirtMachine::UI::InputField> testInputField;

		double time;
	};
}
