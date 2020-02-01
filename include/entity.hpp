#pragma once

#include <fast_array.hpp>
#include <array>
#include "component.hpp"


namespace ez
{
class Entity
{
public:
	using ptr = fva::Handle<Entity>;

	Entity();

private:
	std::array<fva::Container::ID, 64U> components;
};
}
