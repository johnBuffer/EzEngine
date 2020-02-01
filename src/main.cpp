#include <iostream>
#include "filter.hpp"


struct C1
{
	static const uint64_t id = 1U;
};

struct C2
{
	static const uint64_t id = 2U;
};


int main()
{	
	std::cout << Filter<C1, C2>().getFilter() << std::endl;
	

	return 0;
}