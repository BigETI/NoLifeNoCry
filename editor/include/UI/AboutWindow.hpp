#pragma once

#include <cstdint>
#include <String.hpp>
#include <UI/Window.hpp>

namespace DirtyFinger::UI
{
	class AboutWindow : public DirtMachine::UI::Window
	{
	public:

		AboutWindow() = delete;
		AboutWindow(const DirtyFinger::UI::AboutWindow&) = delete;
		AboutWindow(DirtyFinger::UI::AboutWindow&&) = delete;

		AboutWindow(std::size_t width, std::size_t height, const DirtMachine::String& title, DirtMachine::EWindowStyle style);

		virtual ~AboutWindow();

		DirtyFinger::UI::AboutWindow& operator=(const DirtyFinger::UI::AboutWindow&) = delete;
		DirtyFinger::UI::AboutWindow& operator=(DirtyFinger::UI::AboutWindow&&) = delete;
	};
}
