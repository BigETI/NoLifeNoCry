#pragma once

#include <glm/mat4x4.hpp>
#include <Graphic/Renderer.hpp>

namespace DirtMachine::Scripting
{
	class Behaviour
	{
	public:

		Behaviour() = delete;
		Behaviour(const DirtMachine::Scripting::Behaviour&) = delete;
		Behaviour(DirtMachine::Scripting::Behaviour&&) = delete;

		Behaviour(bool isRemovable);

		virtual ~Behaviour();

		virtual void Initialise();

		virtual void Destroy();

		virtual void Enable();

		virtual void Disable();

		virtual void Tick(float deltaTime);

		virtual void Render(const glm::mat4x4& parentTransformationMatrix, DirtMachine::Graphic::Renderer& renderer);

		virtual bool IsInitialised() const;

		virtual bool IsMarkedForRemoval() const;

		virtual bool IsEnabled() const;

		DirtMachine::Scripting::Behaviour& operator = (const DirtMachine::Scripting::Behaviour&) = delete;
		DirtMachine::Scripting::Behaviour& operator = (DirtMachine::Scripting::Behaviour&&) = delete;

	private:

		bool isRemovable;

		bool isInitialised;

		bool isMarkedForRemoval;

		bool isEnabled;
	};
}
