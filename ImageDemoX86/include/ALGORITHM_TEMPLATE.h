#pragma once
///< 

template<typename T>
static inline int GetIntValue(T data)
{
	return int(data+0.5);
}

template<typename T>
static inline T maxValue(T a, T b)
{
	return a>b?a:b;
}

template<typename T>
static inline T minValue(T a, T b)
{
	return a<b?a:b;
}