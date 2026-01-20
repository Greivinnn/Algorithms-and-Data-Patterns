// GreivinWen-Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Item.h"

int main()
{
	Item smallPotion(ItemType::SmallHpPotion, 20);
	smallPotion.AddItem();
	smallPotion.AddItem();
	smallPotion.AddItem();
	smallPotion.AddItem();
	smallPotion.PrintItems();
	
	return 0;
}
