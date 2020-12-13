#include <glm/mat4x4.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <Graphic/Transform.hpp>
#include <Scripting/SpriteRenderer.hpp>

DirtMachine::Scripting::SpriteRenderer::SpriteRenderer(std::size_t layer, int priority, const DirtMachine::Graphic::Sprite* sprite) :
	DirtMachine::Scripting::Behaviour(true),
	layer(layer),
	priority(priority),
	renderStates(DirtMachine::Graphic::RenderStates::Default),
	sprite(sprite)
{
	// ...
}

DirtMachine::Scripting::SpriteRenderer::~SpriteRenderer()
{
	SetSprite(nullptr);
}

std::size_t DirtMachine::Scripting::SpriteRenderer::GetLayer() const
{
	return layer;
}

void DirtMachine::Scripting::SpriteRenderer::SetLayer(std::size_t newLayer)
{
	layer = newLayer;
}

int DirtMachine::Scripting::SpriteRenderer::GetPriority() const
{
	return priority;
}

void DirtMachine::Scripting::SpriteRenderer::SetPriority(int newPriority)
{
	priority = newPriority;
}

const DirtMachine::Graphic::Sprite* DirtMachine::Scripting::SpriteRenderer::GetSprite() const
{
	return sprite;
}

void DirtMachine::Scripting::SpriteRenderer::SetSprite(const DirtMachine::Graphic::Sprite* newSprite)
{
	sprite = newSprite;
}

void DirtMachine::Scripting::SpriteRenderer::Render(const glm::mat4x4& parentTransformationMatrix, DirtMachine::Graphic::Renderer& renderer)
{
	glm::vec3 scale;
	glm::quat orientation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(parentTransformationMatrix, scale, orientation, translation, skew, perspective);
	renderStates.transform = DirtMachine::Graphic::Transform::Identity;
	renderStates.transform.scale(scale.x, scale.y);
	renderStates.transform.rotate(glm::eulerAngles(orientation).z);
	renderStates.transform.transformPoint(translation.x, translation.y);
	renderer.Enqueue(reinterpret_cast<const DirtMachine::Graphic::Drawable*>(sprite), layer, priority, renderStates);
	DirtMachine::Scripting::Behaviour::Render(parentTransformationMatrix, renderer);
}
