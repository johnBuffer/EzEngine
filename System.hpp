#pragma once

#include "FastVersatileArray.hpp"
#include "Component.hpp"

class System
{
public:
	System();

	virtual void update(float dt);
	virtual void init();
	
protected:
	uint32_t _signature;

};