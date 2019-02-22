#pragma once

class BaseComponent
{
public:
	BaseComponent() = default;
	BaseComponent(uint32_t entity_id) :
		_entity_id(entity_id)
	{}

protected:
	uint32_t _entity_id;
};