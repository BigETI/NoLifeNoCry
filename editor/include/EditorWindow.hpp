#pragma once

#include "EExitCode.hpp"
#include "Window.hpp"

namespace NoLifeNoCry::Editor
{
	class EditorWindow : public NoLifeNoCry::Engine::Window
	{
	public:
		/// @brief Constructor
		/// @param windowWidth Window width
		/// @param windowHeight Window height
		/// @param windowName Window name
		/// @param windowStyle Window style
		EditorWindow(std::size_t windowWidth, std::size_t windowHeight, const std::string& windowName, NoLifeNoCry::Engine::EWindowStyle windowStyle);

		/// @brief Destructor
		~EditorWindow();

		EditorWindow(const EditorWindow&) = delete;
		EditorWindow(EditorWindow&&) = delete;

		/// @brief Start editor
		/// @return Exit code
		NoLifeNoCry::Engine::EExitCode Start();

		EditorWindow& operator=(const EditorWindow&) = delete;
		EditorWindow& operator=(EditorWindow&&) = delete;
	};
}
