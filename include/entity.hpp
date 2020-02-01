#pragma once

#include <fast_array.hpp>
#include <array>
#include "component.hpp"
#include "parameters.hpp"


namespace ez
{
class Entity
{
public:
	using ptr = fva::Handle<Entity>;

	Entity()
	{
		for (fva::ID& id : components) {
			id = 0UL;
		}
	}

	template<typename T>
	T& get();

	template<typename T, typename... Args>
	void add(Args&&...);

private:
	std::array<fva::ID, MAX_COMPONENTS> components;
};


template<typename T>
inline T& Entity::get()
{
	const fva::ID component_index = components[T::s_id];
	return T::get(component_index);
}

template<typename T, typename... Args>
inline void Entity::add(Args&&... args)
{
	components[T::s_id] = T::add(args...);
}

}
