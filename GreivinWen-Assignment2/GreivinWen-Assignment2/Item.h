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
public:
	// constructor
	Item(ItemType itemType, int value, int initialCount = 0);
	// default constructor
	Item();
	// initializes item with their name
	void initializeItemName();
	// destructor
	~Item();
	// tracks if the count > 0
	void ConsumeItem();
	// add item to mCount
	void AddItem();
	// print the mCount
	void PrintItems() const;
	// get item type
	ItemType GetItemType() const;
	// get item count
	int GetCount() const;

	// comparison operator for priority queue (compares by count)
	bool operator>(const Item& other) const
	{
		return mCount > other.mCount;
	}
private:
	// stores item type
	ItemType mType;
	// stores item name
	std::string mName;
	// stores item damage or healing value
	int mValue;
	// stores the amount of items in stack
	int mCount;
};