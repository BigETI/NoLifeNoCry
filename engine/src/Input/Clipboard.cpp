#include <SFML/Window/Clipboard.hpp>
#include <Input/Clipboard.hpp>

NoLifeNoCry::Engine::String NoLifeNoCry::Engine::Input::Clipboard::GetString()
{
	return sf::Clipboard::getString();
}

void NoLifeNoCry::Engine::Input::Clipboard::SetString(const NoLifeNoCry::Engine::String& string)
{
	sf::Clipboard::setString(string);
}
