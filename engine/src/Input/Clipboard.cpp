#include <SFML/Window/Clipboard.hpp>
#include <Input/Clipboard.hpp>

DirtMachine::String DirtMachine::Input::Clipboard::GetString()
{
	return sf::Clipboard::getString();
}

void DirtMachine::Input::Clipboard::SetString(const DirtMachine::String& string)
{
	sf::Clipboard::setString(string);
}
