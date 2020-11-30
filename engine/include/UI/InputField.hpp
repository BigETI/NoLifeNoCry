#pragma once

#include <string>
#include <vector>
#include <Graphic/Font.hpp>
#include <Graphic/RenderTarget.hpp>
#include <UI/InteractableControl.hpp>
#include <UI/Label.hpp>
#include <UI/Panel.hpp>

namespace NoLifeNoCry::Engine::UI
{
	class InputField : public NoLifeNoCry::Engine::UI::InteractableControl
	{
	public:

		InputField(const glm::ivec2& position, float rotation, const glm::uvec2& size, const NoLifeNoCry::Engine::String& textString, const NoLifeNoCry::Engine::String& hintTextString, const NoLifeNoCry::Engine::Graphic::Font* textFont, unsigned int textCharacterSize, NoLifeNoCry::Engine::UI::Control* parent);

		virtual ~InputField();

		virtual NoLifeNoCry::Engine::String GetTextLine(std::size_t textLineIndex) const;

		virtual void SetTextLine(std::size_t textLineIndex, const NoLifeNoCry::Engine::String& textLine);

		virtual std::size_t GetTextLineCount() const;

		virtual NoLifeNoCry::Engine::String GetText() const;

		virtual void SetText(const NoLifeNoCry::Engine::String& newText);

		virtual NoLifeNoCry::Engine::String GetHintText() const;

		virtual void SetHintText(const NoLifeNoCry::Engine::String& newText);

		virtual void GetSelectionInformation(std::size_t& beginRowPosition, std::size_t& beginColumnPosition, std::size_t& endRowPosition, std::size_t& endColumnPosition) const;

		virtual void ResetSelection();

		virtual void InsertTextIntoSelection(const NoLifeNoCry::Engine::String& newText);

		virtual void RemoveSelectedText();

		virtual bool CopySelectedText() const;

		virtual void SelectAllText();

		virtual void RemoveBack();

		virtual void RemoveFront();

		virtual bool ProcessTextEntered(const NoLifeNoCry::Engine::Input::Data::TextData& textData) override;

		virtual bool ProcessKeyPressed(const NoLifeNoCry::Engine::Input::Data::KeyboardKeyData& keyboardKeyData) override;

	private:

		std::shared_ptr<NoLifeNoCry::Engine::UI::Panel> backgroundPanel;

		std::vector<std::shared_ptr<NoLifeNoCry::Engine::UI::Label>> textLineLabels;

		std::vector<std::shared_ptr<NoLifeNoCry::Engine::UI::Label>> hintTextLineLabels;

		std::vector<std::shared_ptr<NoLifeNoCry::Engine::UI::Panel>> selectionPanels;

		std::shared_ptr<NoLifeNoCry::Engine::UI::Label> caretLabel;

		std::vector<NoLifeNoCry::Engine::String> textLines;

		const NoLifeNoCry::Engine::Graphic::Font* textFont;

		unsigned int textCharacterSize;

		std::size_t caretRowPosition;

		std::size_t caretColumnPosition;

		std::size_t selectionRowPosition;

		std::size_t selectionColumnPosition;

		void UpdateTextLineLabel(std::size_t textLineIndex);

		void UpdateTextLineLabels();

		void UpdateSelection();
	};
}
