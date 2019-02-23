#pragma once

#include <iostream>

template <typename... T>
struct EntitySet;

template <>
struct EntitySet<>
{
	static constexpr uint64_t getSignature()
	{
		return 0U;
	}
};

template <typename First, typename... Rest>
struct EntitySet<First, Rest...>
{
	static constexpr uint64_t getSignature()
	{
		return First::signature() | EntitySet<Rest...>::getSignature();
	}
};