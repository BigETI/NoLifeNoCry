#include <array>
#include <memory>
#include <Input/Data/MouseButtonData.hpp>
#include <Input/EMouseButton.hpp>
#include <UI/AboutWindow.hpp>
#include <UI/Button.hpp>
#include <UI/ETextAlignment.hpp>
#include <UI/Label.hpp>

DirtyFinger::UI::AboutWindow::AboutWindow(std::size_t width, std::size_t height, const DirtMachine::String& title, DirtMachine::EWindowStyle style) :
	DirtMachine::UI::Window(width, height, title, style)
{
	std::array<std::shared_ptr<DirtMachine::UI::Control>, 4> controls =
	{
		GetUI().CreateChild<DirtMachine::UI::Label>(glm::ivec2(0, -36), 0.0f, glm::uvec2(static_cast<unsigned int>(width), 24U), "Dirty Finger has been made by Ethem Kurt", GetDefaultFont(), 14, DirtMachine::UI::ETextAlignment::Center),
		GetUI().CreateChild<DirtMachine::UI::Label>(glm::ivec2(0, -12), 0.0f, glm::uvec2(static_cast<unsigned int>(width), 24U), "This editor is part of my programming task for", GetDefaultFont(), 14, DirtMachine::UI::ETextAlignment::Center),
		GetUI().CreateChild<DirtMachine::UI::Label>(glm::ivec2(0, 12), 0.0f, glm::uvec2(static_cast<unsigned int>(width), 24U), "BA3 Game Programming at CGL in TH-Köln.", GetDefaultFont(), 14, DirtMachine::UI::ETextAlignment::Center),
		GetUI().CreateChild<DirtMachine::UI::Label>(glm::ivec2(0, 36), 0.0f, glm::uvec2(static_cast<unsigned int>(width), 24U), "GitHub: https://github.com/BigETI/NoLifeNoCry", GetDefaultFont(), 14, DirtMachine::UI::ETextAlignment::Center)
	};
	GetUI().OnTransformationChanged += [this, controls]()
	{
		glm::uvec2 current_size(GetSize());
		glm::uvec2 control_size(static_cast<unsigned int>(glm::max(static_cast<int>(current_size.x) - 64, 0)), 24U);
		glm::ivec2 current_position(32, (static_cast<int>(current_size.y) / 2) - 36);
		for (std::shared_ptr<DirtMachine::UI::Control> control : controls)
		{
			control->SetLocalPosition(current_position);
			control->SetSize(control_size);
			current_position.y += 24;
		}
	};
}

DirtyFinger::UI::AboutWindow::~AboutWindow()
{
	// ...
}
