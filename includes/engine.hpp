#pragma once

#include <fast_array.hpp>
#include "entity.hpp"
#include "drawable.hpp"
#include "updatable.hpp"


namespace ez
{
class Engine
{
public:
	static void initialize();
	static fva::Handle<Entity*> addEntity(Entity* new_entity);
	static void removeEntity(fva::Handle<Entity*> entity);

	static void removeDrawable(fva::Handle<Drawable*> drawable);
	static void removeUpdatable(fva::Handle<Updatable*> updatable);

private:
	fva::SwapArray<Entity*> m_entities;
	fva::SwapArray<Drawable*> m_drawables;
	fva::SwapArray<Updatable*> m_updatables;

	Engine() = default;
	static Engine s_instance;
};
}
