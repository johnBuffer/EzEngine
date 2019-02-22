#pragma once

#include "BaseComponent.hpp"
#include "FastVersatileArray.hpp"

template<typename T>
class Component : public BaseComponent
{
public:
	uint32_t entityID() const
	{
		return _entity_id;
	}

	static void init(uint32_t signature)
	{
		T::_signature = signature;
	}

	static uint32_t signature()
	{
		return _signature;
	}

	template<typename... Args>
	static uint32_t add(uint32_t entity_id, Args&&... args)
	{
		return _data.add(entity_id, args...);
	}

	static T& getData(uint32_t index)
	{
		return _data[index];
	}

protected:
	Component() :
		BaseComponent()
	{}

	Component(uint32_t entity_id) :
		BaseComponent(entity_id)
	{}

	friend T;

	static uint32_t _signature;
	static fva::SwapArray<T> _data;
};

template<typename T> 
uint32_t Component<T>::_signature;

template<typename T>
fva::SwapArray<T> Component<T>::_data;