#pragma once
#include "Vector.h"	
#include "Item.h"

class Inventory
{
public:
	Inventory();
	void Initialize();
	void AddItem(ItemType itemType);
	void DisplayInventory() const;
private:
	Vector<Item> mItems;
};