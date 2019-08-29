#pragma once

#include <stdint.h>

namespace ez
{

template<class T>
class System
{
public:
	System() = default;

	static const uint32_t get_id();

private:
	static void register_system();
	
	static T        s_instance;
	static uint32_t s_id;
};

template<class T>
inline const uint32_t System<T>::get_id()
{
	return s_id;
}

template<class T>
inline void System<T>::register_system()
{
	T::initialize();
	s_instance = T();
}

}
