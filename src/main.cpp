#include <iostream>
#include "test_header.hpp"


struct GenObj
{
	float ok;
};


struct TestObj : public ACObject<TestObj>, GenObj
{
	float lol;
};


int main()
{
	TestObj::objects.resize(5);
	TestObj::objects[0].ok = 8.0f;
	TestObj::objects[0].lol = 4.0f;

	ObjectPtr<TestObj> test_ptr(0);

	std::cout << test_ptr->ok << std::endl;
	std::cout << test_ptr->lol << std::endl;

	ObjectPtr<GenObj> gen_ptr = test_ptr;

	std::cout << gen_ptr->ok << std::endl;

	return 0;
}