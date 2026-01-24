#include "Inventory.h"
#include "PriorityQueue.h"
#include <iostream>

Inventory::Inventory()
{
	
}

void Inventory::Initialize()
{
	// Initialize items with initial counts
	Item smallPotion(ItemType::SmallHpPotion, 20, 5);
	mItems.PushBack(smallPotion);

	Item mediumPotion(ItemType::MediumHpPotion, 50, 3);
	mItems.PushBack(mediumPotion);

	Item largePotion(ItemType::LargeHpPotion, 100, 1);
	mItems.PushBack(largePotion);

	Item fragBomb(ItemType::FragBomb, 75, 10);
	mItems.PushBack(fragBomb);

	Item gasBomb(ItemType::GasBomb, 50, 7);
	mItems.PushBack(gasBomb);
}

void Inventory::AddItem(ItemType itemType)
{
	if (!mItems.Size())
	{
		std::cout << "\n\nInventory is empty for now...\n\n";
		return;
	}

	// Find the item in the vector and increase its count
	bool itemFound = false;
	for (size_t i = 0; i < mItems.Size(); ++i)
	{
		if (mItems[i].GetItemType() == itemType)
		{
			mItems[i].AddItem();
			itemFound = true;
			break;
		}
	}

	if (!itemFound)
	{
		std::cout << "Item type not found in inventory!\n";
	}
}

void Inventory::DisplayInventory() const
{
	// Create a PriorityQueue
	PriorityQueue<Item> priorityQueue;

	// Add everything from the inventory Vector to the PriorityQueue
	// Note: Each item already has its own mCount, so we just add each unique item once
	for (size_t i = 0; i < mItems.Size(); ++i)
	{
		priorityQueue.Push(mItems[i]);
	}

	// Store the initial size before we start popping
	size_t totalItemTypes = priorityQueue.Size();
	int totalItemCount = 0;

	// Print the PriorityQueue in order of highest count
	std::cout << "\n===== INVENTORY BY PRIORITY (Highest Count First) =====\n";

	while (!priorityQueue.Empty())
	{
		Item topItem = priorityQueue.Top();
		topItem.PrintItems();
		totalItemCount += topItem.GetCount();
		priorityQueue.Pop();
	}

	std::cout << "\nTotal item types in priority queue: " << totalItemTypes << "\n";
	std::cout << "Total item count: " << totalItemCount << "\n";
	std::cout << "========================================================\n";
}