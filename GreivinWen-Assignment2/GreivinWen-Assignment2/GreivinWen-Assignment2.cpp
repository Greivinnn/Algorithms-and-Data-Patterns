// GreivinWen-Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"
#include "Inventory.h"


int main()
{
	Item smallPotion(ItemType::SmallHpPotion, 20);
	smallPotion.AddItem();
	smallPotion.AddItem();
	smallPotion.AddItem();
	smallPotion.AddItem();
	smallPotion.PrintItems();

	Inventory playerInventory;
	playerInventory.DisplayInventory();
	
	return 0;
}
