#pragma once
#include "FastVersatileArray.hpp"
#include <array>

const uint32_t MAX_COMPONENTS = 64;

class Entity
{
public:
	Entity() = default;

	explicit Entity(uint32_t id) :
		_id(id),
		_signature(0U)
	{}

	template<typename T, typename... Args>
	void addComponent(Args&&... args)
	{
		// Add the component to the entity
		uint32_t component_id = T::add(_id, args...);
		_components[T::id()] = component_id;
		
		// Update entity's signature
		_signature |= T::signature();
	}

	template<typename T>
	T* getComponent()
	{
		uint32_t index = _components[T::id()];
		if (index != -1)
			return &(T::getData(index));
		return nullptr;
	}

	template<typename T>
	T& get()
	{
		uint32_t index = _components[T::id()];
		return T::getData(index);
	}

	uint64_t getSignature() const
	{
		return _signature;
	}

private:
	uint32_t _id;
	uint64_t _signature;
	std::array<uint32_t, MAX_COMPONENTS> _components;

	friend class EntityHandle;
};

class EntityHandle
{
public:
	EntityHandle() :
		_source(nullptr),
		_id(-1)
	{}

	EntityHandle(fva::SwapArray<Entity>* source, uint32_t id) :
		_source(source),
		_id(id)
	{}

	EntityHandle(fva::SwapArray<Entity>* source, const Entity& entity) :
		_source(source),
		_id(entity._id)
	{}

	Entity* operator->()
	{
		return &(this->operator*());
	}

	Entity& operator*()
	{
		return (*_source)[_id];
	}

private:
	fva::SwapArray<Entity>* _source;
	uint32_t _id;
};

