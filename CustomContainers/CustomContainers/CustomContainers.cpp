#include <iostream>
#include "Array.h"
#include "Vector.h"
#include "PriorityQueue.h"
#include "Vector2.h";
#include "KDTree.h"
#include <string>

struct Item
{
	std::string namme;
	Vector2 position;
};

int main()
{
	Vector<Item> items;
	KDTree<float, 2> itemLocations;
	int maxItems = 100;
	items.Resize(maxItems);
	for (int i = 0; i < maxItems; ++i)
	{
		items[i].namme = "ItemName" + std::to_string(i);
		items[i].position = { (float)(rand() % 501), (float)(rand() % 501) };

		itemLocations.AddItem(&items[i].position.x, &items[i]);
	}

	itemLocations.BuildTree();

	Vector2 minRange = { 200.0f, 200.0f };
	Vector2 maxRange = { 300.0f, 300.0f };

	Vector<const void*> itemsInRange;
	itemLocations.FindInRange(itemsInRange, j & minRange.x, &maxRange.x);

	for(Vector<)
	return 0;
}
