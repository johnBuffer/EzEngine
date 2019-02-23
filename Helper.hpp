#pragma once

#include <iostream>

template <typename... T>
struct ComponentSet;

template <>
struct ComponentSet<>
{
	static constexpr uint64_t getSignature()
	{
		return 0U;
	}
};

template <typename First, typename... Rest>
struct ComponentSet<First, Rest...>
{
	static constexpr uint64_t getSignature()
	{
		return First::signature() | ComponentSet<Rest...>::getSignature();
	}
};

template <typename C>
constexpr uint64_t getSignature()
{
	return C::signature();
}

template <typename C1, typename C2, typename... Rest>
constexpr uint64_t getSignature()
{
	return C1::signature() | getSignature<C2, Rest...>();
}
