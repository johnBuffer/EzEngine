#include "engine.hpp"


namespace ez
{

Engine Engine::s_instance;


void Engine::initialize()
{
	s_instance = Engine();
}

fva::Handle<Entity*> Engine::addEntity(Entity* new_entity)
{
	return s_instance.m_entities.add(new_entity);
}

void Engine::removeEntity(fva::Handle<Entity*> entity)
{
	s_instance.m_entities.remove(entity);
}

void Engine::removeDrawable(fva::Handle<Drawable*> drawable)
{
	s_instance.m_drawables.remove(drawable);
}

void Engine::removeUpdatable(fva::Handle<Updatable*> updatable)
{
	s_instance.m_updatables.remove(updatable);
}

}
