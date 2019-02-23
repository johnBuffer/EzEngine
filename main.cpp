#include <iostream>
#include "Engine.hpp"

#include "Helper.hpp"
#include "Component.hpp"
#include <bitset>

struct Position : public Component<Position>
{
	Position(uint32_t entity_id, float x_, float y_) :
		Component(entity_id),
		x(x_),
		y(y_)
	{}

	float x, y;
};

struct Velocity : public Component<Velocity>
{
	Velocity(uint32_t entity_id, float x_, float y_) :
		Component(entity_id),
		vx(x_),
		vy(y_)
	{}

	float vx, vy;
};

int main()
{	
	Engine engine;

	engine.registerComponent<Position>();
	engine.registerComponent<Velocity>();

	std::cout << Velocity::signature() << std::endl;

	EntityHandle e = engine.create();
	e->addComponent<Position>(5, 12);
	e->addComponent<Velocity>(1, 1);

	std::list<EntityHandle> matchingSet = engine.getMatching<Position, Velocity>();

	for (EntityHandle& eh : matchingSet)
	{
		Position* p = eh->getComponent<Position>();
		if (p)
		{
			std::cout << p->x << " " << p->y << std::endl;
		}
		else
		{
			std::cout << "Error, cannot find component" << std::endl;
		}
	}

	std::cout << "DONE" << std::endl;

	while (true)
	{
		engine.update(0.016f);
	}

	return 0;
}