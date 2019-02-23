#pragma once

#include "FastVersatileArray.hpp"
#include "Component.hpp"

class System
{
public:
	System(uint64_t signature) :
		_signature(signature)
	{}

	virtual void update(float dt) = 0;
	virtual void init();

	
protected:
	uint64_t _signature;

};