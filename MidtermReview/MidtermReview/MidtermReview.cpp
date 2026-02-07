
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>



// constant time complexity O(1)
// does one thing regardless of the input size
// linear goes up by 2 for each input size O(n)
int constantTime(int n)
{
	return n * n;
}

// linear time complexity O(n)
// loops though the input size once, so it grows linearly with the input size
// bigger n = slower time complexity
int linearTime(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += i;
	}
	return sum;
}

// very fast even for large input sizes, because it only loops through half of the input size
int logarithmicTime(int n)
{
	int count = 0;
	int i = n;
	while (i > 1)
	{
		i = i / 2;
		count++;
	}
	return count;
}

class House
{
public:
	int mPrice;
	int mSqFoot;
	int mRooms;
	int mDistance;
};

class HouseListing
{
public:
	void AddHouse(const House& house)
	{
		mHouses.push_back(house);
	}

	void PrintWithCriteria()
	{

	}
private:
	std::vector<House> mHouses;
};

int main()
{
    // Create a function that has a time complexity of:
	// O(1):
	
	// O(n)
	// O(n/2)
	// O(logn)

	
	return 0;
}
