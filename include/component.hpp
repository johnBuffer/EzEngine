#pragma once

#include <fast_array.hpp>
#include <pooled_object.hpp>
#include <engine.hpp>


template<typename T>
struct ComponentBack : public PooledObject<T>
{
	static fva::ID s_id;

	static void initialize();

	static T& get(fva::ID id);

	template<typename... Args>
	static fva::ID add(Args&&...);
};

template<typename T>
fva::ID ComponentBack<T>::s_id;

template<typename T>
inline void ComponentBack<T>::initialize()
{
	s_id = ez::Engine::get().getComponentID();
}

template<typename T>
inline T& ComponentBack<T>::get(fva::ID id)
{
	return pool[id];
}

template<typename T>
template<typename... Args>
inline fva::ID ComponentBack<T>::add(Args&&... args)
{
	return pool.add(args...).getIndex();
}
