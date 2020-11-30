#pragma once

#include <String.hpp>

namespace NoLifeNoCry::Engine::Input
{
	class Clipboard
	{
	public:

		static NoLifeNoCry::Engine::String GetString();

		static void SetString(const NoLifeNoCry::Engine::String& string);
	};
}
