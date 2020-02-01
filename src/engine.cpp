#include <engine.hpp>


namespace ez
{

Engine Engine::s_instance;


void Engine::initialize()
{
	s_instance = Engine();
}

}
