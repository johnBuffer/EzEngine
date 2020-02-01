#pragma once

#include <fast_array.hpp>



template<typename C1, typename... Cs>
class Filter
{
public:
	Filter()
		: filter_value(C1::getKey() | Filter<Cs...>().filter_value)
	{
	}

	fva::ID getFilter() const
	{
		return filter_value;
	}

private:
	fva::ID filter_value;
};

template<typename C1>
class Filter<C1>
{
public:
	Filter()
		: filter_value(C1::getKey())
	{}

	fva::ID getFilter() const
	{
		return filter_value;
	}

	bool matches(fva::ID key) const
	{
		return filter_value & key == filter_value;
	}

	fva::ID filter_value;
};


template<>
class Filter<void>
{
public:
	Filter()
		: filter_value(0U)
	{}

private:
	fva::ID filter_value;
};

