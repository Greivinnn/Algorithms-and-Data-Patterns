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
    std::cout << "\n";

    Vector<const int*> pathDFS;
    Vector<const int*> pathBFS;

    std::cout << "Path from 0-9 (DFS):\n";
    myGraph.GetPathDFS(0, 9, pathDFS);
    for (int i = pathDFS.Size() - 1; i >= 0; --i)
    {
        std::cout << (*pathDFS[i]) << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Path from 0-9 (BFS):\n";
    myGraph.GetPathBFS(0, 9, pathBFS);
    for (int i = pathBFS.Size() - 1; i >= 0; --i)
    {
        std::cout << (*pathBFS[i]) << " ";
    }
    std::cout << "\n";

}
void CitiesOfVancouver()
{
    // Create a City object (string)
    // add all the cities to a vector
    // add the cities to the graph, then link them all where applicable
    // Print all the connections
    // find paths between cities

    // store all of the cities
    Vector<std::string> cities;
    cities.PushBack("Vancouver");       // 0
    cities.PushBack("Burnaby");         // 1
    cities.PushBack("North_Vancouver"); // 2
    cities.PushBack("Delta");           // 3
    cities.PushBack("Richmond");        // 4
    cities.PushBack("New_West");        // 5
    cities.PushBack("Coquitlam");       // 6
    cities.PushBack("Victoria");        // 7
    cities.PushBack("Naniamo");         // 8
    cities.PushBack("Quiznel");         // 9
    cities.PushBack("Langley");         // 10
    cities.PushBack("Abbotsford");      // 11
    cities.PushBack("Maple_Ridge");     // 12
    cities.PushBack("Port_Coquitlam");  // 13
    cities.PushBack("Surrey");          // 14

    // add to the graph
    Graph<std::string> vancouverMap;
    for (int i = 0; i < cities.Size(); ++i)
    {
        vancouverMap.AddItem(&cities[i]);
    }
    // link them all together
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
    vancouverMap.AddLink(11, 12);

    std::cout << "Connected Cities of Greater Vancouver:\n";
    vancouverMap.PrintGraph();
    std::cout << "\n\n";
    int startingIndex = 0;
    Vector<const std::string*> connectionsDFS;
    Vector<const std::string*> connectionsBFS;
    vancouverMap.GetAllConnectionsDFS(startingIndex, connectionsDFS);
    vancouverMap.GetAllConnectionsBFS(startingIndex, connectionsBFS);
    std::cout << "Cities Connected To " << cities[startingIndex] << " (DFS):\n";
    for (int i = 0; i < connectionsDFS.Size(); ++i)
    {
        std::cout << (*connectionsDFS[i]) << " ";
    }
    std::cout << "\n";
    std::cout << "Cities Connected To " << cities[startingIndex] << " (BFS):\n";
    for (int i = 0; i < connectionsBFS.Size(); ++i)
    {
        std::cout << (*connectionsBFS[i]) << " ";
    }
    std::cout << "\n\n";

    int islandStartingIndex = 7;
    connectionsDFS.Clear();
    connectionsBFS.Clear();
    vancouverMap.GetAllConnectionsDFS(islandStartingIndex, connectionsDFS);
    vancouverMap.GetAllConnectionsBFS(islandStartingIndex, connectionsBFS);
    std::cout << "Cities Connected To " << cities[islandStartingIndex] << " (DFS):\n";
    for (int i = 0; i < connectionsDFS.Size(); ++i)
    {
        std::cout << (*connectionsDFS[i]) << " ";
    }
    std::cout << "\n";
    std::cout << "Cities Connected To " << cities[islandStartingIndex] << " (BFS):\n";
    for (int i = 0; i < connectionsBFS.Size(); ++i)
    {
        std::cout << (*connectionsBFS[i]) << " ";
    }
    std::cout << "\n\n";

    int startIndex = 0;
    int endIndex = 7;
    Vector<const std::string*> cityRoute;
    std::cout << "Getting Path From " << cities[startIndex] << " to " << cities[endIndex] << " (DFS):\n";
    if (vancouverMap.GetPathDFS(startIndex, endIndex, cityRoute))
    {
        for (int i = cityRoute.Size() - 1; i >= 0; --i)
        {
            std::cout << (*cityRoute[i]) << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Path was not found\n";
    }
    std::cout << "\n";

    cityRoute.Clear();
    std::cout << "Getting Path From " << cities[startIndex] << " to " << cities[endIndex] << " (BFS):\n";
    if (vancouverMap.GetPathBFS(startIndex, endIndex, cityRoute))
    {
        for (int i = cityRoute.Size() - 1; i >= 0; --i)
        {
            std::cout << (*cityRoute[i]) << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "Path was not found\n";
    }
    std::cout << "\n";

}
struct Tile
{
    int x = 0;
    int y = 0;

    // used after doing path finding
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

    friend std::ostream& operator<<(std::ostream& os, const Tile& t)
    {
        os << t.x << "_" << t.y;
        return os;
    }
};
void ClearTileMap(Vector<Tile>& tileMap)
{
    for (int i = 0; i < tileMap.Size(); ++i)
    {
        tileMap[i].isInPath = false;
    }
}
void DrawTileMap(int width, int height, const Vector<Tile>& tileMap)
{
    std::cout << "    ";
    for (int w = 0; w < width; ++w)
    {
        if (w <= 9)
        {
            std::cout << "0" << w << "  ";
        }
        else
        {
            std::cout << w << "  ";
        }
    }
    std::cout << "\n";
    for (int h = 0; h < height; ++h)
    {
        if (h <= 9)
        {
            std::cout << "0" << h << " ";
        }
        else
        {
            std::cout << h << " ";
        }
        for (int w = 0; w < width; ++w)
        {
            int index = w + (h * width);
            tileMap[index].Draw();
        }
        std::cout << "\n";
    }
}
void TileMapSearch()
{
    Vector<Tile> tileMap;
    Graph<Tile> tileMapGraph;
    std::string input;
    bool isDone = false;

    int width = 0;
    int height = 0;
    std::cout << "Enter Map Width (1-99):";
    std::cin >> width;
    std::cout << "Enter Map Height (1-99):";
    std::cin >> height;
    // draw the map with number outlines
    // need extra line to display coordinates
    // draw top row indices

    // clear/reset data
    tileMapGraph.Terminate();
    tileMap.Clear();

    // add the tiles to the tilemap
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

    // add the tiles to the graph (eg: like nav mesh)
    for (int i = 0; i < tileMap.Size(); ++i)
    {
        tileMapGraph.AddItem(&tileMap[i]);
    }
    // set up links
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

    while (!isDone)
    {
        system("cls");
        std::cout << "Tile Map:\n";
        ClearTileMap(tileMap);
        DrawTileMap(width, height, tileMap);

        int startX = 0;
        int startY = 0;
        int endX = 0;
        int endY = 0;
        std::cout << "Enter Start X:";
        std::cin >> startX;
        std::cout << "Enter Start Y:";
        std::cin >> startY;
        std::cout << "Enter End X:";
        std::cin >> endX;
        std::cout << "Enter End Y:";
        std::cin >> endY;

        system("cls");
        std::cout << "Path From (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ") (DFS):\n";
        int startIndex = startX + (startY * width);
        int endIndex = endX + (endY * width);
        Vector<const Tile*> path;
        if (tileMapGraph.GetPathDFS(startIndex, endIndex, path))
        {
            for (int i = 0; i < path.Size(); ++i)
            {
                int index = path[i]->x + (path[i]->y * width);
                tileMap[index].isInPath = true;
            }
        }
        DrawTileMap(width, height, tileMap);

        std::cin >> input;
        isDone = input == "done";
        if (isDone)
        {
            break;
        }

        std::cout << "\n\n\n";
        std::cout << "Path From (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ") (BFS):\n";
        path.Clear();

        ClearTileMap(tileMap);

        if (tileMapGraph.GetPathBFS(startIndex, endIndex, path))
        {
            for (int i = 0; i < path.Size(); ++i)
            {
                int index = path[i]->x + (path[i]->y * width);
                tileMap[index].isInPath = true;
            }
        }
        DrawTileMap(width, height, tileMap);

        std::cin >> input;
        isDone = input == "done";
        if (isDone)
        {
            break;
        }
    }
}

int main()
{
	TileMapSearch();
}

