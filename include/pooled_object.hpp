#pragma once

#include <fast_array.hpp>
#include <memory>


template<typename T>
struct PooledObject
{
	using ptr = fva::Handle<T>;
	template<typename... Args>

	static ptr create(Args&&... args);
	static void remove(const T& obj);
	static fva::Container<T> pool;
};


template<typename T>
fva::Container<T> PooledObject<T>::pool;

template<typename T>
template<typename ...Args>
inline fva::Handle<T> PooledObject<T>::create(Args&& ...args)
{
	return pool.add(args...);
}

template<typename T>
inline void PooledObject<T>::remove(const T& obj_to_remove)
{
	const uint64_t pool_size = pool.size();
	for (uint64_t i(0U); i < pool_size; ++i) {
		ptr& obj = pool[i];
		if (&(*obj) == &obj_to_remove) {
			std::swap(obj, pool.back());
			pool.pop_back();
			break;
		}
	}
}
