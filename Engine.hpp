#pragma once

#include "System.hpp"

class Engine
{
public:
	Engine();

	void update(float dt);

	void addSystem(System* s);

private:
	std::vector<System> m_systems;
};