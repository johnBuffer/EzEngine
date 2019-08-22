#pragma once


class Updatable
{
public:
	Updatable();

	virtual void update(float dt) = 0;
};
