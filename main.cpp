#include <iostream>
#include "Engine.hpp"

#include "entity_manager.hpp"
#include "Component.hpp"
#include <bitset>
#include "PhysicSystem.hpp"
#include "physics_components.hpp"

int main()
{	
	Engine engine;
	engine.addSystem<PhysicSystem, Position, Velocity>();

	engine.registerComponent<Position>();
	engine.registerComponent<Velocity>();

	EntityHandle e = ez::EntityManager::create();
	e->addComponent<Position>(5, 12);
	e->addComponent<Velocity>(1, 1);


	while (true)
	{
		engine.update(0.016f);
	}

	return 0;
}