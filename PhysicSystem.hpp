#pragma once

#include "System.hpp"
#include "entity_manager.hpp"
#include "physics_components.hpp"

class PhysicSystem : public System
{
public:
	PhysicSystem(uint64_t signature) :
		System(signature)
	{}

	void init()
	{
		std::cout << "Physic system initialized" << std::endl;
	}

	void update(float dt)
	{
		std::list<EntityHandle> entities = ez::EntityManager::get<Position, Velocity>();
		std::cout << "PhysicSystem updated " << entities.size() << " entities" << std::endl;
		
	}
};