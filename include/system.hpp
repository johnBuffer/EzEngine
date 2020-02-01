#pragma once

#include <stdint.h>
#include <memory>
#include <vector>
#include "entity.hpp"
#include "filter.hpp"


namespace ez
{
	// Interface class
	class SystemInterface
	{
	public:
		using ptr = std::unique_ptr<SystemInterface>;

		SystemInterface() = default;
		SystemInterface(const fva::ID filter_)
			: filter(filter_)
		{}

		virtual void execute() = 0;

		void add(Entity& entity)
		{
			if (matches(entity.getKey())) {
				entities.push_back(entity.getID());
			}
		}

	protected:
		const fva::ID filter;
		std::vector<fva::ID> entities;

	private:
		bool matches(fva::ID key) const
		{
			return (filter & key) == filter;
		}
	};

	// Backend class
	template<typename ...Args>
	class System : public SystemInterface
	{
	public:
		using ptr = std::unique_ptr<SystemInterface>;

		System()
			: SystemInterface(Filter<Args...>().getFilter())
		{
		}

		const fva::ID getFilter() const
		{
			return filter.getFilter();
		}
	};
}
