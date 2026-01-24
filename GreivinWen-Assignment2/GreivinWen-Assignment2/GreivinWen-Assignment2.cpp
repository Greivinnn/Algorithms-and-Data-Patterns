// GreivinWen-Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Inventory.h"


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Inventory playerInventory;
	playerInventory.Initialize();
	for (int i = 0; i < 100; ++i)
	{
		// Generate a random number between 0 and 4 (inclusive)
		// This corresponds to the ItemType enum values
		int randomType = std::rand() % static_cast<int>(ItemType::Count);

		// Cast the random number to ItemType
		ItemType randomItem = static_cast<ItemType>(randomType);

		// Add the random item to inventory
		playerInventory.AddItem(randomItem);
	}

	std::cout << "\n\nInventory after adding 100 random items:\n";
	playerInventory.DisplayInventory();
	
	return 0;
}
