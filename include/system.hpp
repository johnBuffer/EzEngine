#pragma once

#include <stdint.h>
#include <memory>
#include <fast_array.hpp>
#include "entity.hpp"


namespace ez
{
	class SystemInterface
	{
	public:
		using ptr = std::unique_ptr<SystemInterface>;

		virtual void execute() = 0;

		//void addEntity(fva::Handle<Entity> entity);
	
	private:
		//fva::Container<Entity> entities;
	};

	template<typename T>
	class System
	{
	public:
		using ptr = std::unique_ptr<SystemInterface>;

		System() = default;
		
		const uint32_t getID() const;

		static std::unique_ptr<T> create();

	private:
	};

	template<typename T>
	inline const uint32_t System<T>::getID() const
	{
		return id;
	}
	template<typename T>
	inline std::unique_ptr<T> System<T>::create()
	{
		return T::initialize();
	}
}
