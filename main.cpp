#include <iostream>
#include "Engine.hpp"

#include "Helper.hpp"
#include "Component.hpp"
#include "container.hpp"

struct LOL : public Component<LOL>
{

};

int main()
{
	LOL lol;
	LOL::init(1001);

	std::cout << lol.signature() << std::endl;
	
	Engine engine;

	while (true)
	{
		engine.update(0.016);
	}

	return 0;
}