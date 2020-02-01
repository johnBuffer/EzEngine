#pragma once

#include <fast_array.hpp>
#include <unordered_map>
#include "entity.hpp"
#include "system.hpp"
#include "entity.hpp"


namespace ez
{
class Engine
{
public:
	static void initialize();
	static Engine& get();

	template<typename T, typename... Args>
	void registerSystem(Args&&... args);

	fva::ID createEntity();
	fva::ID addEntity(const Entity& entity);
	fva::ID getComponentID();

	Entity& getEntity(fva::ID id);

	void update(float dt = 0.016f);

private:
	fva::Container<Entity> m_entities;
	std::vector<SystemInterface::ptr> m_systems;
	std::unordered_map<fva::ID, std::vector<fva::ID>> m_systems_entities;
	uint64_t component_count;

	Engine();
	static Engine s_instance;
};

template<typename T, typename... Args>
inline void Engine::registerSystem(Args&&... args)
{
	m_systems.push_back(std::make_unique<T>(args...));
}

}
