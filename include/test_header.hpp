#pragma once

#include <vector>
#include <functional>

template<typename T>
using Getter = T*(*)(uint64_t);


template<typename T>
struct ACObject
{
	static T* getAt(uint64_t index)
	{
		return &objects[index];
	}

	static std::vector<T> objects;
};

template<typename T>
std::vector<T> ACObject<T>::objects;


template<typename T>
struct ObjectPtr
{
	ObjectPtr() = default;
	
	ObjectPtr(const uint64_t idx)
		: getter(&T::getAt)
		, index(idx)
	{
	}

	ObjectPtr(Getter<T> get, const uint64_t idx)
		: getter(get)
		, index(idx)
	{}

	T* getObject()
	{
		return getter(index);
	}

	T* operator->()
	{
		return getObject();
	}

	template<typename U>
	operator ObjectPtr<U>()
	{
		ObjectPtr<U> res([](uint64_t idx) { return dynamic_cast<U*>(T::getAt(idx)); }, index);
		return res;
	}

	const Getter<T> getter;
	const uint64_t index;
};
