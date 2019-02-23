#pragma once
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
	Velocity(uint32_t entity_id, float x_, float y_) :
		Component(entity_id),
		vx(x_),
		vy(y_)
	{}

	float vx, vy;
};
