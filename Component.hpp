#pragma once

#include "FastVersatileArray.hpp"

template<typename T>
class Component
{
public:
	uint32_t entityID() const
	{
		return _entity_id;
	}

	static void init(uint64_t signature)
	{
		T::_signature = signature;
	}

	static uint64_t signature()
	{
		return _signature;
	}

	template<typename... Args>
	static fva::Handle<T> add(Args&&... args)
	{
		return _data.add(args);
	}

protected:
	Component() :
		_id(0),
		_entity_id(0)
	{}

	Component(uint32_t id, uint32_t entity_id) :
		_id(id),
		_entity_id(id)
	{}

	friend T;

	uint32_t _id;
	uint32_t _entity_id;

	static uint64_t _signature;
	static fva::SwapArray<T> _data;
};

template<typename T> 
uint64_t Component<T>::_signature;