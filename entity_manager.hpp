#pragma once

#include "Entity.hpp"
#include "FastVersatileArray.hpp"
#include <list>
#include "Helper.hpp"

namespace ez
{
	class EntityManager
	{
	public:
		static EntityHandle create()
		{
			return s_instance->_create();
		}

		template<typename... Components>
		static std::list<EntityHandle> get()
		{
			return s_instance->_get<Components...>();
		}

	private:
		EntityManager() :
			_entity_counter(0)
		{}

		EntityHandle _create()
		{
			uint32_t index = _entities.add(_entity_counter++);
			return EntityHandle(&_entities, index);
		}

		template<typename... Args>
		std::list<EntityHandle> _get()
		{
			const uint64_t signature = getSignature<Args...>();
			std::list<EntityHandle> result_set;

			for (const Entity& entity : _entities)
			{
				if (entity.getSignature() == signature)
				{
					result_set.emplace_back(&_entities, entity);
				}
			}

			return result_set;
		}

		uint32_t _entity_counter;
		fva::SwapArray<Entity> _entities;

		static EntityManager* s_instance;
	};
}