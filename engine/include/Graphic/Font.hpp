#pragma once

#include <SFML/Graphics/Font.hpp>

namespace NoLifeNoCry::Engine::Graphic
{
	/*class Font : public sf::Font
	{
	public:
		Font() : sf::Font()
		{
			std::cout << "Pajeet \"" << getInfo().family << "\" is create! " << this << std::endl;
		}

		Font(const sf::Font& copy) : sf::Font(copy)
		{
			std::cout << "Pajeet \"" << getInfo().family << "\" is copy! " << this << std::endl;
		}

		virtual ~Font()
		{
			std::cout << "Pajeet \"" << getInfo().family << "\" is kill! " << this << std::endl;
		}
	};*/

	using Font = sf::Font;
}
