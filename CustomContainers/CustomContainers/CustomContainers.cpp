#include <iostream>
#include "Array.h"
#include "Vector.h"
#include "PriorityQueue.h"
#include "Vector2.h";
#include "KDTree.h"
#include <string>
#include "Graph.h"

struct Item
{
	std::string namme;
	Vector2 position;
};

void GraphTesting()
{
	std::cout << "Graph and Grapg Traversal Test\n";

	Graph<int> myGraph;
	Vector<int> graphData;
	for (int i = 0; i < 10; ++i)
	{
		graphData.PushBack(i);
	}

	for (int i = 0; i < graphData.Size(); ++i)
	{
		myGraph.AddItem(&graphData[i]);
	}
	myGraph.AddLink(0, 1);
	myGraph.AddLink(0, 2);
	myGraph.AddLink(1, 3);
	myGraph.AddLink(1, 4);
	myGraph.AddLink(2, 5);
	myGraph.AddLink(2, 6);
	myGraph.AddLink(3, 7);
	myGraph.AddLink(4, 8);
	myGraph.AddLink(5, 9);
	myGraph.PrintGraph();

	Vector<const int*> connectionsDFS;
	Vector<const int*> connectionsBFS;

	myGraph.GetAllConnectionsDFS(0, connectionsDFS);
	myGraph.GetAllConnectionsBFS(0, connectionsBFS);

	std::cout << "Connections DFS:\n";
	for (int i = 0; i < connectionsDFS.Size(); ++i)
	{
		std::cout << (*connectionsDFS[i]) << " ";
	}
	std::cout << "\n";

	std::cout << "Connections BFS:\n";
	for (int i = 0; i < connectionsBFS.Size(); ++i)
	{
		std::cout << (*connectionsBFS[i]) << " ";
	}
	std::cout << "\n";

	Vector<const int*> pathDFS;
	Vector<const int*> pathBFS;
	myGraph.GetPathDFS(0, 9, pathDFS);
	myGraph.GetPathBFS(0, 9, pathBFS);

	std::cout << "Path from 0-9 (DFS):\n";
	for (int i = pathDFS.Size() - 1; i >= 0; --i)
	{
		std::cout << (*pathDFS[i]) << " ";
	}
	std::cout << "\n";

	std::cout << "Path from 0-9 (BFS):\n";
	for (int i = pathBFS.Size() - 1; i >= 0; --i)
	{
		std::cout << (*pathBFS[i]) << " ";
	}
	std::cout << "\n";
}

void CitiesOfVan()
{

	// Create a city object
	// add all the cities to a vector
	// add the cities to the graph, then link them all where applicable
	// Print all the connections
	// find path between cities

	Vector<std::string> cities;
	cities.PushBack("Vancouver");			// 0
	cities.PushBack("Burnaby");				// 1
	cities.PushBack("North-Vancouver");		// 2
	cities.PushBack("West-Vancouver");		// 3
	cities.PushBack("Delta");				// 4
	cities.PushBack("Richmond");			// 5
	cities.PushBack("Coquitlam");			// 6
	cities.PushBack("Victoria");			// 7
	cities.PushBack("Nanaimo");				// 8
	cities.PushBack("Quiznel");				// 9
	cities.PushBack("Langeley");			// 10
	cities.PushBack("Abbotsford");			// 11
	cities.PushBack("Maple-Ridge");			// 12
	cities.PushBack("Port-Coquitlam");		// 13
	cities.PushBack("Surrey");				// 14

	Graph<std::string> vancouverMap;
	for (int i = 0; i < cities.Size(); ++i)
	{
		vancouverMap.AddItem(&cities[i]);
	}

	vancouverMap.AddLink(0, 1);
	vancouverMap.AddLink(0, 2);
	vancouverMap.AddLink(0, 4);
	vancouverMap.AddLink(1, 2);
	vancouverMap.AddLink(1, 14);
	vancouverMap.AddLink(1, 5);
	vancouverMap.AddLink(1, 6);
	vancouverMap.AddLink(3, 4);
	vancouverMap.AddLink(3, 14);
	vancouverMap.AddLink(4, 14);
	vancouverMap.AddLink(4, 5);
	vancouverMap.AddLink(5, 14);
	vancouverMap.AddLink(6, 13);
	vancouverMap.AddLink(6, 12);
	vancouverMap.AddLink(7, 8);
	vancouverMap.AddLink(8, 9);
	vancouverMap.AddLink(10, 14);
	vancouverMap.AddLink(10, 11);
	vancouverMap.AddLink(10, 12);

	vancouverMap.PrintGraph();
	std::cout << "\n\n";
	int startingIndex = 0;
	Vector<const std::string*> connectionDFS;
	Vector<const std::string*> connectionBFS;
	vancouverMap.GetAllConnectionsDFS(startingIndex, connectionDFS);
	vancouverMap.GetAllConnectionsBFS(startingIndex, connectionBFS);

	std::cout << "Cities Connected To " << cities[startingIndex] << " (DFS):\n";
	for (int i = 0; i < connectionDFS.Size(); ++i)
	{
		std::cout << (*connectionDFS[i]) << " ";
	}
	std::cout << "\n";
	std::cout << "Cities Connected To " << cities[startingIndex] << " (BFS):\n";
	for (int i = 0; i < connectionBFS.Size(); ++i)
	{
		std::cout << (*connectionBFS[i]) << " ";
	}
	std::cout << "\n";

	int islandStartingIndex = 7;
	connectionDFS.Clear();
	connectionBFS.Clear();
	vancouverMap.GetAllConnectionsDFS(islandStartingIndex, connectionDFS);
	vancouverMap.GetAllConnectionsBFS(islandStartingIndex, connectionBFS);

	std::cout << "Cities Connected To " << cities[islandStartingIndex] << " (DFS):\n";
	for (int i = 0; i < connectionDFS.Size(); ++i)
	{
		std::cout << (*connectionDFS[i]) << " ";
	}
	std::cout << "\n";
	std::cout << "Cities Connected To " << cities[islandStartingIndex] << " (BFS):\n";
	for (int i = 0; i < connectionBFS.Size(); ++i)
	{
		std::cout << (*connectionBFS[i]) << " ";
	}
	std::cout << "\n";

	int startIndex = 0;
	int endIndex = 11;
	Vector<const std::string*> cityRoute;
	std::cout << "\n\nGetting Path From " << cities[startIndex] << " to " << cities[endIndex] << " (DFS):\n";
	if (vancouverMap.GetPathDFS(startIndex, endIndex, cityRoute))
	{
		for (int i = cityRoute.Size() - 1; i >= 0; --i)
		{
			std::cout << (*cityRoute[i]) << " ";
		}
	}
	else
	{
		std::cout << "Path not found.\n";
	}

	cityRoute.Clear();
	std::cout << "\n\nGetting path from " << cities[startIndex] << " to " << cities[endIndex] << " (BFS):\n";

	if (vancouverMap.GetPathBFS(startIndex, endIndex, cityRoute))
	{
		for (int i = cityRoute.Size() - 1; i >= 0; --i)
		{
			std::cout << (*cityRoute[i]) << " ";
		}
	}
	else
	{
		std::cout << "Path not found.\n";
	}
	std::cout << "\n\n\n\n\n\n";
}

struct Tile
{
	int x = 0;
	int y = 0;

	bool isInPath = false;
	void Draw() const
	{
		if (isInPath)
		{
			std::cout << "[0] ";
		}
		else
		{
			std::cout << "[ ] ";
		}
	}

	std::ostream& operator<<(std::ostream& os, const Tile& t)
};


void DrawTileMap(int width, int height,Vector<Tile> tileMap)
{
	std::cout << "    ";

	for (int w = 0; w <= height; ++w)
	{
		if (w < 9)
		{
			std::cout << "0" << w << "   ";
		}
		else
		{
			std::cout << w << "   ";
		}
	}
	std::cout << "\n";
	for (int h = 0; h <= height; ++h)
	{
		if (h < 9)
		{
			std::cout << "0" << h << "   ";
		}
		else
		{
			std::cout << h << "   ";
		}
		for (int w = 0; w < width; ++w)
		{
			int index = w + (h * width);
			tileMap[index].Draw();
		}
		std::cout << "\n";
	}
}

int main()
{
	Vector<Tile> tileMap;
	Graph<Tile> tileMapGraph;
	std::string input;
	bool isDone = false;

	while (!isDone)
	{
		system("cls");
		std::cout << "Tile Map\n";

		int width = 0;
		int height = 0;
		std::cout << "Enter Map Width: ";
		std::cin >> width;
		std::cout << "\nEnter Map Height: ";
		std::cin >> height;

		tileMapGraph.Terminate();
		tileMap.Clear();

		tileMap.Resize(width * height);
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				int index = x + (y * width);
				tileMap[index].x = x;
				tileMap[index].y = y;
			}
		}
		
		for (int i = 0; i < tileMap.Size(); ++i)
		{
			tileMapGraph.AddItem(&tileMap[i]);
		}

		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				int currentIndex = x + (y * width);
				if (x + 1 < width)
				{
					int rightIndex = (x + 1) + (y * width);
					tileMapGraph.AddLink(currentIndex, rightIndex);
				}
				if (y + 1 < height)
				{
					int downIndex = x + ((y + 1) * width);
					tileMapGraph.AddLink(currentIndex, downIndex);
				}
			}
		}

		DrawTileMap(width, height, tileMap);

		int startX = 0;
		int startY = 0;
		int endX = 0;
		int endY = 0;

		std::cout << "Enter Start X: ";
		std::cin >> startX;
		std::cout << "Enter Start Y: ";
		std::cin >> startY;
		std::cout << "Enter End X: ";
		std::cin >> endX;
		std::cout << "Enter End Y: ";
		std::cin >> endY;

		system("cls");
		std::cout << "Path Frpm (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ") (DFS):\n";

		int startIndex = startX + (startY * width);
		int endIndex = endY + (endY * width);
		Vector<const Tile*> path;
		if (tileMapGraph.GetPathDFS(startIndex, endIndex, path))
		{
			for (int i = 0; i < path.Size(); ++i)
			{
				int index = path[i]->x + (path[i]->y * width);
				tileMap[index].isInPath = true;
			}
		}

		

		std::cin >> input;

		isDone = input == "done";
	}
}
