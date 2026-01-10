#pragma once
#include <cstddef>
template<typename T, std::size_t N>
class Array
{
public:
	// base constructor, called by default
	Array()
	{
		// allocate memory 
		// size required is size of T type object
		// times the number of items N
		mValues = new T[N];

	}
	// constructor overload
	Array(T initValue)
	{
		mValues = new T[N];
		for (std::size_t i = 0; i < N; ++i)
		{
			mValues[i] = initValue;
		}
	}
	// destructor when destroyed
	~Array()
	{
		delete[] mValues;
		mValues = nullptr;
	}

	// gets the number of elements in the array
	std::size_t Size()
	{
		return N;
	}

	// Gets the data stored in the array
	T* Data()
	{
		return mValues;
	}

	// const version
	const T* Data() const
	{
		return mValues;
	}

	// operator overloads to access data
	T& operator[](std::size_t index)
	{
		// can add custom data to catch out of bounds
		// eg: assert, throw/catch
		return mValues[index];
	}
	
	// const version
	const T& operator[](std::size_t index) const
	{
		return mValues[index];
	}
private:
	T* mValues;

};
