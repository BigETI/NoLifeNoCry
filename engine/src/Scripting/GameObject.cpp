#include <Scripting/GameObject.hpp>

DirtMachine::Scripting::GameObject::GameObject(DirtMachine::Scripting::Transformation* parent) :
	DirtMachine::Scripting::Transformation(parent)
{
	// ...
}

DirtMachine::Scripting::GameObject::~GameObject()
{
	// ...
}

std::shared_ptr<DirtMachine::Scripting::GameObject> DirtMachine::Scripting::GameObject::AddGameObject()
{
	std::shared_ptr<DirtMachine::Scripting::GameObject> ret(std::make_shared<DirtMachine::Scripting::GameObject>(this));
	behaviours.push_back(ret);
	return ret;
}

void DirtMachine::Scripting::GameObject::Initialise()
{
	DirtMachine::Scripting::Transformation::Initialise();
	for (std::shared_ptr<DirtMachine::Scripting::Behaviour> behaviour : behaviours)
	{
		behaviour->Initialise();
	}
}

void DirtMachine::Scripting::GameObject::Destroy()
{
	DirtMachine::Scripting::Transformation::Destroy();
	for (std::shared_ptr<DirtMachine::Scripting::Behaviour> behaviour : behaviours)
	{
		behaviour->Destroy();
	}
}

void DirtMachine::Scripting::GameObject::Enable()
{
	DirtMachine::Scripting::Transformation::Enable();
	for (std::shared_ptr<Behaviour> behaviour : behaviours)
	{
		behaviour->Enable();
	}
}

void DirtMachine::Scripting::GameObject::Disable()
{
	DirtMachine::Scripting::Transformation::Disable();
	for (std::shared_ptr<DirtMachine::Scripting::Behaviour> behaviour : behaviours)
	{
		behaviour->Disable();
	}
}

void DirtMachine::Scripting::GameObject::Tick(float deltaTime)
{
	DirtMachine::Scripting::Transformation::Tick(deltaTime);
	std::vector<std::shared_ptr<DirtMachine::Scripting::Behaviour>> remove_behaviours;
	for (std::shared_ptr<DirtMachine::Scripting::Behaviour> behaviour : behaviours)
	{
		if (behaviour->IsMarkedForRemoval())
		{
			remove_behaviours.push_back(behaviour);
		}
		else
		{
			behaviour->Tick(deltaTime);
		}
	}
	for (const std::shared_ptr<DirtMachine::Scripting::Behaviour>& remove_behaviour : remove_behaviours)
	{
		behaviours.remove(remove_behaviour);
	}
	remove_behaviours.clear();
}

void DirtMachine::Scripting::GameObject::Render(const glm::mat4x4& parentTransformationMatrix, DirtMachine::Graphic::Renderer& renderer)
{
	glm::mat4x4 new_transformation(parentTransformationMatrix * GetLocalTransformation());
	DirtMachine::Scripting::Transformation::Render(parentTransformationMatrix, renderer);
	for (std::shared_ptr<DirtMachine::Scripting::Behaviour> behaviour : behaviours)
	{
		behaviour->Render(new_transformation, renderer);
	}
}
