#pragma once

#include <fast_array.hpp>

class Drawable
{
public:

	Drawable();

	~Drawable();

	virtual void draw() = 0;

private:
	fva::Handle<Drawable*> m_engine_handle;
};
