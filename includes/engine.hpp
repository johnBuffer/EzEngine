#pragma once

#include <fast_array.hpp>
#include "entity.hpp"
#include "system_interface.hpp"


namespace ez
{
class Engine
{
public:
	static void initialize();

private:
	fva::SwapArray<Entity> m_entities;
	std::vector<SystemInterface*> m_systems;
	
	Engine() = default;
	static Engine s_instance;
};
}
