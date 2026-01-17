#include <iostream>
#include "Array.h"
#include "Vector.h"

int main()
{
	Array<int, 10> myInts;
	for (int i = 0; i < myInts.Size(); ++i)
	{
		myInts[i] = rand() % 100;
	}

	// non-const iterator 
	for (Array<int, 10>::Iterator iter = myInts.Begin(); iter != myInts.End(); ++iter)
	{
		std::cout << "Array Value: " << *iter << "\n";
	}

	std::sort(myInts.Begin(), myInts.End());
	/*std::cout << "Array sorted:\n";
	for (Array<int, 10>::Iterator iter = myInts.Begin(); iter != myInts.End(); ++iter)
	{
		std::cout << "Array Value: " << *iter << "\n";
	}*/
 
	return 0;
}
