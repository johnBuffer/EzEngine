#pragma once

#include <cstdint>



template<typename C1, typename... Cs>
class Filter
{
public:
	Filter()
		: filter_value(C1::id | Filter<Cs...>().filter_value)
	{
	}

	uint64_t getFilter()
	{
		return filter_value;
	}

private:
	uint64_t filter_value;
};

template<typename C1>
class Filter<C1>
{
public:
	Filter()
		: filter_value(C1::id)
	{
	}

	uint64_t filter_value;
};


template<>
class Filter<void>
{
public:
	Filter()
		: filter_value(0U)
	{
	}

private:
	uint64_t filter_value;
};

