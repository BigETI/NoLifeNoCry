#include <UI/Control.hpp>

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultPrimaryBackgroundColour(0x0F, 0x0F, 0x0F, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultSecondaryBackgroundColour(0x1F, 0x1F, 0x1F, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultHighlightBackgroundColour(0x7F, 0x7F, 0x7F, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultPrimaryForegroundColour(0x3F, 0x3F, 0x3F, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultSecondaryForegroundColour(0x5F, 0x5F, 0x5F, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultHighlightForegroundColour(0xDF, 0xDF, 0xDF, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultPrimaryTextColour(0xFF, 0xFF, 0xFF, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultSecondaryTextColour(0xFF, 0xFF, 0xFF, 0xFF);

DirtMachine::Graphic::Colour DirtMachine::UI::Control::defaultHighlightTextColour(0xFF, 0xFF, 0xFF, 0xFF);

DirtMachine::UI::Control::Control(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, bool isEnabled, DirtMachine::UI::Control* parent) :
	position(position),
	rotation(rotation),
	size(size),
	parent(parent),
	isVisible(isVisible),
	isEnabled(isEnabled),
	primaryBackgroundColour(nullptr),
	secondaryBackgroundColour(nullptr),
	highlightBackgroundColour(nullptr),
	primaryForegroundColour(nullptr),
	secondaryForegroundColour(nullptr),
	highlightForegroundColour(nullptr),
	primaryTextColour(nullptr),
	secondaryTextColour(nullptr),
	highlightTextColour(nullptr)
{
	OnTransformationChanged += [this]()
	{
		for (std::shared_ptr<DirtMachine::UI::Control> child : children)
		{
			child->OnTransformationChanged();
		}
	};
	OnPrimaryBackgroundColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		if (!primaryBackgroundColour)
		{
			for (std::shared_ptr<DirtMachine::UI::Control> child : children)
			{
				child->OnPrimaryBackgroundColourChanged(colour);
			}
		}
	};
	OnSecondaryBackgroundColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		if (!secondaryBackgroundColour)
		{
			for (std::shared_ptr<DirtMachine::UI::Control> child : children)
			{
				child->OnSecondaryBackgroundColourChanged(colour);
			}
		}
	};
	OnHighlightBackgroundColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		if (!highlightBackgroundColour)
		{
			for (std::shared_ptr<DirtMachine::UI::Control> child : children)
			{
				child->OnHighlightBackgroundColourChanged(colour);
			}
		}
	};
	OnPrimaryForegroundColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		if (!primaryBackgroundColour)
		{
			for (std::shared_ptr<DirtMachine::UI::Control> child : children)
			{
				child->OnPrimaryForegroundColourChanged(colour);
			}
		}
	};
	OnSecondaryForegroundColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		if (!secondaryBackgroundColour)
		{
			for (std::shared_ptr<DirtMachine::UI::Control> child : children)
			{
				child->OnSecondaryForegroundColourChanged(colour);
			}
		}
	};
	OnHighlightForegroundColourChanged += [this](const DirtMachine::Graphic::Colour& colour)
	{
		if (!primaryBackgroundColour)
		{
			for (std::shared_ptr<DirtMachine::UI::Control> child : children)
			{
				child->OnHighlightForegroundColourChanged(colour);
			}
		}
	};
}

DirtMachine::UI::Control::~Control()
{
	delete primaryBackgroundColour;
	primaryBackgroundColour = nullptr;
	delete secondaryBackgroundColour;
	secondaryBackgroundColour = nullptr;
	delete highlightBackgroundColour;
	highlightBackgroundColour = nullptr;
	delete primaryForegroundColour;
	primaryForegroundColour = nullptr;
	delete secondaryForegroundColour;
	secondaryForegroundColour = nullptr;
	delete highlightForegroundColour;
	highlightForegroundColour = nullptr;
	delete primaryTextColour;
	primaryTextColour = nullptr;
	delete secondaryTextColour;
	secondaryTextColour = nullptr;
	delete highlightTextColour;
	highlightTextColour = nullptr;
}

const glm::ivec2& DirtMachine::UI::Control::GetLocalPosition() const
{
	return position;
}

void DirtMachine::UI::Control::SetLocalPosition(const glm::ivec2& newPosition)
{
	if (position != newPosition)
	{
		position = newPosition;
		OnTransformationChanged();
		ProcessMouseMoved({ GetMousePosition() });
	}
}

glm::ivec2 DirtMachine::UI::Control::GetGlobalPosition() const
{
	return position + (parent ? parent->GetGlobalPosition() : glm::ivec2(0, 0));
}

void DirtMachine::UI::Control::SetGlobalPosition(const glm::ivec2& newPosition)
{
	SetLocalPosition(newPosition - GetGlobalPosition());
}

glm::uvec2 DirtMachine::UI::Control::GetSize() const
{
	return size;
}

void DirtMachine::UI::Control::SetSize(const glm::uvec2& newSize)
{
	if (size != newSize)
	{
		size = newSize;
		OnTransformationChanged();
		ProcessMouseMoved({ GetMousePosition() });
	}
}

bool DirtMachine::UI::Control::IsVisible() const
{
	return isVisible;
}

void DirtMachine::UI::Control::SetVisible(bool visibleState)
{
	if (isVisible != visibleState)
	{
		isVisible = visibleState;
		if (isVisible)
		{
			ProcessMouseMoved({ GetMousePosition() });
		}
	}
}

bool DirtMachine::UI::Control::IsEnabled() const
{
	return isEnabled;
}

void DirtMachine::UI::Control::SetEnabled(bool enabledState)
{
	isEnabled = enabledState;
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetPrimaryBackgroundColour() const
{
	return primaryBackgroundColour ? *primaryBackgroundColour : (parent ? parent->GetPrimaryBackgroundColour() : defaultPrimaryBackgroundColour);
}

void DirtMachine::UI::Control::SetPrimaryBackgroundColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetPrimaryBackgroundColour());
	if (!primaryBackgroundColour)
	{
		primaryBackgroundColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*primaryBackgroundColour != colour)
	{
		*primaryBackgroundColour = colour;
	}
	if (old_colour != *primaryBackgroundColour)
	{
		OnPrimaryBackgroundColourChanged(*primaryBackgroundColour);
	}
}

void DirtMachine::UI::Control::ResetPrimaryBackgroundColour()
{
	DirtMachine::Graphic::Colour old_colour(GetPrimaryBackgroundColour());
	delete primaryBackgroundColour;
	primaryBackgroundColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetPrimaryBackgroundColour());
	if (old_colour != colour)
	{
		OnPrimaryBackgroundColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetSecondaryBackgroundColour() const
{
	return secondaryBackgroundColour ? *secondaryBackgroundColour : (parent ? parent->GetSecondaryBackgroundColour() : defaultSecondaryBackgroundColour);
}

void DirtMachine::UI::Control::SetSecondaryBackgroundColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetSecondaryBackgroundColour());
	if (!secondaryBackgroundColour)
	{
		secondaryBackgroundColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*secondaryBackgroundColour != colour)
	{
		*secondaryBackgroundColour = colour;
	}
	if (old_colour != *secondaryBackgroundColour)
	{
		OnSecondaryBackgroundColourChanged(*secondaryBackgroundColour);
	}
}

void DirtMachine::UI::Control::ResetSecondaryBackgroundColour()
{
	DirtMachine::Graphic::Colour old_colour(GetSecondaryBackgroundColour());
	delete secondaryBackgroundColour;
	secondaryBackgroundColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetSecondaryBackgroundColour());
	if (old_colour != colour)
	{
		OnSecondaryBackgroundColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetHighlightBackgroundColour() const
{
	return highlightBackgroundColour ? *highlightBackgroundColour : (parent ? parent->GetHighlightBackgroundColour() : defaultHighlightBackgroundColour);
}

void DirtMachine::UI::Control::SetHighlightBackgroundColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetHighlightBackgroundColour());
	if (!highlightBackgroundColour)
	{
		highlightBackgroundColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*highlightBackgroundColour != colour)
	{
		*highlightBackgroundColour = colour;
	}
	if (old_colour != *highlightBackgroundColour)
	{
		OnHighlightBackgroundColourChanged(*highlightBackgroundColour);
	}
}

void DirtMachine::UI::Control::ResetHighlightBackgroundColour()
{
	DirtMachine::Graphic::Colour old_colour(GetHighlightBackgroundColour());
	delete highlightBackgroundColour;
	highlightBackgroundColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetHighlightBackgroundColour());
	if (old_colour != colour)
	{
		OnHighlightBackgroundColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetPrimaryForegroundColour() const
{
	return primaryForegroundColour ? *primaryForegroundColour : (parent ? parent->GetPrimaryForegroundColour() : defaultPrimaryForegroundColour);
}

void DirtMachine::UI::Control::SetPrimaryForegroundColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetPrimaryForegroundColour());
	if (!primaryForegroundColour)
	{
		primaryForegroundColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*primaryForegroundColour != colour)
	{
		*primaryForegroundColour = colour;
	}
	if (old_colour != *primaryForegroundColour)
	{
		OnPrimaryForegroundColourChanged(*primaryForegroundColour);
	}
}

void DirtMachine::UI::Control::ResetPrimaryForegroundColour()
{
	DirtMachine::Graphic::Colour old_colour(GetPrimaryForegroundColour());
	delete primaryForegroundColour;
	primaryForegroundColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetPrimaryForegroundColour());
	if (old_colour != colour)
	{
		OnPrimaryForegroundColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetSecondaryForegroundColour() const
{
	return secondaryForegroundColour ? *secondaryForegroundColour : (parent ? parent->GetSecondaryForegroundColour() : defaultSecondaryForegroundColour);
}

void DirtMachine::UI::Control::SetSecondaryForegroundColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetSecondaryForegroundColour());
	if (!secondaryForegroundColour)
	{
		secondaryForegroundColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*secondaryForegroundColour != colour)
	{
		*secondaryForegroundColour = colour;
	}
	if (old_colour != *secondaryForegroundColour)
	{
		OnSecondaryForegroundColourChanged(*secondaryForegroundColour);
	}
}

void DirtMachine::UI::Control::ResetSecondaryForegroundColour()
{
	DirtMachine::Graphic::Colour old_colour(GetSecondaryForegroundColour());
	delete secondaryForegroundColour;
	secondaryForegroundColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetSecondaryForegroundColour());
	if (old_colour != colour)
	{
		OnSecondaryForegroundColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetHighlightForegroundColour() const
{
	return highlightForegroundColour ? *highlightForegroundColour : (parent ? parent->GetHighlightForegroundColour() : defaultHighlightForegroundColour);
}

void DirtMachine::UI::Control::SetHighlightForegroundColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetHighlightForegroundColour());
	if (!highlightForegroundColour)
	{
		highlightForegroundColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*highlightForegroundColour != colour)
	{
		*highlightForegroundColour = colour;
	}
	if (old_colour != *highlightForegroundColour)
	{
		OnHighlightForegroundColourChanged(*highlightForegroundColour);
	}
}

void DirtMachine::UI::Control::ResetHighlightForegroundColour()
{
	DirtMachine::Graphic::Colour old_colour(GetHighlightForegroundColour());
	delete highlightForegroundColour;
	highlightForegroundColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetHighlightForegroundColour());
	if (old_colour != colour)
	{
		OnHighlightForegroundColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetPrimaryTextColour() const
{
	return primaryTextColour ? *primaryTextColour : (parent ? parent->GetPrimaryTextColour() : defaultPrimaryTextColour);
}

void DirtMachine::UI::Control::SetPrimaryTextColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetPrimaryTextColour());
	if (!primaryTextColour)
	{
		primaryTextColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*primaryTextColour != colour)
	{
		*primaryTextColour = colour;
	}
	if (old_colour != *primaryTextColour)
	{
		OnPrimaryTextColourChanged(*primaryTextColour);
	}
}

void DirtMachine::UI::Control::ResetPrimaryTextColour()
{
	DirtMachine::Graphic::Colour old_colour(GetPrimaryTextColour());
	delete primaryTextColour;
	primaryTextColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetPrimaryTextColour());
	if (old_colour != colour)
	{
		OnPrimaryTextColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetSecondaryTextColour() const
{
	return secondaryTextColour ? *secondaryTextColour : (parent ? parent->GetSecondaryTextColour() : defaultSecondaryTextColour);
}

void DirtMachine::UI::Control::SetSecondaryTextColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetSecondaryTextColour());
	if (!secondaryTextColour)
	{
		secondaryTextColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*secondaryTextColour != colour)
	{
		*secondaryTextColour = colour;
	}
	if (old_colour != *secondaryTextColour)
	{
		OnSecondaryTextColourChanged(*secondaryTextColour);
	}
}

void DirtMachine::UI::Control::ResetSecondaryTextColour()
{
	DirtMachine::Graphic::Colour old_colour(GetSecondaryTextColour());
	delete secondaryTextColour;
	secondaryTextColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetSecondaryTextColour());
	if (old_colour != colour)
	{
		OnSecondaryTextColourChanged(colour);
	}
}

const DirtMachine::Graphic::Colour& DirtMachine::UI::Control::GetHighlightTextColour() const
{
	return highlightTextColour ? *highlightTextColour : (parent ? parent->GetHighlightTextColour() : defaultHighlightTextColour);
}

void DirtMachine::UI::Control::SetHighlightTextColour(const DirtMachine::Graphic::Colour& colour)
{
	DirtMachine::Graphic::Colour old_colour(GetHighlightTextColour());
	if (!highlightTextColour)
	{
		highlightTextColour = new DirtMachine::Graphic::Colour(colour);
	}
	if (*highlightTextColour != colour)
	{
		*highlightTextColour = colour;
	}
	if (old_colour != *highlightTextColour)
	{
		OnHighlightTextColourChanged(*highlightTextColour);
	}
}

void DirtMachine::UI::Control::ResetHighlightTextColour()
{
	DirtMachine::Graphic::Colour old_colour(GetHighlightTextColour());
	delete highlightTextColour;
	highlightTextColour = nullptr;
	DirtMachine::Graphic::Colour colour(GetHighlightTextColour());
	if (old_colour != colour)
	{
		OnHighlightTextColourChanged(colour);
	}
}

bool DirtMachine::UI::Control::HasParent() const
{
	return parent;
}

DirtMachine::UI::Control* DirtMachine::UI::Control::GetParent() const
{
	return parent;
}

std::size_t DirtMachine::UI::Control::GetChildCount() const
{
	return children.size();
}

DirtMachine::UI::Control& DirtMachine::UI::Control::GetChild(std::size_t index)
{
	return *(children[index].get());
}

const DirtMachine::UI::Control& DirtMachine::UI::Control::GetChild(std::size_t index) const
{
	return *(children[index].get());
}

bool DirtMachine::UI::Control::IsMouseOnWindow() const
{
	return parent ? parent->IsMouseOnWindow() : false;
}

bool DirtMachine::UI::Control::IsWindowFocused() const
{
	return parent ? parent->IsWindowFocused() : false;
}

glm::ivec2 DirtMachine::UI::Control::GetMousePosition() const
{
	return parent ? parent->GetMousePosition() : glm::ivec2(0, 0);
}

void DirtMachine::UI::Control::Draw(DirtMachine::Graphic::RenderTarget& renderTarget) const
{
	for (const std::shared_ptr<Control>& child : children)
	{
		if (child->IsVisible())
		{
			child->PushDrawingState(renderTarget);
			child->Draw(renderTarget);
			child->PopDrawingState(renderTarget);
		}
	}
}

bool DirtMachine::UI::Control::ProcessTextEntered(const DirtMachine::Input::Data::TextData& textData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessTextEntered(textData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessKeyPressed(const DirtMachine::Input::Data::KeyboardKeyData& keyboardKeyData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessKeyPressed(keyboardKeyData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessKeyReleased(const DirtMachine::Input::Data::KeyboardKeyData& keyboardKeyData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessKeyReleased(keyboardKeyData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessMouseWheelScrolled(const DirtMachine::Input::Data::MouseWheelData& mouseWheelData)
{
	bool ret(false);
	DirtMachine::Input::Data::MouseWheelData local_mouse_wheel_data({ mouseWheelData.wheel, mouseWheelData.delta, mouseWheelData.position - position });
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessMouseWheelScrolled(local_mouse_wheel_data);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessMouseButtonPressed(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessMouseButtonPressed(mouseButtonData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessMouseButtonReleased(const DirtMachine::Input::Data::MouseButtonData& mouseButtonData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessMouseButtonReleased(mouseButtonData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessMouseMoved(const DirtMachine::Input::Data::MouseMovementData& mouseMovementData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessMouseMoved(mouseMovementData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessWindowMouseEntered()
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessWindowMouseEntered();
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessWindowMouseLeft()
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessWindowMouseLeft();
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessJoystickButtonPressed(const DirtMachine::Input::Data::JoystickButtonData& joystickButtonData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessJoystickButtonPressed(joystickButtonData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessJoystickButtonReleased(const DirtMachine::Input::Data::JoystickButtonData& joystickButtonData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessJoystickButtonReleased(joystickButtonData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessJoystickMoved(const DirtMachine::Input::Data::JoystickMovementData& joystickMovementData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessJoystickMoved(joystickMovementData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessJoystickConnected(const DirtMachine::Input::Data::JoystickConnectionData& joystickConnectionData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessJoystickConnected(joystickConnectionData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessJoystickDisconnected(const DirtMachine::Input::Data::JoystickConnectionData& joystickConnectionData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessJoystickDisconnected(joystickConnectionData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessTouchBegan(const DirtMachine::Input::Data::TouchData& touchData)
{
	bool ret(false);
	glm::ivec2 local_position = touchData.position - GetGlobalPosition();
	if ((local_position.x >= 0) && (local_position.x <= static_cast<int>(size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(size.y)))
	{
		for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
		{
			if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
			{
				ret = (*reverse_iterator)->ProcessTouchBegan(touchData);
				if (ret)
				{
					break;
				}
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessTouchMoved(const DirtMachine::Input::Data::TouchData& touchData)
{
	bool ret(false);
	glm::ivec2 local_position = touchData.position - GetGlobalPosition();
	if ((local_position.x >= 0) && (local_position.x <= static_cast<int>(size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(size.y)))
	{
		for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
		{
			if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
			{
				ret = (*reverse_iterator)->ProcessTouchMoved(touchData);
				if (ret)
				{
					break;
				}
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessTouchEnded(const DirtMachine::Input::Data::TouchData& touchData)
{
	bool ret(false);
	glm::ivec2 local_position = touchData.position - GetGlobalPosition();
	if ((local_position.x >= 0) && (local_position.x <= static_cast<int>(size.x)) && (local_position.y >= 0) && (local_position.y <= static_cast<int>(size.y)))
	{
		for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
		{
			if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
			{
				ret = (*reverse_iterator)->ProcessTouchEnded(touchData);
				if (ret)
				{
					break;
				}
			}
		}
	}
	return ret;
}

bool DirtMachine::UI::Control::ProcessSensorChanged(const DirtMachine::Input::Data::SensorData& sensorData)
{
	bool ret(false);
	for (std::vector<std::shared_ptr<Control>>::const_reverse_iterator reverse_iterator(children.crbegin()), reverse_end(children.crend()); reverse_iterator != reverse_end; reverse_iterator++)
	{
		if ((*reverse_iterator)->IsVisible() && (*reverse_iterator)->IsEnabled())
		{
			ret = (*reverse_iterator)->ProcessSensorChanged(sensorData);
			if (ret)
			{
				break;
			}
		}
	}
	return ret;
}

void DirtMachine::UI::Control::PushDrawingState(DirtMachine::Graphic::RenderTarget& renderTarget)
{
	originalView = renderTarget.getView();
	sf::View view(originalView);
	glm::vec2 move_position(-GetLocalPosition());
	view.rotate(-rotation);
	view.move({ move_position.x, move_position.y });
	renderTarget.setView(view);
}

void DirtMachine::UI::Control::PopDrawingState(DirtMachine::Graphic::RenderTarget& renderTarget)
{
	renderTarget.setView(originalView);
}
