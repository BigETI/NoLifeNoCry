#include <UI/Control.hpp>

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultPrimaryBackgroundColour(0x0F, 0x0F, 0x0F, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultSecondaryBackgroundColour(0x1F, 0x1F, 0x1F, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultHighlightBackgroundColour(0x7F, 0x7F, 0x7F, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultPrimaryForegroundColour(0x3F, 0x3F, 0x3F, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultSecondaryForegroundColour(0x5F, 0x5F, 0x5F, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultHighlightForegroundColour(0xDF, 0xDF, 0xDF, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultPrimaryTextColour(0xFF, 0xFF, 0xFF, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultSecondaryTextColour(0xFF, 0xFF, 0xFF, 0xFF);

NoLifeNoCry::Engine::Graphic::Colour NoLifeNoCry::Engine::UI::Control::defaultHighlightTextColour(0xFF, 0xFF, 0xFF, 0xFF);

NoLifeNoCry::Engine::UI::Control::Control(const glm::ivec2& position, float rotation, const glm::uvec2& size, bool isVisible, bool isEnabled, NoLifeNoCry::Engine::UI::Control* parent) :
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
		for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
		{
			child->OnTransformationChanged();
		}
	};
	OnPrimaryBackgroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		if (!primaryBackgroundColour)
		{
			for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
			{
				child->OnPrimaryBackgroundColourChanged(colour);
			}
		}
	};
	OnSecondaryBackgroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		if (!secondaryBackgroundColour)
		{
			for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
			{
				child->OnSecondaryBackgroundColourChanged(colour);
			}
		}
	};
	OnHighlightBackgroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		if (!highlightBackgroundColour)
		{
			for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
			{
				child->OnHighlightBackgroundColourChanged(colour);
			}
		}
	};
	OnPrimaryForegroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		if (!primaryBackgroundColour)
		{
			for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
			{
				child->OnPrimaryForegroundColourChanged(colour);
			}
		}
	};
	OnSecondaryForegroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		if (!secondaryBackgroundColour)
		{
			for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
			{
				child->OnSecondaryForegroundColourChanged(colour);
			}
		}
	};
	OnHighlightForegroundColourChanged += [this](const NoLifeNoCry::Engine::Graphic::Colour& colour)
	{
		if (!primaryBackgroundColour)
		{
			for (std::shared_ptr<NoLifeNoCry::Engine::UI::Control> child : children)
			{
				child->OnHighlightForegroundColourChanged(colour);
			}
		}
	};
}

NoLifeNoCry::Engine::UI::Control::~Control()
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

const glm::ivec2& NoLifeNoCry::Engine::UI::Control::GetLocalPosition() const
{
	return position;
}

void NoLifeNoCry::Engine::UI::Control::SetLocalPosition(const glm::ivec2& newPosition)
{
	if (position != newPosition)
	{
		position = newPosition;
		OnTransformationChanged();
		ProcessMouseMoved({ GetMousePosition() });
	}
}

glm::ivec2 NoLifeNoCry::Engine::UI::Control::GetGlobalPosition() const
{
	return position + (parent ? parent->GetGlobalPosition() : glm::ivec2(0, 0));
}

void NoLifeNoCry::Engine::UI::Control::SetGlobalPosition(const glm::ivec2& newPosition)
{
	SetLocalPosition(newPosition - GetGlobalPosition());
}

glm::uvec2 NoLifeNoCry::Engine::UI::Control::GetSize() const
{
	return size;
}

void NoLifeNoCry::Engine::UI::Control::SetSize(const glm::uvec2& newSize)
{
	if (size != newSize)
	{
		size = newSize;
		OnTransformationChanged();
		ProcessMouseMoved({ GetMousePosition() });
	}
}

bool NoLifeNoCry::Engine::UI::Control::IsVisible() const
{
	return isVisible;
}

void NoLifeNoCry::Engine::UI::Control::SetVisible(bool visibleState)
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

bool NoLifeNoCry::Engine::UI::Control::IsEnabled() const
{
	return isEnabled;
}

void NoLifeNoCry::Engine::UI::Control::SetEnabled(bool enabledState)
{
	isEnabled = enabledState;
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetPrimaryBackgroundColour() const
{
	return primaryBackgroundColour ? *primaryBackgroundColour : (parent ? parent->GetPrimaryBackgroundColour() : defaultPrimaryBackgroundColour);
}

void NoLifeNoCry::Engine::UI::Control::SetPrimaryBackgroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetPrimaryBackgroundColour());
	if (!primaryBackgroundColour)
	{
		primaryBackgroundColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetPrimaryBackgroundColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetPrimaryBackgroundColour());
	delete primaryBackgroundColour;
	primaryBackgroundColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetPrimaryBackgroundColour());
	if (old_colour != colour)
	{
		OnPrimaryBackgroundColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetSecondaryBackgroundColour() const
{
	return secondaryBackgroundColour ? *secondaryBackgroundColour : (parent ? parent->GetSecondaryBackgroundColour() : defaultSecondaryBackgroundColour);
}

void NoLifeNoCry::Engine::UI::Control::SetSecondaryBackgroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetSecondaryBackgroundColour());
	if (!secondaryBackgroundColour)
	{
		secondaryBackgroundColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetSecondaryBackgroundColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetSecondaryBackgroundColour());
	delete secondaryBackgroundColour;
	secondaryBackgroundColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetSecondaryBackgroundColour());
	if (old_colour != colour)
	{
		OnSecondaryBackgroundColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetHighlightBackgroundColour() const
{
	return highlightBackgroundColour ? *highlightBackgroundColour : (parent ? parent->GetHighlightBackgroundColour() : defaultHighlightBackgroundColour);
}

void NoLifeNoCry::Engine::UI::Control::SetHighlightBackgroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetHighlightBackgroundColour());
	if (!highlightBackgroundColour)
	{
		highlightBackgroundColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetHighlightBackgroundColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetHighlightBackgroundColour());
	delete highlightBackgroundColour;
	highlightBackgroundColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetHighlightBackgroundColour());
	if (old_colour != colour)
	{
		OnHighlightBackgroundColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetPrimaryForegroundColour() const
{
	return primaryForegroundColour ? *primaryForegroundColour : (parent ? parent->GetPrimaryForegroundColour() : defaultPrimaryForegroundColour);
}

void NoLifeNoCry::Engine::UI::Control::SetPrimaryForegroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetPrimaryForegroundColour());
	if (!primaryForegroundColour)
	{
		primaryForegroundColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetPrimaryForegroundColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetPrimaryForegroundColour());
	delete primaryForegroundColour;
	primaryForegroundColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetPrimaryForegroundColour());
	if (old_colour != colour)
	{
		OnPrimaryForegroundColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetSecondaryForegroundColour() const
{
	return secondaryForegroundColour ? *secondaryForegroundColour : (parent ? parent->GetSecondaryForegroundColour() : defaultSecondaryForegroundColour);
}

void NoLifeNoCry::Engine::UI::Control::SetSecondaryForegroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetSecondaryForegroundColour());
	if (!secondaryForegroundColour)
	{
		secondaryForegroundColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetSecondaryForegroundColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetSecondaryForegroundColour());
	delete secondaryForegroundColour;
	secondaryForegroundColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetSecondaryForegroundColour());
	if (old_colour != colour)
	{
		OnSecondaryForegroundColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetHighlightForegroundColour() const
{
	return highlightForegroundColour ? *highlightForegroundColour : (parent ? parent->GetHighlightForegroundColour() : defaultHighlightForegroundColour);
}

void NoLifeNoCry::Engine::UI::Control::SetHighlightForegroundColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetHighlightForegroundColour());
	if (!highlightForegroundColour)
	{
		highlightForegroundColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetHighlightForegroundColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetHighlightForegroundColour());
	delete highlightForegroundColour;
	highlightForegroundColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetHighlightForegroundColour());
	if (old_colour != colour)
	{
		OnHighlightForegroundColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetPrimaryTextColour() const
{
	return primaryTextColour ? *primaryTextColour : (parent ? parent->GetPrimaryTextColour() : defaultPrimaryTextColour);
}

void NoLifeNoCry::Engine::UI::Control::SetPrimaryTextColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetPrimaryTextColour());
	if (!primaryTextColour)
	{
		primaryTextColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetPrimaryTextColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetPrimaryTextColour());
	delete primaryTextColour;
	primaryTextColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetPrimaryTextColour());
	if (old_colour != colour)
	{
		OnPrimaryTextColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetSecondaryTextColour() const
{
	return secondaryTextColour ? *secondaryTextColour : (parent ? parent->GetSecondaryTextColour() : defaultSecondaryTextColour);
}

void NoLifeNoCry::Engine::UI::Control::SetSecondaryTextColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetSecondaryTextColour());
	if (!secondaryTextColour)
	{
		secondaryTextColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetSecondaryTextColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetSecondaryTextColour());
	delete secondaryTextColour;
	secondaryTextColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetSecondaryTextColour());
	if (old_colour != colour)
	{
		OnSecondaryTextColourChanged(colour);
	}
}

const NoLifeNoCry::Engine::Graphic::Colour& NoLifeNoCry::Engine::UI::Control::GetHighlightTextColour() const
{
	return highlightTextColour ? *highlightTextColour : (parent ? parent->GetHighlightTextColour() : defaultHighlightTextColour);
}

void NoLifeNoCry::Engine::UI::Control::SetHighlightTextColour(const NoLifeNoCry::Engine::Graphic::Colour& colour)
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetHighlightTextColour());
	if (!highlightTextColour)
	{
		highlightTextColour = new NoLifeNoCry::Engine::Graphic::Colour(colour);
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

void NoLifeNoCry::Engine::UI::Control::ResetHighlightTextColour()
{
	NoLifeNoCry::Engine::Graphic::Colour old_colour(GetHighlightTextColour());
	delete highlightTextColour;
	highlightTextColour = nullptr;
	NoLifeNoCry::Engine::Graphic::Colour colour(GetHighlightTextColour());
	if (old_colour != colour)
	{
		OnHighlightTextColourChanged(colour);
	}
}

bool NoLifeNoCry::Engine::UI::Control::HasParent() const
{
	return parent;
}

NoLifeNoCry::Engine::UI::Control* NoLifeNoCry::Engine::UI::Control::GetParent() const
{
	return parent;
}

std::size_t NoLifeNoCry::Engine::UI::Control::GetChildCount() const
{
	return children.size();
}

NoLifeNoCry::Engine::UI::Control& NoLifeNoCry::Engine::UI::Control::GetChild(std::size_t index)
{
	return *(children[index].get());
}

const NoLifeNoCry::Engine::UI::Control& NoLifeNoCry::Engine::UI::Control::GetChild(std::size_t index) const
{
	return *(children[index].get());
}

bool NoLifeNoCry::Engine::UI::Control::IsMouseOnWindow() const
{
	return parent ? parent->IsMouseOnWindow() : false;
}

bool NoLifeNoCry::Engine::UI::Control::IsWindowFocused() const
{
	return parent ? parent->IsWindowFocused() : false;
}

glm::ivec2 NoLifeNoCry::Engine::UI::Control::GetMousePosition() const
{
	return parent ? parent->GetMousePosition() : glm::ivec2(0, 0);
}

void NoLifeNoCry::Engine::UI::Control::Draw(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget) const
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

bool NoLifeNoCry::Engine::UI::Control::ProcessTextEntered(const NoLifeNoCry::Engine::Input::Data::TextData& textData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessKeyPressed(const NoLifeNoCry::Engine::Input::Data::KeyboardKeyData& keyboardKeyData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessKeyReleased(const NoLifeNoCry::Engine::Input::Data::KeyboardKeyData& keyboardKeyData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessMouseWheelScrolled(const NoLifeNoCry::Engine::Input::Data::MouseWheelData& mouseWheelData)
{
	bool ret(false);
	NoLifeNoCry::Engine::Input::Data::MouseWheelData local_mouse_wheel_data({ mouseWheelData.wheel, mouseWheelData.delta, mouseWheelData.position - position });
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

bool NoLifeNoCry::Engine::UI::Control::ProcessMouseButtonPressed(const NoLifeNoCry::Engine::Input::Data::MouseButtonData& mouseButtonData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessMouseButtonReleased(const NoLifeNoCry::Engine::Input::Data::MouseButtonData& mouseButtonData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessMouseMoved(const NoLifeNoCry::Engine::Input::Data::MouseMovementData& mouseMovementData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessWindowMouseEntered()
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

bool NoLifeNoCry::Engine::UI::Control::ProcessWindowMouseLeft()
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

bool NoLifeNoCry::Engine::UI::Control::ProcessJoystickButtonPressed(const NoLifeNoCry::Engine::Input::Data::JoystickButtonData& joystickButtonData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessJoystickButtonReleased(const NoLifeNoCry::Engine::Input::Data::JoystickButtonData& joystickButtonData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessJoystickMoved(const NoLifeNoCry::Engine::Input::Data::JoystickMovementData& joystickMovementData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessJoystickConnected(const NoLifeNoCry::Engine::Input::Data::JoystickConnectionData& joystickConnectionData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessJoystickDisconnected(const NoLifeNoCry::Engine::Input::Data::JoystickConnectionData& joystickConnectionData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessTouchBegan(const NoLifeNoCry::Engine::Input::Data::TouchData& touchData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessTouchMoved(const NoLifeNoCry::Engine::Input::Data::TouchData& touchData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessTouchEnded(const NoLifeNoCry::Engine::Input::Data::TouchData& touchData)
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

bool NoLifeNoCry::Engine::UI::Control::ProcessSensorChanged(const NoLifeNoCry::Engine::Input::Data::SensorData& sensorData)
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

void NoLifeNoCry::Engine::UI::Control::PushDrawingState(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget)
{
	originalView = renderTarget.getView();
	sf::View view(originalView);
	glm::vec2 move_position(-GetLocalPosition());
	view.rotate(-rotation);
	view.move({ move_position.x, move_position.y });
	renderTarget.setView(view);
}

void NoLifeNoCry::Engine::UI::Control::PopDrawingState(NoLifeNoCry::Engine::Graphic::RenderTarget& renderTarget)
{
	renderTarget.setView(originalView);
}
