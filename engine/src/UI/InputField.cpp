#include <cmath>
#include <iostream>
#include <Input/EKeyboardKey.hpp>
#include <Input/Clipboard.hpp>
#include <UI/InputField.hpp>

DirtMachine::UI::InputField::InputField(const glm::ivec2& position, float rotation, const glm::uvec2& size, const DirtMachine::String& textString, const DirtMachine::String& hintTextString, const DirtMachine::Graphic::Font* textFont, unsigned int textCharacterSize, bool isMultiLine, DirtMachine::UI::Control* parent) :
	DirtMachine::UI::InteractableControl(position, rotation, size, true, true, true, false, parent),
	backgroundPanel(nullptr),
	caretLabel(nullptr),
	textFont(textFont),
	textCharacterSize(textCharacterSize),
	isMultiLine(isMultiLine),
	caretRowPosition(static_cast<std::size_t>(0)),
	caretColumnPosition(static_cast<std::size_t>(0)),
	selectionRowPosition(static_cast<std::size_t>(0)),
	selectionColumnPosition(static_cast<std::size_t>(0))
{
	backgroundPanel = CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, size);
	caretLabel = CreateChild<DirtMachine::UI::Label>("|", textFont, textCharacterSize, DirtMachine::UI::ETextAlignment::TopLeft, glm::ivec2(0, 0), 0.0f, size);
	textLines.push_back(std::string());
	SetText(textString);
	OnTransformationChanged += [this]()
	{
		glm::uvec2 size(GetSize());
		backgroundPanel->SetSize(size);
		for (const std::shared_ptr<DirtMachine::UI::Label>& text_line_label : textLineLabels)
		{
			text_line_label->SetSize(size);
		}
	};
}

DirtMachine::UI::InputField::~InputField()
{
	// ...
}

DirtMachine::String DirtMachine::UI::InputField::GetTextLine(std::size_t textLineIndex) const
{
	return (textLineIndex < textLines.size()) ? textLines[textLineIndex] : DirtMachine::String();
}

void DirtMachine::UI::InputField::SetTextLine(std::size_t textLineIndex, const DirtMachine::String& textLine)
{
	if (textLineIndex < textLines.size())
	{
		UpdateTextLineLabel(textLineIndex);
	}
	else
	{
		while (textLineIndex >= textLines.size())
		{
			textLines.push_back((textLineIndex == textLines.size()) ? textLine : DirtMachine::String());
			UpdateTextLineLabel(textLineIndex);
		}
	}
	ResetSelection();
}

std::size_t DirtMachine::UI::InputField::GetTextLineCount() const
{
	return textLines.size();
}

DirtMachine::String DirtMachine::UI::InputField::GetText() const
{
	DirtMachine::String ret;
	bool is_first(true);
	for (const DirtMachine::String& text_line : textLines)
	{
		if (is_first)
		{
			is_first = false;
		}
		else
		{
			ret += "\n";
		}
		ret += text_line;
	}
	return ret;
}

void DirtMachine::UI::InputField::SetText(const DirtMachine::String& newText)
{
	DirtMachine::String text_line;
	textLines.clear();
	textLines.push_back(DirtMachine::String());
	for (const sf::Uint32& new_text_character : newText)
	{
		if (new_text_character == '\n')
		{
			textLines.push_back(DirtMachine::String());
		}
		else
		{
			textLines.back() += new_text_character;
		}
	}
	UpdateTextLineLabels();
	ResetSelection();
}

DirtMachine::String DirtMachine::UI::InputField::GetHintText() const
{
	// TODO
	return DirtMachine::String();
}

void DirtMachine::UI::InputField::SetHintText(const DirtMachine::String& newText)
{
	// TODO
}

const DirtMachine::Graphic::Font* DirtMachine::UI::InputField::GetTextFont() const
{
	return textFont;
}

void DirtMachine::UI::InputField::SetTextFont(const DirtMachine::Graphic::Font* newTextFont)
{
	if (textFont != newTextFont)
	{
		textFont = newTextFont;
		for (const std::shared_ptr<DirtMachine::UI::Label>& text_line_label : textLineLabels)
		{
			text_line_label->SetTextFont(textFont);
		}
		UpdateTextLineLabels();
		UpdateSelection();
	}
}

unsigned int DirtMachine::UI::InputField::GetTextCharacterSize() const
{
	return textCharacterSize;
}

void DirtMachine::UI::InputField::SetTextCharacterSize(unsigned int newTextCharacterSize)
{
	if (textCharacterSize != newTextCharacterSize)
	{
		textCharacterSize = newTextCharacterSize;
		UpdateTextLineLabels();
		UpdateSelection();
	}
}

bool DirtMachine::UI::InputField::IsMultiLine() const
{
	return isMultiLine;
}

void DirtMachine::UI::InputField::SetMultiLineState(bool multiLineState)
{
	if (isMultiLine != multiLineState)
	{
		isMultiLine = multiLineState;
		if ((!isMultiLine) && (textLines.size() > static_cast<std::size_t>(0)))
		{
			while (textLines.size() > static_cast<std::size_t>(0))
			{
				textLines.pop_back();
			}
			caretRowPosition = static_cast<std::size_t>(0);
			caretColumnPosition = static_cast<std::size_t>(0);
			UpdateTextLineLabels();
			UpdateSelection();
		}
	}
}

void DirtMachine::UI::InputField::ResetSelection()
{
	selectionRowPosition = caretRowPosition;
	selectionColumnPosition = caretColumnPosition;
	UpdateSelection();
}

void DirtMachine::UI::InputField::GetSelectionInformation(std::size_t& beginRowPosition, std::size_t& beginColumnPosition, std::size_t& endRowPosition, std::size_t& endColumnPosition) const
{
	if (caretRowPosition < selectionRowPosition)
	{
		beginRowPosition = caretRowPosition;
		beginColumnPosition = caretColumnPosition;
		endRowPosition = selectionRowPosition;
		endColumnPosition = selectionColumnPosition;
	}
	else if (caretRowPosition > selectionRowPosition)
	{
		beginRowPosition = selectionRowPosition;
		beginColumnPosition = selectionColumnPosition;
		endRowPosition = caretRowPosition;
		endColumnPosition = caretColumnPosition;
	}
	else
	{
		beginRowPosition = caretRowPosition;
		beginColumnPosition = std::min(caretColumnPosition, selectionColumnPosition);
		endRowPosition = selectionRowPosition;
		endColumnPosition = std::max(caretColumnPosition, selectionColumnPosition);
	}
}

void DirtMachine::UI::InputField::InsertTextIntoSelection(const DirtMachine::String& newText)
{
	std::size_t begin_row_position;
	std::size_t begin_column_position;
	std::size_t end_row_position;
	std::size_t end_column_position;
	GetSelectionInformation(begin_row_position, begin_column_position, end_row_position, end_column_position);
	if (isMultiLine)
	{
		DirtMachine::String end_string(textLines[end_row_position].substring(end_column_position));
		for (std::size_t row(end_row_position + static_cast<std::size_t>(1)); row != textLines.size(); row++)
		{
			end_string += "\n";
			end_string += textLines[row];
		}
		DirtMachine::String begin_text_line(textLines[begin_row_position].substring(static_cast<std::size_t>(0), begin_column_position));
		while (begin_row_position < textLines.size())
		{
			textLines.pop_back();
		}
		DirtMachine::String append_string;
		DirtMachine::String append_text_line;
		DirtMachine::String new_text;
		for (const sf::Uint32& new_text_character : newText)
		{
			if ((!std::iscntrl(new_text_character)) || (new_text_character == '\n'))
			{
				new_text += new_text_character;
			}
		}
		append_string += begin_text_line;
		append_string += new_text;
		textLines.push_back(DirtMachine::String());
		for (const sf::Uint32& append_string_character : append_string)
		{
			if (append_string_character == '\n')
			{
				textLines.push_back(DirtMachine::String());
			}
			else
			{
				textLines.back() += append_string_character;
			}
		}
		if (textLines.size() <= static_cast<std::size_t>(0))
		{
			textLines.push_back(std::string());
		}
		caretRowPosition = textLines.size() - static_cast<std::size_t>(1);
		caretColumnPosition = textLines[caretRowPosition].getSize();
		for (const sf::Uint32& end_string_character : end_string)
		{
			if (end_string_character == '\n')
			{
				textLines.push_back(DirtMachine::String());
			}
			else
			{
				textLines.back() += end_string_character;
			}
		}
		UpdateTextLineLabels();
	}
	else
	{
		DirtMachine::String& text_line(textLines.front());
		DirtMachine::String new_text;
		for (const sf::Uint32& new_text_character : newText)
		{
			if (new_text_character == '\n')
			{
				break;
			}
			else if (!std::iscntrl(new_text_character))
			{
				new_text += new_text_character;
			}
		}
		text_line = text_line.substring(static_cast<std::size_t>(0), begin_column_position) + new_text + ((end_column_position < text_line.getSize()) ? text_line.substring(end_column_position) : DirtMachine::String());
		caretColumnPosition = begin_column_position + new_text.getSize();
		ResetSelection();
		UpdateTextLineLabel(static_cast<std::size_t>(0));
	}
	ResetSelection();
}

void DirtMachine::UI::InputField::RemoveSelectedText()
{
	InsertTextIntoSelection(DirtMachine::String());
}

bool DirtMachine::UI::InputField::CopySelectedText() const
{
	bool ret(false);
	std::size_t begin_row_position;
	std::size_t begin_column_position;
	std::size_t end_row_position;
	std::size_t end_column_position;
	GetSelectionInformation(begin_row_position, begin_column_position, end_row_position, end_column_position);
	if ((begin_row_position != end_row_position) || (begin_column_position != end_column_position))
	{
		bool is_first(true);
		DirtMachine::String copy_string;
		for (std::size_t row(begin_row_position), end(end_row_position + static_cast<std::size_t>(1)); row != end; row++)
		{
			const std::string& text_line(textLines[row]);
			if (is_first)
			{
				is_first = false;
			}
			else
			{
				copy_string += "\n";
			}
			if (begin_row_position == end_row_position)
			{
				copy_string += text_line.substr(begin_column_position, end_column_position - begin_column_position);
			}
			else if (row == begin_row_position)
			{
				copy_string += text_line.substr(begin_column_position);
			}
			else if (row == end_row_position)
			{
				copy_string += text_line.substr(static_cast<std::size_t>(0), end_column_position);
			}
			else
			{
				copy_string += text_line;
			}
		}
		DirtMachine::Input::Clipboard::SetString(copy_string);
		ret = true;
	}
	return ret;
}

void DirtMachine::UI::InputField::SelectAllText()
{
	caretRowPosition = textLines.size() - static_cast<std::size_t>(1);
	caretColumnPosition = textLines[caretRowPosition].getSize();
	selectionRowPosition = static_cast<std::size_t>(0);
	selectionColumnPosition = static_cast<std::size_t>(0);
	UpdateSelection();
}

void DirtMachine::UI::InputField::RemoveBack()
{
	if ((caretRowPosition == selectionRowPosition) && (caretColumnPosition == selectionColumnPosition))
	{
		if (caretColumnPosition > static_cast<std::size_t>(0))
		{
			--selectionColumnPosition;
			RemoveSelectedText();
		}
		else if (caretRowPosition > static_cast<std::size_t>(0))
		{
			--selectionRowPosition;
			selectionColumnPosition = textLines[selectionRowPosition].getSize();
			RemoveSelectedText();
		}
	}
	else
	{
		RemoveSelectedText();
	}
}

void DirtMachine::UI::InputField::RemoveFront()
{
	if ((caretRowPosition == selectionRowPosition) && (caretColumnPosition == selectionColumnPosition))
	{
		const DirtMachine::String& text_line(textLines[caretRowPosition]);
		if (caretColumnPosition < text_line.getSize())
		{
			++caretColumnPosition;
			RemoveSelectedText();
		}
		else if ((caretRowPosition + static_cast<std::size_t>(1)) < textLines.size())
		{
			++caretRowPosition;
			caretColumnPosition = static_cast<std::size_t>(0);
			RemoveSelectedText();
		}
	}
	else
	{
		RemoveSelectedText();
	}
}

bool DirtMachine::UI::InputField::ProcessTextEntered(const DirtMachine::Input::Data::TextData& textData)
{
	if (!DirtMachine::UI::InteractableControl::ProcessTextEntered(textData))
	{
		if (!std::iscntrl(textData.unicode))
		{
			InsertTextIntoSelection(DirtMachine::String(textData.unicode));
		}
	}
	return true;
}

bool DirtMachine::UI::InputField::ProcessKeyPressed(const DirtMachine::Input::Data::KeyboardKeyData& keyboardKeyData)
{
	if (!DirtMachine::UI::InteractableControl::ProcessKeyPressed(keyboardKeyData))
	{
		switch (keyboardKeyData.keyCode)
		{
		case DirtMachine::Input::EKeyboardKey::A:
			if (keyboardKeyData.isControlKeyUsed)
			{
				SelectAllText();
			}
			break;
		case DirtMachine::Input::EKeyboardKey::C:
			if (keyboardKeyData.isControlKeyUsed)
			{
				CopySelectedText();
			}
			break;
		case DirtMachine::Input::EKeyboardKey::V:
			if (keyboardKeyData.isControlKeyUsed)
			{
				InsertTextIntoSelection(DirtMachine::Input::Clipboard::GetString());
			}
			break;
		case DirtMachine::Input::EKeyboardKey::X:
			if (keyboardKeyData.isControlKeyUsed)
			{
				CopySelectedText();
				RemoveSelectedText();
			}
			break;
		case DirtMachine::Input::EKeyboardKey::Up:
			if (caretRowPosition > static_cast<std::size_t>(0))
			{
				--caretRowPosition;
				if (!keyboardKeyData.isShiftKeyUsed)
				{
					ResetSelection();
				}
				UpdateSelection();
			}
			break;
		case DirtMachine::Input::EKeyboardKey::Down:
			if ((caretRowPosition + static_cast<std::size_t>(1)) < textLines.size())
			{
				++caretRowPosition;
				if (!keyboardKeyData.isShiftKeyUsed)
				{
					ResetSelection();
				}
				UpdateSelection();
			}
			break;
		case DirtMachine::Input::EKeyboardKey::Left:
			if (caretColumnPosition > static_cast<std::size_t>(0))
			{
				--caretColumnPosition;
				if (!keyboardKeyData.isShiftKeyUsed)
				{
					ResetSelection();
				}
				UpdateSelection();
			}
			else if (caretRowPosition > static_cast<std::size_t>(0))
			{
				--caretRowPosition;
				caretColumnPosition = textLines[caretRowPosition].getSize();
				if (!keyboardKeyData.isShiftKeyUsed)
				{
					ResetSelection();
				}
				UpdateSelection();
			}
			break;
		case DirtMachine::Input::EKeyboardKey::Right:
		{
			const DirtMachine::String& text_line(textLines[caretRowPosition]);
			if (caretColumnPosition < text_line.getSize())
			{
				++caretColumnPosition;
				if (!keyboardKeyData.isShiftKeyUsed)
				{
					ResetSelection();
				}
				UpdateSelection();
			}
			else if ((caretRowPosition + static_cast<std::size_t>(1)) < textLines.size())
			{
				++caretRowPosition;
				caretColumnPosition = 0;
				if (!keyboardKeyData.isShiftKeyUsed)
				{
					ResetSelection();
				}
				UpdateSelection();
			}
		}
		break;
		case DirtMachine::Input::EKeyboardKey::Backspace:
			RemoveBack();
			break;
		case DirtMachine::Input::EKeyboardKey::Delete:
			RemoveFront();
			break;
		case DirtMachine::Input::EKeyboardKey::Enter:
			if (isMultiLine)
			{
				InsertTextIntoSelection("\n");
			}
			break;
		}
	}
	return true;
}

void DirtMachine::UI::InputField::UpdateTextLineLabel(std::size_t textLineIndex)
{
	if (textLineIndex < textLineLabels.size())
	{
		textLineLabels[textLineIndex]->SetTextString(textLines[textLineIndex]);
	}
	else
	{
		while (textLineIndex >= textLineLabels.size())
		{
			std::shared_ptr<DirtMachine::UI::Label> text_line_label(backgroundPanel->CreateChild<DirtMachine::UI::Label>(textLines[textLineLabels.size()], textFont, textCharacterSize, DirtMachine::UI::ETextAlignment::TopLeft, glm::ivec2(0, static_cast<int>(textFont->getLineSpacing(textCharacterSize) * static_cast<float>(textLineLabels.size()))), 0.0f, GetSize()));
			textLineLabels.push_back(text_line_label);
			std::shared_ptr<DirtMachine::UI::Panel> selection_panel(text_line_label->CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U)));
			selection_panel->SetVisibleState(false);
			selection_panel->SetPrimaryBackgroundColour(DirtMachine::Graphic::Colour(0xFF, 0x00, 0x00, 0x1F));
			selectionPanels.push_back(selection_panel);
		}
	}
}

void DirtMachine::UI::InputField::UpdateTextLineLabels()
{
	for (std::size_t index(static_cast<std::size_t>(0)); (index != textLineLabels.size()) && (index != textLines.size()); index++)
	{
		textLineLabels[index]->SetTextString(textLines[index]);
	}
	while (textLineLabels.size() < textLines.size())
	{
		std::shared_ptr<DirtMachine::UI::Label> text_line_label(backgroundPanel->CreateChild<DirtMachine::UI::Label>(textLines[textLineLabels.size()], textFont, textCharacterSize, DirtMachine::UI::ETextAlignment::TopLeft, glm::ivec2(0, static_cast<int>(textFont->getLineSpacing(textCharacterSize) * static_cast<float>(textLineLabels.size()))), 0.0f, GetSize()));
		textLineLabels.push_back(text_line_label);
		std::shared_ptr<DirtMachine::UI::Panel> selection_panel(text_line_label->CreateChild<DirtMachine::UI::Panel>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U)));
		selection_panel->SetVisibleState(false);
		selection_panel->SetPrimaryBackgroundColour(DirtMachine::Graphic::Colour(0xFF, 0x00, 0x00, 0x1F));
		selectionPanels.push_back(selection_panel);
	}
	while (textLineLabels.size() > textLines.size())
	{
		backgroundPanel->RemoveChild(textLineLabels.back());
		textLineLabels.pop_back();
		selectionPanels.pop_back();
	}
}

void DirtMachine::UI::InputField::UpdateSelection()
{
	if (caretRowPosition >= textLines.size())
	{
		caretRowPosition = textLines.size() - static_cast<std::size_t>(1);
		caretColumnPosition = textLines[caretRowPosition].getSize();
	}
	if (selectionRowPosition >= textLines.size())
	{
		selectionRowPosition = textLines.size() - static_cast<std::size_t>(1);
		selectionColumnPosition = textLines[selectionRowPosition].getSize();
	}
	const DirtMachine::String& text_line(textLines[caretRowPosition]);
	if (caretColumnPosition > text_line.getSize())
	{
		caretColumnPosition = text_line.getSize();
	}
	if (selectionColumnPosition > text_line.getSize())
	{
		selectionColumnPosition = text_line.getSize();
	}
	std::size_t begin_row_position;
	std::size_t begin_column_position;
	std::size_t end_row_position;
	std::size_t end_column_position;
	GetSelectionInformation(begin_row_position, begin_column_position, end_row_position, end_column_position);
	for (std::size_t row(static_cast<std::size_t>(0)); row != textLines.size(); row++)
	{
		const std::shared_ptr<DirtMachine::UI::Label>& text_line_label(textLineLabels[row]);
		const std::shared_ptr<DirtMachine::UI::Panel>& selection_panel(selectionPanels[row]);
		if ((row < begin_row_position) || (row > end_row_position))
		{
			selection_panel->SetVisibleState(false);
		}
		else
		{
			glm::vec2 begin_text_character_position;
			glm::vec2 end_text_character_position;
			selection_panel->SetVisibleState(true);
			begin_text_character_position = text_line_label->FindTextCharacterPosition((begin_row_position == row) ? begin_column_position : static_cast<std::size_t>(0));
			end_text_character_position = ((end_row_position == row) && (end_column_position < textLines[row].getSize())) ?
				glm::vec2(static_cast<float>(text_line_label->FindTextCharacterPosition(end_column_position).x), static_cast<float>(text_line_label->GetTextCharacterSize())) :
				glm::vec2(static_cast<float>(text_line_label->FindTextCharacterPosition(textLines[row].getSize()).x), static_cast<float>(text_line_label->GetTextCharacterSize()));
			selection_panel->SetLocalPosition(begin_text_character_position);
			selection_panel->SetSize(end_text_character_position - begin_text_character_position);
		}
	}
	const std::shared_ptr<DirtMachine::UI::Label>& caret_text_line_label(textLineLabels[caretRowPosition]);
	caretLabel->SetLocalPosition(glm::ivec2(caret_text_line_label->FindTextCharacterPosition(caretColumnPosition).x - caret_text_line_label->GetTextLetterSpacing(), caret_text_line_label->GetLocalPosition().y));
}
