#pragma once

#include <Scripting/GameObject.hpp>

namespace DirtMachine::Scripting
{
	class Scene : public DirtMachine::Scripting::GameObject
	{
	public:

		Scene();

		Scene(const DirtMachine::Scripting::Scene&) = delete;
		Scene(DirtMachine::Scripting::Scene&&) = delete;

		virtual ~Scene();

		DirtMachine::Scripting::Scene& operator = (const DirtMachine::Scripting::Scene&) = delete;
		DirtMachine::Scripting::Scene& operator = (DirtMachine::Scripting::Scene&&) = delete;
	};
}
