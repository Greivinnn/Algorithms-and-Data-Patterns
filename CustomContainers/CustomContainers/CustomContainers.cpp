#include <iostream>
#include "Array.h"
#include "Vector.h"

int main()
{
    std::cout << "Custom Containers!\n";

    Array<int, 5> myInts(0);
    for (std::size_t i = 0; i < myInts.Size(); ++i)
    {
        myInts[i] = i + 1;
    }

    for (std::size_t i = 0; i < myInts.Size(); ++i)
    {
        std::cout << "Value at: " << i << " is " << myInts[i] << "\n";
    }

    Vector<int> myVector;
    myVector.Reserve(10);
    for (int i = 0; i < 10; ++i)
    {
        myVector.PushBack(i + 1);
    }
    std::cout << "Vector:\n";
    for (size_t i = 0; i < myVector.Size(); ++i)
    {
        std::cout << "Value at " << i << " is " << myVector[i] << "\n";
    }
    for (std::size_t i = 0; i < 20; ++i)
    {
        myVector.PushBack(i + 1);
    }
}
