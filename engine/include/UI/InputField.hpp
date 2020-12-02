#pragma once

#include <string>
#include <vector>
#include <Graphic/Font.hpp>
#include <Graphic/RenderTarget.hpp>
#include <UI/InteractableControl.hpp>
#include <UI/Label.hpp>
#include <UI/Panel.hpp>

namespace DirtMachine::UI
{
	class InputField : public DirtMachine::UI::InteractableControl
	{
	public:

		InputField(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::String& textString, const DirtMachine::String& hintTextString, const DirtMachine::Graphic::Font* textFont, unsigned int textCharacterSize, bool isMultiLine, DirtMachine::UI::Control* parent);

		virtual ~InputField();

		virtual DirtMachine::String GetTextLine(std::size_t textLineIndex) const;

		virtual void SetTextLine(std::size_t textLineIndex, const DirtMachine::String& textLine);

		virtual std::size_t GetTextLineCount() const;

		virtual DirtMachine::String GetText() const;

		virtual void SetText(const DirtMachine::String& newText);

		virtual DirtMachine::String GetHintText() const;

		virtual void SetHintText(const DirtMachine::String& newText);

		virtual const DirtMachine::Graphic::Font* GetTextFont() const;

		virtual void SetTextFont(const DirtMachine::Graphic::Font* newTextFont);

		virtual unsigned int GetTextCharacterSize() const;

		virtual void SetTextCharacterSize(unsigned int newTextCharacterSize);

		virtual bool IsMultiLine() const;

		virtual void SetMultiLineState(bool multiLineState);

		virtual void GetSelectionInformation(std::size_t& beginRowPosition, std::size_t& beginColumnPosition, std::size_t& endRowPosition, std::size_t& endColumnPosition) const;

		virtual void ResetSelection();

		virtual void InsertTextIntoSelection(const DirtMachine::String& newText);

		virtual void RemoveSelectedText();

		virtual bool CopySelectedText() const;

		virtual void SelectAllText();

		virtual void RemoveBack();

		virtual void RemoveFront();

		virtual bool ProcessTextEntered(const DirtMachine::Input::Data::TextData& textData) override;

		virtual bool ProcessKeyPressed(const DirtMachine::Input::Data::KeyboardKeyData& keyboardKeyData) override;

	private:

		std::vector<DirtMachine::String> textLines;

		const DirtMachine::Graphic::Font* textFont;

		unsigned int textCharacterSize;

		bool isMultiLine;

		std::shared_ptr<DirtMachine::UI::Panel> backgroundPanel;

		std::vector<std::shared_ptr<DirtMachine::UI::Label>> textLineLabels;

		std::vector<std::shared_ptr<DirtMachine::UI::Label>> hintTextLineLabels;

		std::vector<std::shared_ptr<DirtMachine::UI::Panel>> selectionPanels;

		std::shared_ptr<DirtMachine::UI::Label> caretLabel;

		std::size_t caretRowPosition;

		std::size_t caretColumnPosition;

		std::size_t selectionRowPosition;

		std::size_t selectionColumnPosition;

		void UpdateTextLineLabel(std::size_t textLineIndex);

		void UpdateTextLineLabels();

		void UpdateSelection();
	};
}
