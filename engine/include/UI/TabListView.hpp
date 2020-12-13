#pragma once

#include <list>
#include <memory>
#include <tuple>
#include <glm/vec2.hpp>
#include <String.hpp>
#include <UI/Control.hpp>
#include <UI/Panel.hpp>
#include <UI/TabListViewPage.hpp>

namespace DirtMachine::UI
{
	class TabListView : public DirtMachine::UI::Panel
	{
	public:

		TabListView(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::Graphic::Font* tabButtonLabelTextFont, unsigned int tabButtonLabelTextCharacterSize, float tabButtonLabelTextPadding, DirtMachine::UI::Control* parent);

		virtual ~TabListView();

		virtual const DirtMachine::Graphic::Font* GetTabButtonLabelTextFont() const;

		virtual void SetTabButtonLabelTextFont(const DirtMachine::Graphic::Font* newTabButtonLabelTextFont);

		virtual unsigned int GetTabButtonLabelTextCharacterSize() const;

		virtual void SetTabButtonLabelTextCharacterSize(unsigned int tabButtonLabelTextCharacterSize);

		virtual float GetTabButtonLabelTextPadding() const;

		virtual void SetTabButtonLabelTextPadding(float newTabButtonLabelTextPadding);

		virtual DirtMachine::UI::Panel& GetButtonsPanel();

		virtual const DirtMachine::UI::Panel& GetButtonsPanel() const;

		virtual std::shared_ptr<DirtMachine::UI::TabListViewPage> CreatePage(const DirtMachine::String& tabListViewPageTitle);

		virtual bool RemovePage(const std::shared_ptr<DirtMachine::UI::TabListViewPage> tabListViewPage);

		virtual bool ShowPage(const std::shared_ptr<DirtMachine::UI::TabListViewPage> tabListViewPage);

	private:
		
		const DirtMachine::Graphic::Font* tabButtonLabelTextFont;
		
		unsigned int tabButtonLabelTextCharacterSize;

		float tabButtonLabelTextPadding;

		std::shared_ptr<DirtMachine::UI::Panel> buttonsPanel;

		std::shared_ptr<DirtMachine::UI::Panel> viewPanel;

		std::list<std::tuple<std::shared_ptr<DirtMachine::UI::TabListViewPage>, std::shared_ptr<DirtMachine::UI::Button>>> pages;

		void UpdateLayout();
	};
}
