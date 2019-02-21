#pragma once

#include "System.hpp"
#include <map>



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

private:
	fva::FastArray<System> _systems;

	std::map<uint32_t, int> _components;
};