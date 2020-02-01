#include <iostream>
#include "filter.hpp"
#include "component.hpp"
#include "engine.hpp"
#include "entity.hpp"
#include "system.hpp"


struct C1 : public Component<C1>
{
	C1()
		: a(0.0f)
	{}

	C1(const float f)
		: a(f)
	{}

	const float a;
};


struct C2 : public Component<C2>
{
	C2()
		: a(0.0f)
	{}

	C2(const float f)
		: a(f)
	{}

	const float a;
};


struct MySystem : public ez::System<C1, C2>
{
	void execute() override
	{
		for (fva::ID id : entities) {
			const ez::Entity& entity = ez::Engine::get().getEntity(id);
			const float sum = entity.get<C1>().a + entity.get<C2>().a;
			std::cout << "Working on " << id << " sum: " << sum << std::endl;
		}
	}
};


int main()
{	
	ez::Engine::initialize();
	C1::initialize();
	C2::initialize();

	ez::Engine& engine = ez::Engine::get();
	engine.registerSystem<MySystem>();
	
	ez::Entity entity;
	entity.add<C1>(3.14159f);
	entity.add<C2>(2.0f);
	engine.addEntity(entity);

	engine.update();

	return 0;
}