#include "Inventory.h"

Inventory::Inventory()
{
	Initialize();
}

void Inventory::Initialize()
{
	Item smallPotion(ItemType::SmallHpPotion, 20);
	mItems.PushBack(smallPotion);
	Item mediumPotion(ItemType::MediumHpPotion, 50);
	mItems.PushBack(mediumPotion);
	Item largePotion(ItemType::LargeHpPotion, 100);
	mItems.PushBack(largePotion);
	Item fragBomb(ItemType::FragBomb, 75);
	mItems.PushBack(fragBomb);
	Item gasBomb(ItemType::GasBomb, 50);
	mItems.PushBack(gasBomb);
}
void Inventory::AddItem(ItemType itemType)
{
	if(!mItems.Size())
	{
		return;
	}

	switch (itemType)
	{
		case ItemType::SmallHpPotion:
			mItems[0].AddItem();
			break;
		case ItemType::MediumHpPotion:
			mItems[1].AddItem();
			break;
		case ItemType::LargeHpPotion:
			mItems[2].AddItem();
			break;
		case ItemType::FragBomb:
			mItems[3].AddItem();
			break;
		case ItemType::GasBomb:
			mItems[4].AddItem();
			break;
		default:
			break;
	}

	mItems.PushBack(Item(itemType, 0));
}
void Inventory::DisplayInventory() const
{
	for(size_t i = 0; i < mItems.Size(); ++i)
	{
		mItems[i].PrintItems();
	}	
}