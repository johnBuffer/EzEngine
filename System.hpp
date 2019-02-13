#pragma once

#include <vector>
#include "Component.hpp"

class System
{
public:
	System();

	virtual void update(float dt);
	
protected:
	std::vector<Component> m_components;
};