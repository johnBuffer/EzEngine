#pragma once

#include <vector>
#include <functional>


template<typename T>
class Component
{
	const T& get(uint64_t id) const
	{
		return data[id];
	}

	static std::vector<T> data;
};

template<typename T>
std::vector<T> Component<T>::data;


class CustomComp : public Component<CustomComp>
{
	float truc_1;
};

