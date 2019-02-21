#include <iostream>
#include "Engine.hpp"

#include "Helper.hpp"

int main()
{
	const char* pc;
	//char* const pcc;

	char lol[] = "lololololol";

	pc = lol;
	
	Engine engine;

	while (true)
	{
		engine.update(0.016);
	}

	return 0;
}