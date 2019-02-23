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