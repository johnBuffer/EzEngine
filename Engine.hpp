#pragma once

#include "System.hpp"
#include "Entity.hpp"

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

	Entity create()
	{
		return Entity(++_entity_counter);
	}

	void addSystem();

	template<typename T>
	void registerComponent()
	{
		T::init(++_component_counter);
	}

private:
	fva::SwapArray<System> _systems;

	uint32_t _entity_counter;
	uint32_t _component_counter;
};