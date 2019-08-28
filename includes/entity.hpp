#pragma once

namespace ez
{
class Entity
{
public:
	Entity();

	virtual void update(float dt) = 0;
	virtual void render() = 0;

private:

};
}
