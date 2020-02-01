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

fva::ID Engine::createEntity()
{
	return m_entities.add().getIndex();
}

fva::ID Engine::addEntity(const Entity& entity)
{
	fva::Handle<Entity> handle = m_entities.add(entity);
	const fva::ID id = handle.getIndex();
	Entity& added_entity = *handle;
	added_entity.id = id;

	for (SystemInterface::ptr& system : m_systems) {
		system->add(added_entity);
	}

	return id;
}

Entity& Engine::getEntity(fva::ID id)
{
	return m_entities[id];
}

void Engine::update(float dt)
{
	for (SystemInterface::ptr& system : m_systems) {
		system->execute();
	}
}

}
