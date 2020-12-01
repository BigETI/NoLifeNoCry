#pragma once

#include <String.hpp>

namespace DirtMachine::Input
{
	class Clipboard
	{
	public:

		static DirtMachine::String GetString();

		static void SetString(const DirtMachine::String& string);
	};
}
