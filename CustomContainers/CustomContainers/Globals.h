#pragma once
#include <functional>
#include "Vector.h"
#include <string>

namespace Globals
{
	std::size_t HashFunction(const std::string& str)
	{
		std::size_t hash = 0;
		for(std::size_t i = 0; i < str.size(); ++i)
		{
			hash = hash ^ ((std::size_t)(str[1]) << 1);
		}
		return hash;
	}

	template<typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template<typename T>
	void BubbleSort(Vector<T>& values, std::function<bool(const T&, const T&)>& sortFunc = nullptr)
	{
		std::size_t size = values.Size();
		for (std::size_t i = 0; i < size; ++i)
		{
			std::size_t minIndex = i;
			for (std::size_t j = 0; j < size - i - 1; ++j)
			{
				if (sortFunc != nullptr && sortFunc(values[j], values[j + 1] || values[j] > values[j + 1])
				{
					Swap(values[j], values[j + 1])
				}
				
			}
		}
	}

	template<typename T>
	void BubbleSort(Vector<T>& values, std::function<bool(const T&, const T&)>& sortFunc = nullptr)
	{
		std::size_t size = values.Size();
		for (std::size_t i = 0; i < size; ++i)
		{
			std::size_t minIndex = i;
			for (std::size_t j = 0; j < size - i - 1; ++j)
			{
				if (sortFunc(values[j], values[j + 1]))
				{
					minIndex = j;
				}
				if(i != minIndex)
				{
					Swap(values[i], values[minIndex]);
				}
			}
		}
	}

	template <typename T>
	void SelectionSort(Vector<T>& values, std::function<bool(const T&, const T&)>& sortFunc)
	{
		std::size_t size = values.Size();
		for (std::size_t i = 0; i < size - 1; ++i)
		{
			std::size_t minIndex = i;
			for (std::size_t j = i + 1; j < size; ++j)
			{
				if (sortFunc(values[j], values[minIndex]))
				{
					minIndex = j;
				}
			}
			if(i != minIndex)
			{
				Swap(values[i], values[minIndex]);
			}
		}
	}
}
