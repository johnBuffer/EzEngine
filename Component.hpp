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
	static fva::FastArray<T> _data;
};