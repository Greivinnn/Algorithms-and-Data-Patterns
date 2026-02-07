#pragma once
#include <string>

enum class ItemType
{
	SmallHpPotion,
	MediumHpPotion,
	LargeHpPotion,
	FragBomb,
	GasBomb,
	Count // keeps track of number of item types
};

class Item
{
private:
	// stores item type
	ItemType mType;
	// stores item name
	std::string mName;
	// stores item damage or healing value
	int mValue;
	// stores the amount of items in stack
	int mCount;
public:
	// constructor
	Item(ItemType itemType, int value, int initialCount = 0)
		: mType(itemType), mValue(value), mCount(initialCount)
	{
		initializeItemName();
	}
	// default constructor
	Item()
		: mType(ItemType::SmallHpPotion), mValue(0), mCount(0)
	{
		initializeItemName();
	}
	// initializes item with their name
	void initializeItemName()
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
	~Item()
	{

	}
	// tracks if the count > 0
	void ConsumeItem()
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
	void AddItem()
	{
		mCount++;
		std::cout << "Added one " << mName << ". " << mCount << " in total.\n";
	}
	// print the mCount
	void PrintItems() const
	{
		std::cout << "\n\nNumber of items in stack: " << mCount << "\n";
		std::cout << mName << " (Value: " << mValue << ")\n";
	}
	ItemType GetItemType() const
	{
		return mType;
	}

	int GetCount() const
	{
		return mCount;
	}

	// comparison operator for priority queue (compares by count)
	bool operator>(const Item& other) const
	{
		return mCount > other.mCount;
	}

};