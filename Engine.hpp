#pragma once

#include "System.hpp"
#include "Entity.hpp"
#include "Helper.hpp"
#include <list>

class Engine
{
public:
	Engine() :
		_component_counter(0)
	{}

	void update(float dt)
	{
		for (System* system : _systems)
		{
			system->update(dt);
		}
	}

	template<typename T, typename... Components>
	void addSystem()
	{
		const uint64_t signature = ComponentSet<Components...>::getSignature();
		T* new_system = new T(signature);
		new_system->init();
		_systems.add(new_system);
	}

	template<typename T>
	void registerComponent()
	{
		T::init(_component_counter++);
	}

private:
	uint32_t _component_counter;

	fva::SwapArray<System*> _systems;
};

