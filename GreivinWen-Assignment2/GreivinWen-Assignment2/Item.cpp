#include "Item.h"
#include <iostream>

// constructor
Item::Item(ItemType itemType, int value, int initialCount)
	: mType(itemType), mValue(value), mCount(initialCount)
{
	initializeItemName();
}

// default constructor
Item::Item()
	: mType(ItemType::SmallHpPotion), mValue(0), mCount(0)
{
	initializeItemName();
}

void Item::initializeItemName()
{
	switch (mType)
	{
	case ItemType::SmallHpPotion:
		mName = "Small Health Potion";
		break;
	case ItemType::MediumHpPotion:
		mName = "Medium Health Potion";
		break;
	case ItemType::LargeHpPotion:
		mName = "Large Health Potion";
		break;
	case ItemType::FragBomb:
		mName = "Fragmentation Bomb";
		break;
	case ItemType::GasBomb:
		mName = "Gas Bomb";
		break;
	default:
		mName = "Unknown Item";
		break;
	}
}
// destructor
Item::~Item()
{

}
// tracks if the count > 0
void Item::ConsumeItem()
{
	if (mCount > 0)
	{
		mCount--;
		std::cout << "Consumed one " << mName << ". " << mCount << " left.\n";
	}
	else
	{
		std::cout << "No more " << mName << " left to consume.\n";
	}
}
// add item to mCount
void Item::AddItem()
{
	mCount++;
	std::cout << "Added one " << mName << ". " << mCount << " in total.\n";
}
// print the mCount
void Item::PrintItems() const
{
	std::cout << "\n\nNumber of items in stack: " << mCount << "\n";
	std::cout << mName << " (Value: " << mValue << ")\n";
}
// get item type
ItemType Item::GetItemType() const
{
	return mType;
}

int Item::GetCount() const
{
	return mCount;
}