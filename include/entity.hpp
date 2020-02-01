#pragma once

#include <fast_array.hpp>
#include <array>
#include "parameters.hpp"


namespace ez
{
class Entity
{
public:
	friend class Engine;
	using ptr = fva::Handle<Entity>;

	Entity()
		: id(0U)
	{
		for (fva::ID& id : components) {
			id = 0UL;
		}
	}

	fva::ID getID() const
	{
		return id;
	}

	fva::ID getKey() const
	{
		return key;
	}

	template<typename T>
	T& get() const;

	template<typename T, typename... Args>
	void add(Args&&...);

private:
	fva::ID id;
	fva::ID key;
	std::array<fva::ID, MAX_COMPONENTS> components;
};


template<typename T>
inline T& Entity::get() const
{
	const fva::ID component_index = components[T::getID()];
	return T::get(component_index);
}

template<typename T, typename... Args>
inline void Entity::add(Args&&... args)
{
	components[T::getID()] = T::add(args...);
	key |= T::getKey();
}

}
