#pragma once

#include <fast_array.hpp>
#include <unordered_map>
#include "entity.hpp"
#include "system.hpp"
#include "entity.hpp"


namespace ez
{
class Engine
{
public:
	static void initialize();
	static Engine& get();

	void update(float dt = 0.016f);

private:

	Engine();
	static Engine s_instance;
};

}
