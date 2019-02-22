#pragma once

#include <vector>

template<typename T> class SwapArray;

template<typename T>
class Handle
{
public:
	Handle() :
		_index(0),
		_source(nullptr)
	{}

	Handle(uint32_t index, SwapArray<T>& source) :
		_index(index),
		_source(&source)
	{}

	T& operator*()
	{
		return (*_source)[_index];
	}

	T* operator->()
	{
		return &(this->operator*());
	}

private:
	uint32_t _index;
	SwapArray<T>* _source;
};

template<typename T>
class SwapArray
{
public:
	SwapArray() = default;

	template<typename... Args>
	Handle<T> add(Args&&... args)
	{
		_data.emplace_back(args);
	}

	void remove(Handle<T>& handle)
	{

	}

private:
	std::vector<T> _data;
};