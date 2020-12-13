#pragma once

#include <memory>
#include <glm/vec2.hpp>
#include <String.hpp>
#include <UI/Control.hpp>
#include <UI/Button.hpp>
#include <UI/Panel.hpp>

namespace DirtMachine::UI
{
	class TabListViewPage : public DirtMachine::UI::Panel
	{
	public:

		TabListViewPage(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, std::shared_ptr<DirtMachine::UI::Button> tabListViewPageButton, DirtMachine::UI::Control* parent);

		virtual ~TabListViewPage();

		virtual DirtMachine::String GetTitle() const;

		virtual void SetTitle(const DirtMachine::String& title);

	private:

		std::shared_ptr<DirtMachine::UI::Button> tabListViewPageButton;
	};
}
