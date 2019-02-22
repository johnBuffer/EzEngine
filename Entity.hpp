#pragma once
#include "FastVersatileArray.hpp"

class Entity
{
public:
	Entity() = default;

	template<typename T, typename... Args>
	void addComponents(Args&&...)
	{

	}

private:

	uint32_t _id;
	uint64_t _signature;
	fva::FastArray<uint32_t> _components;

};