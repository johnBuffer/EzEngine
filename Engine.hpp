#pragma once

#include "System.hpp"
#include "Entity.hpp"
#include "Helper.hpp"
#include <list>

class Engine
{
public:
	Engine() :
		_entity_counter(0),
		_component_counter(0)
	{}

	void update(float dt)
	{
		for (System& system : _systems)
		{
			system.update(dt);
		}
	}

	EntityHandle create()
	{
		uint32_t index = _entities.add(_entity_counter++);
		return EntityHandle(&_entities, index);
	}

	void addSystem();

	template<typename T>
	void registerComponent()
	{
		T::init(_component_counter++);
	}

	template<typename... Args>
	std::list<EntityHandle> getMatching()
	{
		const uint64_t signature = EntitySet<Args...>::getSignature();
		std::list<EntityHandle> result_set;

		for (const Entity& entity : _entities)
		{
			std::cout << "LOL" << std::endl;
			if (entity.getSignature() == signature)
			{
				result_set.emplace_back(&_entities, entity);
			}
		}

		return result_set;
	}

private:
	uint32_t _entity_counter;
	uint32_t _component_counter;

	fva::SwapArray<System> _systems;
	fva::SwapArray<Entity> _entities;
};

