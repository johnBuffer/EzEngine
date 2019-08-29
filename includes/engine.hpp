#pragma once

#include <fast_array.hpp>
#include "entity.hpp"


namespace ez
{
class Engine
{
public:
	static void initialize();

	static fva::Handle<Entity*> addEntity(Entity* new_entity);
	static void removeEntity(fva::Handle<Entity*> entity);

	template<class T>
	static void registerSystem();

private:
	fva::SwapArray<Entity*> m_entities;
	fva::SwapArray<

	Engine() = default;
	static Engine s_instance;
};
}
