#pragma once

#include <filesystem>
#include <EExitCode.hpp>
#include <String.hpp>
#include <UI/Button.hpp>
#include <UI/InputField.hpp>
#include <UI/Window.hpp>

namespace DirtyFinger::UI
{
	class EditorWindow : public DirtMachine::UI::Window
	{
	public:

		EditorWindow() = delete;
		EditorWindow(const DirtyFinger::UI::EditorWindow&) = delete;
		EditorWindow(DirtyFinger::UI::EditorWindow&&) = delete;

		EditorWindow(std::size_t width, std::size_t height, const DirtMachine::String& title, DirtMachine::EWindowStyle style);

		/// @brief Destructor
		~EditorWindow();

		DirtyFinger::UI::EditorWindow& operator=(const DirtyFinger::UI::EditorWindow&) = delete;
		DirtyFinger::UI::EditorWindow& operator=(DirtyFinger::UI::EditorWindow&&) = delete;

	private:

		static const std::filesystem::path configurationFilePath;
	};
}
