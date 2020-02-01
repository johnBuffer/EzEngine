#pragma once

#include <fast_array.hpp>
#include "entity.hpp"
#include "system.hpp"


namespace ez
{
class Engine
{
public:
	static void initialize();
	static Engine& get();

	fva::ID getComponentID();

private:
	//fva::Container<Entity> m_entities;
	std::vector<SystemInterface> m_systems;

	uint64_t component_count;
	
	Engine();
	static Engine s_instance;
};
}
