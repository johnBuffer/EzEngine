#pragma once
#include "FastVersatileArray.hpp"

class Entity
{
public:
	Entity() = default;

	explicit Entity(uint32_t id) :
		_id(id)
	{}

	template<typename T, typename... Args>
	void addComponents(Args&&...)
	{

	}

private:

	uint32_t _id;
	uint64_t _signature;
	fva::SwapArray<uint32_t> _components;

};