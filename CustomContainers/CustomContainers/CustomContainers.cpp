#include <iostream>
#include "Array.h"
#include "Vector.h"
#include "PriorityQueue.h"

int main()
{
	PriorityQueue<int> priorityQueue;
	for (int i = 0; i < 20; ++i)
	{
		int value = rand() % 100;
		priorityQueue.Push(value);
		std::cout << value << " ";
	}
	std::cout << "\n\n";

	/*while (!priorityQueue.Empty())
	{
		std::cout << priorityQueue.Top() << "\n";
		priorityQueue.Pop();
	}*/
 
	return 0;
}
