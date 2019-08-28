#include "updatable.hpp"

#include "engine.hpp"

namespace ez
{

Updatable::Updatable()
{
	Engine::addUpdatable(this);
}

Updatable::~Updatable()
{
	
}

void Updatable::setEngineHandle(fva::Handle<Updatable*> handle)
{
}

}
