#include <iostream>
#include "Engine.hpp"

#include "Helper.hpp"
#include "Component.hpp"

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
	float vx, vy;
};

int main()
{	
	Engine engine;

	engine.registerComponent<Position>();
	engine.registerComponent<Velocity>();

	std::cout << Velocity::signature() << std::endl;

	Entity e = engine.create();
	e.addComponent<Position>(5, 12);

	Position* p = e.getComponent<Position>();
	if (p)
	{
		std::cout << p->x << " " << p->y << std::endl;
	}

	while (true)
	{
		engine.update(0.016f);
	}

	return 0;
}