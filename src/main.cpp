#include <iostream>
#include "filter.hpp"
#include "component.hpp"
#include "engine.hpp"
#include "entity.hpp"


struct C1 : public ComponentBack<C1>
{
	C1()
		: a(0.0f)
	{}

	C1(const float f)
		: a(f)
	{}

	const float a;
};


struct C2 : public ComponentBack<C2>
{
};


int main()
{	
	ez::Engine::initialize();
	C1::initialize();
	C2::initialize();

	std::cout << C1::s_id << std::endl;
	std::cout << C2::s_id << std::endl;

	ez::Entity entity;
	entity.add<C1>(3.14159f);

	std::cout << entity.get<C1>().a << std::endl;

	return 0;
}