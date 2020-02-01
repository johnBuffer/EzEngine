#include <engine.hpp>


namespace ez
{

Engine Engine::s_instance;


Engine::Engine()
	: component_count(0U)
{
	
}

void Engine::initialize()
{
	s_instance = Engine();
}

Engine& Engine::get()
{
	return s_instance;
}

fva::ID Engine::getComponentID()
{
	return component_count++;
}

}
