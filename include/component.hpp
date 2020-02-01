#pragma once

#include <fast_array.hpp>
#include <pooled_object.hpp>
#include <engine.hpp>


template<typename T>
struct Component : public PooledObject<T>
{
	static void initialize();
	static fva::ID getID();
	static fva::ID getKey();
	static T& get(fva::ID id);

	template<typename... Args>
	static fva::ID add(Args&&...);

private:
	static fva::ID s_id;
	static fva::ID s_key;
};

template<typename T> fva::ID Component<T>::s_id;
template<typename T> fva::ID Component<T>::s_key;

template<typename T>
inline void Component<T>::initialize()
{
	s_id  = ez::Engine::get().getComponentID();
	s_key = fva::ID(1UL) << s_id;
}

template<typename T>
inline fva::ID Component<T>::getID()
{
	return s_id;
}

template<typename T>
inline fva::ID Component<T>::getKey()
{
	return s_key;
}

template<typename T>
inline T& Component<T>::get(fva::ID id)
{
	return pool[id];
}

template<typename T>
template<typename... Args>
inline fva::ID Component<T>::add(Args&&... args)
{
	return pool.add(args...).getIndex();
}
