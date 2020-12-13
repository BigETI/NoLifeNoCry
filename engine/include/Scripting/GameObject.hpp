#pragma once

#include <list>
#include <memory>
#include <vector>
#include <Scripting/Behaviour.hpp>
#include <Scripting/Transformation.hpp>

namespace DirtMachine::Scripting
{
	class GameObject : public DirtMachine::Scripting::Transformation
	{
	public:

		GameObject() = delete;
		GameObject(const DirtMachine::Scripting::GameObject&) = delete;
		GameObject(DirtMachine::Scripting::GameObject&&) = delete;

		GameObject(DirtMachine::Scripting::Transformation* parent);

		virtual ~GameObject();

		template <typename T>
		std::shared_ptr<T> GetBehaviour() const
		{
			static_assert(std::is_convertible<T*, DirtMachine::Scripting::Behaviour*>::value, "Type must inherit from \"Behaviour\".");
			std::shared_ptr<T> ret(nullptr);
			for (std::shared_ptr<DirtMachine::Behaviour>& behaviour : behaviours)
			{
				if (dynamic_cast<T*>(behaviour.get()))
				{
					ret = behaviour;
					break;
				}
			}
			return ret;
		}

		template <typename T, typename Container = std::vector<std::shared_ptr<T>>>
		Container& GetBehaviours(Container& result) const
		{
			static_assert(std::is_convertible<T*, DirtMachine::Scripting::Behaviour*>::value, "Type must inherit from \"Behaviour\".");
			result.clear();
			for (std::shared_ptr<DirtMachine::Behaviour>& behaviour : behaviours)
			{
				if (dynamic_cast<T*>(behaviour.get()))
				{
					result.push_back(behaviour);
				}
			}
			return ret;
		}

		template <typename T>
		std::shared_ptr<T> AddBehaviour()
		{
			static_assert(std::is_convertible<T*, DirtMachine::Scripting::Behaviour*>::value, "Type must inherit from \"Behaviour\".");
			std::shared_ptr<T> ret(std::make_shared<T>());
			behaviours.push_back(ret);
			return ret;
		}

		std::shared_ptr<DirtMachine::Scripting::GameObject> AddGameObject();

		template <typename T>
		std::shared_ptr<T> RequireBehaviour()
		{
			static_assert(std::is_convertible<T*, DirtMachine::Scripting::Behaviour*>::value, "Type must inherit from \"Behaviour\".");
			std::shared_ptr<T> ret(GetBehaviour<T>());
			return ret ? ret : AddBehaviour<T>();
		}

		template <typename T>
		bool RemoveBehaviour(const std::shared_ptr<T>& behaviour)
		{
			static_assert(std::is_convertible<T*, DirtMachine::Scripting::Behaviour*>::value, "Type must inherit from \"Behaviour\".");
			return behaviours.remove(behaviour) > 0ULL;
		}

		virtual void Initialise() override;

		virtual void Destroy() override;

		virtual void Enable() override;

		virtual void Disable() override;

		virtual void Tick(float deltaTime) override;

		virtual void Render(const glm::mat4x4& parentTransformationMatrix, DirtMachine::Graphic::Renderer& renderer) override;

		DirtMachine::Scripting::GameObject& operator = (const DirtMachine::Scripting::GameObject&) = delete;
		DirtMachine::Scripting::GameObject& operator = (DirtMachine::Scripting::GameObject&&) = delete;

	private:

		std::list<std::shared_ptr<DirtMachine::Scripting::Behaviour>> behaviours;
	};
}
