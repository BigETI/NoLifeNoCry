#pragma once

#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <Scripting/Behaviour.hpp>

namespace DirtMachine::Scripting
{
	class Transformation : public DirtMachine::Scripting::Behaviour
	{
	public:

		Transformation() = delete;
		Transformation(const DirtMachine::Scripting::Transformation&) = delete;
		Transformation(DirtMachine::Scripting::Transformation&&) = delete;

		Transformation(DirtMachine::Scripting::Transformation* parent);

		virtual ~Transformation();

		virtual glm::mat4x4 GetLocalTransformation() const;

		virtual void SetLocalTransformation(const glm::mat4x4& newLocalTransformation);

		virtual glm::mat4x4 GetLocalSpaceToWorldSpaceTransformation() const;

		virtual glm::mat4x4 GetWorldSpaceToLocalSpaceTransformation() const;

		virtual glm::vec3 GetLocalPosition() const;

		virtual void SetLocalPosition(const glm::vec3& newLocalPosition);

		virtual glm::vec3 GetGlobalPosition() const;

		virtual void SetGlobalPosition(const glm::vec3& newGlobalPosition);

		virtual glm::quat GetLocalRotation() const;

		virtual void SetLocalRotation(const glm::quat& newLocalRotation);

		virtual glm::quat GetGlobalRotation() const;

		virtual void SetGlobalRotation(const glm::quat& newGlobalRotation);

		virtual DirtMachine::Scripting::Transformation* GetParent() const;

		DirtMachine::Scripting::Transformation& operator = (const DirtMachine::Scripting::Transformation&) = delete;
		DirtMachine::Scripting::Transformation& operator = (DirtMachine::Scripting::Transformation&&) = delete;

	private:

		DirtMachine::Scripting::Transformation* parent;

		glm::mat4x4 transformation;
	};
}
