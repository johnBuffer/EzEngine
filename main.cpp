#include <iostream>
#include "Engine.hpp"

int main()
{
	Engine engine;

	while (true)
	{
		engine.update(0.016);
	}

	return 0;
}