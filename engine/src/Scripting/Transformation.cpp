#include <glm/gtx/matrix_decompose.hpp>
#include <Scripting/Transformation.hpp>

DirtMachine::Scripting::Transformation::Transformation(DirtMachine::Scripting::Transformation* parent) :
	DirtMachine::Scripting::Behaviour(false),
	parent(parent),
	transformation()
{
	// ...
}

DirtMachine::Scripting::Transformation::~Transformation()
{
	// ...
}

glm::mat4x4 DirtMachine::Scripting::Transformation::GetLocalTransformation() const
{
	return transformation;
}

void DirtMachine::Scripting::Transformation::SetLocalTransformation(const glm::mat4x4& newLocalTransformation)
{
	transformation = newLocalTransformation;
}

glm::mat4x4 DirtMachine::Scripting::Transformation::GetLocalSpaceToWorldSpaceTransformation() const
{
	return (parent ? parent->GetLocalSpaceToWorldSpaceTransformation() : glm::mat4x4()) * transformation;
}

glm::mat4x4 DirtMachine::Scripting::Transformation::GetWorldSpaceToLocalSpaceTransformation() const
{
	return transformation / (parent ? parent->GetWorldSpaceToLocalSpaceTransformation() : glm::mat4x4());
}

glm::vec3 DirtMachine::Scripting::Transformation::GetLocalPosition() const
{
	glm::vec3 scale;
	glm::quat orientation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, orientation, translation, skew, perspective);
	return translation;
}

void DirtMachine::Scripting::Transformation::SetLocalPosition(const glm::vec3& newLocalPosition)
{
	// TODO
}

glm::vec3 DirtMachine::Scripting::Transformation::GetGlobalPosition() const
{
	// TODO
	return glm::vec3();
}

void DirtMachine::Scripting::Transformation::SetGlobalPosition(const glm::vec3& newGlobalPosition)
{
	// TODO
}

glm::quat DirtMachine::Scripting::Transformation::GetLocalRotation() const
{
	glm::vec3 scale;
	glm::quat orientation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(transformation, scale, orientation, translation, skew, perspective);
	return orientation;
}

void DirtMachine::Scripting::Transformation::SetLocalRotation(const glm::quat& newLocalRotation)
{
	// TODO
}

glm::quat DirtMachine::Scripting::Transformation::GetGlobalRotation() const
{
	// TODO
	return glm::quat();
}

void DirtMachine::Scripting::Transformation::SetGlobalRotation(const glm::quat& newGlobalRotation)
{
	// TODO
}

DirtMachine::Scripting::Transformation* DirtMachine::Scripting::Transformation::GetParent() const
{
	return parent;
}
