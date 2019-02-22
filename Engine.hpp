#pragma once

#include "System.hpp"
#include "Entity.hpp"



class Engine
{
public:
	Engine() = default;

	void update(float dt)
	{
		for (System& system : _systems)
		{
			system.update(dt);
		}
	}

	template<typename... Args>
	void foreach()
	{

	}

	Entity create()
	{
		return Entity(++_counter);
	}

private:
	fva::SwapArray<System> _systems;

	uint32_t _counter;
};