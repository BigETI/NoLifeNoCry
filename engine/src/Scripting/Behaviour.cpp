#include <Scripting/Behaviour.hpp>

DirtMachine::Scripting::Behaviour::Behaviour(bool isRemovable) :
	isRemovable(isRemovable),
	isInitialised(false),
	isMarkedForRemoval(false),
	isEnabled(false)
{
	// ...
}

DirtMachine::Scripting::Behaviour::~Behaviour()
{
	if (isEnabled)
	{
		Disable();
	}
}

void DirtMachine::Scripting::Behaviour::Initialise()
{
	isInitialised = true;
}

void DirtMachine::Scripting::Behaviour::Destroy()
{
	if (isRemovable)
	{
		isMarkedForRemoval = true;
		if (isEnabled)
		{
			Disable();
		}
	}
}

void DirtMachine::Scripting::Behaviour::Enable()
{
	isEnabled = true;
}

void DirtMachine::Scripting::Behaviour::Disable()
{
	isEnabled = false;
}

void DirtMachine::Scripting::Behaviour::Tick(float deltaTime)
{
	// ...
}

void DirtMachine::Scripting::Behaviour::Render(const glm::mat4x4& parentTransformationMatrix, DirtMachine::Graphic::Renderer& renderer)
{
	// ...
}

bool DirtMachine::Scripting::Behaviour::IsInitialised() const
{
	return isInitialised;
}

bool DirtMachine::Scripting::Behaviour::IsMarkedForRemoval() const
{
	return isMarkedForRemoval;
}

bool DirtMachine::Scripting::Behaviour::IsEnabled() const
{
	return isEnabled;
}
