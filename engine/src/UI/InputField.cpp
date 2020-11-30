#include <cmath>
#include <iostream>
#include <Input/EKeyboardKey.hpp>
#include <Input/Clipboard.hpp>
#include <UI/InputField.hpp>

NoLifeNoCry::Engine::UI::InputField::InputField(const glm::ivec2& position, float rotation, const glm::uvec2& size, const NoLifeNoCry::Engine::String& textString, const NoLifeNoCry::Engine::String& hintTextString, const NoLifeNoCry::Engine::Graphic::Font* textFont, unsigned int textCharacterSize, NoLifeNoCry::Engine::UI::Control* parent) :
	NoLifeNoCry::Engine::UI::InteractableControl(position, rotation, size, true, true, true, false, parent),
	backgroundPanel(nullptr),
	caretLabel(nullptr),
	textFont(textFont),
	textCharacterSize(textCharacterSize),
	caretRowPosition(static_cast<std::size_t>(0)),
	caretColumnPosition(static_cast<std::size_t>(0)),
	selectionRowPosition(static_cast<std::size_t>(0)),
	selectionColumnPosition(static_cast<std::size_t>(0))
{
	backgroundPanel = CreateChild<NoLifeNoCry::Engine::UI::Panel>(glm::ivec2(0, 0), 0.0f, size);
	caretLabel = CreateChild<NoLifeNoCry::Engine::UI::Label>("|", textFont, textCharacterSize, NoLifeNoCry::Engine::UI::ETextAlignment::TopLeft, glm::ivec2(0, 0), 0.0f, size);
	textLines.push_back(std::string());
	SetText(textString);
	OnTransformationChanged += [this]()
	{
		glm::uvec2 size(GetSize());
		backgroundPanel->SetSize(size);
		for (const std::shared_ptr<NoLifeNoCry::Engine::UI::Label>& text_line_label : textLineLabels)
		{
			text_line_label->SetSize(size);
		}
	};
}

NoLifeNoCry::Engine::UI::InputField::~InputField()
{
	// ...
}

NoLifeNoCry::Engine::String NoLifeNoCry::Engine::UI::InputField::GetTextLine(std::size_t textLineIndex) const
{
	return (textLineIndex < textLines.size()) ? textLines[textLineIndex] : NoLifeNoCry::Engine::String();
}

void NoLifeNoCry::Engine::UI::InputField::SetTextLine(std::size_t textLineIndex, const NoLifeNoCry::Engine::String& textLine)
{
	if (textLineIndex < textLines.size())
	{
		UpdateTextLineLabel(textLineIndex);
	}
	else
	{
		while (textLineIndex >= textLines.size())
		{
			textLines.push_back((textLineIndex == textLines.size()) ? textLine : NoLifeNoCry::Engine::String());
			UpdateTextLineLabel(textLineIndex);
		}
	}
	ResetSelection();
}

std::size_t NoLifeNoCry::Engine::UI::InputField::GetTextLineCount() const
{
	return textLines.size();
}

NoLifeNoCry::Engine::String NoLifeNoCry::Engine::UI::InputField::GetText() const
{
	NoLifeNoCry::Engine::String ret;
	bool is_first(true);
	for (const NoLifeNoCry::Engine::String& text_line : textLines)
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

void NoLifeNoCry::Engine::UI::InputField::SetText(const NoLifeNoCry::Engine::String& newText)
{
	NoLifeNoCry::Engine::String text_line;
	textLines.clear();
	textLines.push_back(NoLifeNoCry::Engine::String());
	for (const sf::Uint32& new_text_character : newText)
	{
		if (new_text_character == '\n')
		{
			textLines.push_back(NoLifeNoCry::Engine::String());
		}
		else
		{
			textLines.back() += new_text_character;
		}
	}
	UpdateTextLineLabels();
	ResetSelection();
}

NoLifeNoCry::Engine::String NoLifeNoCry::Engine::UI::InputField::GetHintText() const
{
	// TODO
	return NoLifeNoCry::Engine::String();
}

void NoLifeNoCry::Engine::UI::InputField::SetHintText(const NoLifeNoCry::Engine::String& newText)
{
	// TODO
}

void NoLifeNoCry::Engine::UI::InputField::ResetSelection()
{
	selectionRowPosition = caretRowPosition;
	selectionColumnPosition = caretColumnPosition;
	UpdateSelection();
}

void NoLifeNoCry::Engine::UI::InputField::GetSelectionInformation(std::size_t& beginRowPosition, std::size_t& beginColumnPosition, std::size_t& endRowPosition, std::size_t& endColumnPosition) const
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

void NoLifeNoCry::Engine::UI::InputField::InsertTextIntoSelection(const NoLifeNoCry::Engine::String& newText)
{
	std::size_t begin_row_position;
	std::size_t begin_column_position;
	std::size_t end_row_position;
	std::size_t end_column_position;
	GetSelectionInformation(begin_row_position, begin_column_position, end_row_position, end_column_position);
	NoLifeNoCry::Engine::String end_string(textLines[end_row_position].substring(end_column_position));
	for (std::size_t row(end_row_position + static_cast<std::size_t>(1)); row != textLines.size(); row++)
	{
		end_string += "\n";
		end_string += textLines[row];
	}
	NoLifeNoCry::Engine::String begin_text_line(textLines[begin_row_position].substring(static_cast<std::size_t>(0), begin_column_position));
	while (begin_row_position < textLines.size())
	{
		textLines.pop_back();
	}
	NoLifeNoCry::Engine::String append_string;
	NoLifeNoCry::Engine::String append_text_line;
	NoLifeNoCry::Engine::String new_text;
	for (const sf::Uint32& new_text_character : newText)
	{
		if ((!std::iscntrl(new_text_character)) || (new_text_character == '\n'))
		{
			new_text += new_text_character;
		}
	}
	append_string += begin_text_line;
	append_string += new_text;
	textLines.push_back(NoLifeNoCry::Engine::String());
	for (const sf::Uint32& append_string_character : append_string)
	{
		if (append_string_character == '\n')
		{
			textLines.push_back(NoLifeNoCry::Engine::String());
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
			textLines.push_back(NoLifeNoCry::Engine::String());
		}
		else
		{
			textLines.back() += end_string_character;
		}
	}
	UpdateTextLineLabels();
	ResetSelection();
}

void NoLifeNoCry::Engine::UI::InputField::RemoveSelectedText()
{
	InsertTextIntoSelection(NoLifeNoCry::Engine::String());
}

bool NoLifeNoCry::Engine::UI::InputField::CopySelectedText() const
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
		NoLifeNoCry::Engine::String copy_string;
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
		NoLifeNoCry::Engine::Input::Clipboard::SetString(copy_string);
		ret = true;
	}
	return ret;
}

void NoLifeNoCry::Engine::UI::InputField::SelectAllText()
{
	caretRowPosition = textLines.size() - static_cast<std::size_t>(1);
	caretColumnPosition = textLines[caretRowPosition].getSize();
	selectionRowPosition = static_cast<std::size_t>(0);
	selectionColumnPosition = static_cast<std::size_t>(0);
	UpdateSelection();
}

void NoLifeNoCry::Engine::UI::InputField::RemoveBack()
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

void NoLifeNoCry::Engine::UI::InputField::RemoveFront()
{
	if ((caretRowPosition == selectionRowPosition) && (caretColumnPosition == selectionColumnPosition))
	{
		const NoLifeNoCry::Engine::String& text_line(textLines[caretRowPosition]);
		if ((caretColumnPosition + static_cast<std::size_t>(1)) < text_line.getSize())
		{
			++caretColumnPosition;
			RemoveSelectedText();
		}
		else if ((caretRowPosition + static_cast<std::size_t>(1)) > static_cast<std::size_t>(0))
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

bool NoLifeNoCry::Engine::UI::InputField::ProcessTextEntered(const NoLifeNoCry::Engine::Input::Data::TextData& textData)
{
	if (!NoLifeNoCry::Engine::UI::InteractableControl::ProcessTextEntered(textData))
	{
		if (!std::iscntrl(textData.unicode))
		{
			InsertTextIntoSelection(NoLifeNoCry::Engine::String(textData.unicode));
		}
	}
	return true;
}

bool NoLifeNoCry::Engine::UI::InputField::ProcessKeyPressed(const NoLifeNoCry::Engine::Input::Data::KeyboardKeyData& keyboardKeyData)
{
	if (!NoLifeNoCry::Engine::UI::InteractableControl::ProcessKeyPressed(keyboardKeyData))
	{
		switch (keyboardKeyData.keyCode)
		{
		case NoLifeNoCry::Engine::Input::EKeyboardKey::A:
			if (keyboardKeyData.isControlKeyUsed)
			{
				SelectAllText();
			}
			break;
		case NoLifeNoCry::Engine::Input::EKeyboardKey::C:
			if (keyboardKeyData.isControlKeyUsed)
			{
				CopySelectedText();
			}
			break;
		case NoLifeNoCry::Engine::Input::EKeyboardKey::V:
			if (keyboardKeyData.isControlKeyUsed)
			{
				InsertTextIntoSelection(NoLifeNoCry::Engine::Input::Clipboard::GetString());
			}
			break;
		case NoLifeNoCry::Engine::Input::EKeyboardKey::X:
			if (keyboardKeyData.isControlKeyUsed)
			{
				CopySelectedText();
				RemoveSelectedText();
			}
			break;
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Up:
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
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Down:
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
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Left:
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
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Right:
		{
			const NoLifeNoCry::Engine::String& text_line(textLines[caretRowPosition]);
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
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Backspace:
			RemoveBack();
			break;
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Delete:
			RemoveFront();
			break;
		case NoLifeNoCry::Engine::Input::EKeyboardKey::Enter:
			InsertTextIntoSelection("\r\n");
			break;
		}
	}
	return true;
}

void NoLifeNoCry::Engine::UI::InputField::UpdateTextLineLabel(std::size_t textLineIndex)
{
	if (textLineIndex < textLineLabels.size())
	{
		textLineLabels[textLineIndex]->SetTextString(textLines[textLineIndex]);
	}
	else
	{
		while (textLineIndex >= textLineLabels.size())
		{
			std::shared_ptr<NoLifeNoCry::Engine::UI::Label> text_line_label(backgroundPanel->CreateChild<NoLifeNoCry::Engine::UI::Label>(textLines[textLineLabels.size()], textFont, textCharacterSize, NoLifeNoCry::Engine::UI::ETextAlignment::TopLeft, glm::ivec2(0, static_cast<int>(textFont->getLineSpacing(textCharacterSize) * static_cast<float>(textLineLabels.size()))), 0.0f, GetSize()));
			textLineLabels.push_back(text_line_label);
			std::shared_ptr<NoLifeNoCry::Engine::UI::Panel> selection_panel(text_line_label->CreateChild<NoLifeNoCry::Engine::UI::Panel>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U)));
			selection_panel->SetVisible(false);
			selection_panel->SetPrimaryBackgroundColour(NoLifeNoCry::Engine::Graphic::Colour(0xFF, 0x00, 0x00, 0x1F));
			selectionPanels.push_back(selection_panel);
		}
	}
}

void NoLifeNoCry::Engine::UI::InputField::UpdateTextLineLabels()
{
	for (std::size_t index(static_cast<std::size_t>(0)); (index != textLineLabels.size()) && (index != textLines.size()); index++)
	{
		textLineLabels[index]->SetTextString(textLines[index]);
	}
	while (textLineLabels.size() < textLines.size())
	{
		std::shared_ptr<NoLifeNoCry::Engine::UI::Label> text_line_label(backgroundPanel->CreateChild<NoLifeNoCry::Engine::UI::Label>(textLines[textLineLabels.size()], textFont, textCharacterSize, NoLifeNoCry::Engine::UI::ETextAlignment::TopLeft, glm::ivec2(0, static_cast<int>(textFont->getLineSpacing(textCharacterSize) * static_cast<float>(textLineLabels.size()))), 0.0f, GetSize()));
		textLineLabels.push_back(text_line_label);
		std::shared_ptr<NoLifeNoCry::Engine::UI::Panel> selection_panel(text_line_label->CreateChild<NoLifeNoCry::Engine::UI::Panel>(glm::ivec2(0, 0), 0.0f, glm::uvec2(0U, 0U)));
		selection_panel->SetVisible(false);
		selection_panel->SetPrimaryBackgroundColour(NoLifeNoCry::Engine::Graphic::Colour(0xFF, 0x00, 0x00, 0x1F));
		selectionPanels.push_back(selection_panel);
	}
	while (textLineLabels.size() > textLines.size())
	{
		backgroundPanel->RemoveChild(textLineLabels.back());
		textLineLabels.pop_back();
		selectionPanels.pop_back();
	}
}

void NoLifeNoCry::Engine::UI::InputField::UpdateSelection()
{
	if (caretRowPosition >= textLines.size())
	{
		caretRowPosition = textLines.size() - static_cast<std::size_t>(1);
	}
	if (selectionRowPosition >= textLines.size())
	{
		selectionRowPosition = textLines.size() - static_cast<std::size_t>(1);
	}
	const NoLifeNoCry::Engine::String& text_line(textLines[caretRowPosition]);
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
		const std::shared_ptr<NoLifeNoCry::Engine::UI::Label>& text_line_label(textLineLabels[row]);
		const std::shared_ptr<NoLifeNoCry::Engine::UI::Panel>& selection_panel(selectionPanels[row]);
		if ((row < begin_row_position) || (row > end_row_position))
		{
			selection_panel->SetVisible(false);
		}
		else
		{
			glm::vec2 begin_text_character_position;
			glm::vec2 end_text_character_position;
			selection_panel->SetVisible(true);
			begin_text_character_position = text_line_label->FindTextCharacterPosition((begin_row_position == row) ? begin_column_position : static_cast<std::size_t>(0));
			end_text_character_position = ((end_row_position == row) && (end_column_position < textLines[row].getSize())) ?
				glm::vec2(static_cast<float>(text_line_label->FindTextCharacterPosition(end_column_position).x), static_cast<float>(text_line_label->GetTextCharacterSize())) :
				glm::vec2(static_cast<float>(text_line_label->FindTextCharacterPosition(textLines[row].getSize()).x), static_cast<float>(text_line_label->GetTextCharacterSize()));
			selection_panel->SetLocalPosition(begin_text_character_position);
			selection_panel->SetSize(end_text_character_position - begin_text_character_position);
		}
	}
	const std::shared_ptr<NoLifeNoCry::Engine::UI::Label>& caret_text_line_label(textLineLabels[caretRowPosition]);
	caretLabel->SetLocalPosition(glm::ivec2(caret_text_line_label->FindTextCharacterPosition(caretColumnPosition).x - caret_text_line_label->GetTextLetterSpacing(), caret_text_line_label->GetLocalPosition().y));
}
