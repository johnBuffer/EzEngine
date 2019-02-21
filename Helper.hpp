#pragma once

template<typename T>
uint64_t getSetSignature(uint64_t prev=0)
{
	return prev |= T::signature();
}

template<typename T, typename... Args>
uint64_t getSetSignature()
{
	return T::signature() |= getSetSignature<Args>();
}