#pragma once

#include <fast_array.hpp>


namespace ez
{

class Updatable
{
public:
	Updatable();
	virtual ~Updatable();

	virtual void update(float dt) = 0;

	void setEngineHandle(fva::Handle<Updatable*> handle);

private:
	fva::Handle<Updatable*> m_engine_handle;
};

}
