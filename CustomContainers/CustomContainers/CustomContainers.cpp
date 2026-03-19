#include <iostream>
#include "Array.h"
#include "Vector.h"
#include "PriorityQueue.h"
#include "Vector2.h";
#include "KDTree.h"
#include <string>
#include "Graph.h"
#include "Vector3.h"
#include <cstdlib> 
#include <ctime>   
#include "UnorderedMap.h"
#include "Globals.h"
#include "Map.h"
#include "MSTGraph.h"
#include "MSTGraphK.h"
#include "WeightedGraph.h"

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

// Homework assignment 3
enum class PickupType
{
    Invalid,        // 0
    Health,         // 1
    Ammo,           // 2
    Coins,          // 3
    Upgrade,        // 4
    SpecialItem,    // 5
    Count           // 6
};

class PickUp
{
public:
    PickUp(PickupType pickupType, const Vector3& pos)
        : mType(pickupType), mPosition(pos)
    {
        if (pickupType == PickupType::Invalid)
        {
            mName = "Invalid";
        }
        else if (pickupType == PickupType::Health)
        {
            mName = "Health";
        }
        else if (pickupType == PickupType::Ammo)
        {
            mName = "Ammo";
        }
        else if (pickupType == PickupType::Coins)
        {
            mName = "Coins";
        }
        else if (pickupType == PickupType::Upgrade)
        {
            mName = "Upgrade";
        }
        else if (pickupType == PickupType::SpecialItem)
        {
            mName = "Special_Item";
        }
    }

    PickUp()
        : mType(PickupType::Invalid), mPosition(0.0f, 0.0f, 0.0f)
    {

    }

    const Vector3& GetPosition() const
    {
        return mPosition;
    }

    const PickupType& GetType() const
    {
        return mType;
    }

    const std::string& GetName() const
    {
        return mName;
    }
private:
    PickupType mType;
    std::string mName;
    Vector3 mPosition;
};

class PickupManager
{
public:
    PickupManager()
    {

    }
    ~PickupManager()
    {

    }

    void ReservePickups(std::size_t count)
    {
        mPickUpVector.Reserve(count);
    }

    // adds an item to the pickups and stores the position of it
    // also stores the pickup in the KDTree
    void AddItem(PickupType pickupType, const Vector3& pos)
    {
        // create and add pick up to vector
        mPickUpVector.PushBack(PickUp(pickupType, pos));

        // get pointer to the newly added pick up
        PickUp* pickupPtr = &mPickUpVector[mPickUpVector.Size() - 1];

        pickupPtr->GetPosition().x;

        // add to KDTree - pointer to position and pickup as user data
        mKDTree.AddItem(&pickupPtr->GetPosition().x, pickupPtr);
    }
    // does a search to find the closest item to the position
    const PickUp* GetClosestPickup(const Vector3& pos)
    {
        // make a const void to get the result of the KDTree.FindNearest at pos x
        const void* result = mKDTree.FindNearest(&pos.x);
        // static cast convert the void pointer to a pickup pointer and return it
        return (const PickUp*)result;
    }
    // do a search to find all items within a given range
    // use the pickupType to find a specific item, if Invalid, get all pickups in range
    void ObtainPickupsInRange(const Vector3& pos, float range, PickupType pickupType)
    {
        mLastSearchResults.Clear();

        // calculate the max and min range
        Vector3 minRange(pos.x - range, pos.y - range, pos.z - range);
        Vector3 maxRange(pos.x + range, pos.y + range, pos.z + range);

        // create a vector to store the void pointers from our KDTree
        Vector<const void*> foundItems;

        // if pickups invalid = get all pickups
        if (pickupType == PickupType::Invalid)
        {
            mKDTree.FindInRange(foundItems, &minRange.x, &maxRange.x, nullptr);
        }
        else
        {
            // Filter by pickup type using a lambda
            // how it works:
            // filterByType stores a lambda function 
            // [pickupType] is the capture clause, this tells the code capture the variable pickupType from surrounding scope
            // -> bool is the return type either true if is a valid pickupType, false if its invalid 
            auto filterByType = [pickupType](const void* userData) -> bool
                {
                    // static cast to make our void pointer userData to a Pickup pointer
                    const PickUp* pickup = (const PickUp*)userData;
                    // return the pickupType we got 
                    return pickup->GetType() == pickupType;
                };

            // pass everything to the KDTree function 
            mKDTree.FindInRange(foundItems, &minRange.x, &maxRange.x, filterByType);
        }

        // store the results in member variable so they can be accessed after the function call
        for (int i = 0; i < foundItems.Size(); ++i)
        {
            mLastSearchResults.PushBack((const PickUp*)foundItems[i]);
        }
    }

    const Vector<const PickUp*> GetLastSearchResults() const
    {
        return mLastSearchResults;
    }
	// builds the KDTree, needs to be called after all items have been added
    void BuildTree()
    {
        mKDTree.BuildTree();
    }

private:
    Vector<PickUp> mPickUpVector;
    KDTree<float, 3> mKDTree;
    Vector<const PickUp*> mLastSearchResults; // stores the results from ObtainPickupsInRange
};

// calculates the distance between two 3D points (player and item)
float CalculateDistance(const Vector3& pos1, const Vector3& pos2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float dz = pos2.z - pos1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void PrintPickupsInAttractRange(PickupManager& manager, const Vector3& playerPos, float attractRange)
{
    std::cout << "========================================\n";
    std::cout << "C. ITEMS IN ATTRACT RANGE (" << attractRange << "f):\n";
    std::cout << "========================================\n";

    // Call the existing ObtainPickupsInRange function
    manager.ObtainPickupsInRange(playerPos, attractRange, PickupType::Invalid);

    // Get the results from the function
    const Vector<const PickUp*>& pickupsInRange = manager.GetLastSearchResults();

    if (pickupsInRange.Size() == 0)
    {
        std::cout << "No pickups found in attract range.\n";
    }
    else
    {
        std::cout << "Found " << pickupsInRange.Size() << " pickup(s) in attract range:\n";
        for (int i = 0; i < pickupsInRange.Size(); ++i)
        {
            const PickUp* pickup = pickupsInRange[i];
            const Vector3& pickupPos = pickup->GetPosition();
            float distance = CalculateDistance(playerPos, pickupPos);

            std::cout << "  - " << pickup->GetName()
                << " at position (" << pickupPos.x << ", " << pickupPos.y << ", " << pickupPos.z << ")"
                << " | Distance: " << distance << "\n";
        }
    }
}

void PrintHealthPickupsInRange(PickupManager& manager, const Vector3& playerPos, float searchRange)
{
    std::cout << "========================================\n";
    std::cout << "D. HEALTH PICKUPS IN RANGE (" << searchRange << "f):\n";
    std::cout << "========================================\n";

    // Call the existing ObtainPickupsInRange function with Health filter
    manager.ObtainPickupsInRange(playerPos, searchRange, PickupType::Health);

    // Get the results from the function
    const Vector<const PickUp*>& healthPickups = manager.GetLastSearchResults();

    if (healthPickups.Size() == 0)
    {
        std::cout << "No health pickups found in range.\n";
    }
    else
    {
        std::cout << "Found " << healthPickups.Size() << " health pickup(s):\n";
        for (int i = 0; i < healthPickups.Size(); ++i)
        {
            const PickUp* pickup = healthPickups[i];
            const Vector3& pickupPos = pickup->GetPosition();
            float distance = CalculateDistance(playerPos, pickupPos);

            std::cout << "  - " << pickup->GetName()
                << " at position (" << pickupPos.x << ", " << pickupPos.y << ", " << pickupPos.z << ")"
                << " | Distance: " << distance << "\n";
        }
    }
}

void PrintClosestPickup(PickupManager& manager, const Vector3& playerPos)
{
    std::cout << "========================================\n";
    std::cout << "E. CLOSEST PICKUP TO PLAYER:\n";
    std::cout << "========================================\n";

    const PickUp* closestPickup = manager.GetClosestPickup(playerPos);

    if (closestPickup != nullptr)
    {
        const Vector3& pickupPos = closestPickup->GetPosition();
        float distance = CalculateDistance(playerPos, pickupPos);

        std::cout << "Closest pickup: " << closestPickup->GetName() << "\n";
        std::cout << "Location: (" << pickupPos.x << ", " << pickupPos.y << ", " << pickupPos.z << ")\n";
        std::cout << "Distance from player: " << distance << "\n";
    }
    else
    {
        std::cout << "No pickups found!\n";
    }
}

void CreateRandomPickups(PickupManager& manager, int count)
{
    srand(time(0));

    manager.ReservePickups(count);

    for (int i = 0; i < count; ++i)
    {
        // random position range from 0 to 100 in decimal 
        float x = static_cast<float>(rand() % 100);
        float y = static_cast<float>(rand() % 100);
        float z = static_cast<float>(rand() % 100);
        Vector3 pos(x, y, z);

        // Random pickup type excluding invalid ofc
        int typeIndex = (rand() % 5) + 1;  // random from 1 to 5
        PickupType type = static_cast<PickupType>(typeIndex);

        manager.AddItem(type, pos);
    }
}

void MapsFunctions()
{
    Map<int, int> myMap;
    for (int i = 0; i < 10; ++i)
    {
        int value = rand() % 1000; // random value between 0 and 999
        myMap.Insert(i, value);
        std::cout << value << " ";
    }
    std::cout << "\nHas key 3" << myMap.Has(3) << "\n";
    std::cout << "\nHas key 30" << myMap.Has(30) << "\n";

    Vector<int> allKeys;
    myMap.ObtainKeys(allKeys);
    std::cout << "Obtain all keys:\n";
    for (std::size_t i = 0; i < allKeys.Size(); ++i)
    {
        std::cout << allKeys[i] << " ";
    }
    std::cout << "\n Value with key 7" << myMap[7] << "\n";

    myMap.Remove(6);

    allKeys.Clear();
    myMap.ObtainKeys(allKeys);
    std::cout << "Obtain all keys after removing key 6:\n";
    for (std::size_t i = 0; i < allKeys.Size(); ++i)
    {
        std::cout << allKeys[i] << " ";
    }
    myMap.Clear();
}

void GloabalSorting()
{
    std::cout << "Custom Sorting:\n";
    Vector<int> myNumbers;
    int maxNumbers = 20;

    for (int i = 0; i < maxNumbers; ++i)
    {
        int value = 1 + (rand() % 100);
        myNumbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    //Globals::InsertionSort(myNumbers.Begin(), myNumbers.End());
    //Globals::MergeSort(myNumbers.Begin(), myNumbers.End());
    //Globals::QuickSort(myNumbers.Begin(), myNumbers.End());
    //Globals::BucketSort(myNumbers.Begin(), myNumbers.End());
   //Globals::HeapSort(myNumbers.Begin(), myNumbers.End());
   // Globals::IntroSort(myNumbers.Begin(), myNumbers.End());
    for (int i = 0; i < myNumbers.Size(); ++i)
    {
        std::cout << myNumbers[i] << " ";
    }
    std::cout << "\n\n";
}

// Homework assignment 4
void Assignment4()
{
    class Texture
    {
    public:
        Texture(const std::string& path)
            : filePath(path)
        {
        }
        Texture()
            : filePath("default_texture.png")
        {
        }
        void Print()
        {
            std::cout << "Rendering: " << filePath << "\n";
        }
    private:
        std::string filePath;
    };

    class TextureManager
    {
    public:
        static TextureManager* Get()
        {
            static TextureManager instance;
            return &instance;
        }
        std::size_t LoadTexture(const std::string& filePath)
        {
            auto uniqueKey = Globals::HashFunction(filePath);
            mTextures.Insert(uniqueKey, Texture(filePath));
            return uniqueKey;
        }
        Texture* GetTexture(std::size_t key)
        {
            return &mTextures[key];
        }
    private:
        UnorderedMap<std::size_t, Texture> mTextures;
    };

    class Entity
    {
    public:
        void Initialize(const std::string& textureFilePath)
        {
            mTextureId = TextureManager::Get()->LoadTexture(textureFilePath);
            mPosition = Vector2(0.0f, 0.0f);
        }
        void Update()
        {
            int dx = rand() % 20;
            int dy = rand() % 20;
            mPosition = Vector2(dx, dy);
        }
        Vector2 GetPosition() const
        {
            return mPosition;
        }
        void Render()
        {
            // Get the texture from the texture manager using our stored ID
            Texture* texture = TextureManager::Get()->GetTexture(mTextureId);
            if (texture)
            {
                texture->Print();
            }

            // Print the entity's position
            std::cout << "Position: (" << mPosition.x << ", " << mPosition.y << ")\n";
        }
    private:
        std::size_t mTextureId;
        Vector2 mPosition;
    };

    // main code
    srand(time(0));
    Vector<Entity> myEntities;
    Entity playerOne;
    Entity playerTwo;
    std::string enemyTexturePath = "enemy1234";
    playerOne.Initialize("player1");
    myEntities.PushBack(playerOne);
    playerTwo.Initialize("player2");
    myEntities.PushBack(playerTwo);

    for (int i = 0; i < 20; ++i)
    {
        Entity enemy;
        enemy.Initialize(enemyTexturePath);
        myEntities.PushBack(enemy);
    }

    for (std::size_t i = 0; i < myEntities.Size(); ++i)
    {
        myEntities[i].Update();
    }

    // Sort by closest to origin
    std::function<bool(const Entity&, const Entity&)> sortByDistance = [](const Entity& a, const Entity& b)
        {
            Vector2 posA = a.GetPosition();
            Vector2 posB = b.GetPosition();
            float distA = (posA.x * posA.x) + (posA.y * posA.y);
            float distB = (posB.x * posB.x) + (posB.y * posB.y);
            return distA > distB;
        };

    Globals::BubbleSort(myEntities, sortByDistance);

    for (std::size_t i = 0; i < myEntities.Size(); ++i)
    {
        myEntities[i].Render();
        std::cout << "\n";
    }

    for (int i = 0; i < 20; ++i)
    {
        Entity enemy;
        enemy.Initialize(enemyTexturePath);
        myEntities.PushBack(enemy);
    }

    for (std::size_t i = 0; i < myEntities.Size(); ++i)
    {
        myEntities[i].Update();
    }

    // Sort by closest to origin
    std::function<bool(const Entity&, const Entity&)> sortByDistance2 = [](const Entity& a, const Entity& b)
        {
            Vector2 posA = a.GetPosition();
            Vector2 posB = b.GetPosition();
            float distA = (posA.x * posA.x) + (posA.y * posA.y);
            float distB = (posB.x * posB.x) + (posB.y * posB.y);
            return distA > distB;
        };

    Globals::BubbleSort(myEntities, sortByDistance2);

    for (int i = 0; i < 20; ++i)
    {
        Entity enemy;
        enemy.Initialize(enemyTexturePath);
        myEntities.PushBack(enemy);
    }

    for (std::size_t i = 0; i < myEntities.Size(); ++i)
    {
        myEntities[i].Update();
    }

    // Sort by closest to origin
    std::function<bool(const Entity&, const Entity&)> sortByDistance3 = [](const Entity& a, const Entity& b)
        {
            Vector2 posA = a.GetPosition();
            Vector2 posB = b.GetPosition();
            float distA = (posA.x * posA.x) + (posA.y * posA.y);
            float distB = (posB.x * posB.x) + (posB.y * posB.y);
            return distA > distB;
        };

    Globals::BubbleSort(myEntities, sortByDistance3);

    for (int i = 0; i < 20; ++i)
    {
        Entity enemy;
        enemy.Initialize(enemyTexturePath);
        myEntities.PushBack(enemy);
    }

    for (std::size_t i = 0; i < myEntities.Size(); ++i)
    {
        myEntities[i].Update();
    }

    // Sort by closest to origin
    std::function<bool(const Entity&, const Entity&)> sortByDistance4 = [](const Entity& a, const Entity& b)
        {
            Vector2 posA = a.GetPosition();
            Vector2 posB = b.GetPosition();
            float distA = (posA.x * posA.x) + (posA.y * posA.y);
            float distB = (posB.x * posB.x) + (posB.y * posB.y);
            return distA > distB;
        };

    Globals::BubbleSort(myEntities, sortByDistance4);

    for (std::size_t i = 0; i < myEntities.Size(); ++i)
    {
        myEntities[i].Render();
        std::cout << "\n";
    }

}
void Assignment5()
{
    // Homework assignment 5
    class KeyItem
    {
    public:
        void Add(int amount)
        {
            mCount += amount;
        }
        void Consume(int amount)
        {
            mCount -= amount;
        }
        int GetCount() const
        {
            return mCount;
        }
        void Print() const
        {
            std::cout << mName << ": " << mCount << "\n";
        }
    private:
        std::string mName;
        int mCount = 0;
    };

    class Inventory
    {
    public:
        Inventory* Get()
        {
            static Inventory instance;
            return &instance;
        }
        void PickupKey(const std::string& keyName, int amount)
        {
            if (mKeys.Has(keyName))
            {
                std::cout << "This key already exists, adding " << amount << " to it.\n";
                mKeys[keyName].Add(amount);
            }
            else
            {
                KeyItem newKey;
                newKey.Add(amount);
                mKeys.Insert(keyName, newKey);
            }
        }
        void UseKey(const std::string& keyName, int amount)
        {
            if (mKeys.Has(keyName))
            {
                mKeys[keyName].Consume(amount);  // Decrease the count

                if (mKeys[keyName].GetCount() <= 0)  // If count hits 0, remove it
                {
                    mKeys.Remove(keyName);
                }
            }
        }
        void ObtainKeys(Vector<std::string>& outKeys)
        {
            mKeys.ObtainKeys(outKeys);
        }

        int GetKeyCount(const std::string& keyName)
        {
            if (mKeys.Has(keyName))
            {
                return mKeys[keyName].GetCount();
            }
            return 0;
        }

        bool Has(const std::string& keyName)
        {
            return mKeys.Has(keyName);
        }
    private:
        Map<std::string, KeyItem> mKeys;
    };

    // main code 
    srand(time(0));
    Inventory inventory;
    Vector<std::string> mKeyNames;
    for (int i = 0; i < 20; ++i)
    {
        mKeyNames.PushBack("Key" + std::to_string(i));
    }

    // Add 100 random keys using names from the vector
    for (int i = 0; i < 100; i++)
    {
        int randomIndex = rand() % mKeyNames.Size(); // pick a random index
        std::string randomKey = mKeyNames[randomIndex]; // get the name from the vector
        inventory.PickupKey(randomKey, 1); // PickupKey handles creating the KeyItem internally
    }

    // Obtain all keys and print their names and counts
    Vector<std::string> ownedKeys;
    inventory.ObtainKeys(ownedKeys);

    for (int i = 0; i < ownedKeys.Size(); i++)
    {
        std::string keyName = ownedKeys[i];
        int count = inventory.GetKeyCount(keyName);
        std::cout << "Key: " << keyName << " | Count: " << count << "\n";
    }

    int doorsUnlocked = 0;
    int failedAttempts = 0;

    int choice = 0;
    while (true)
    {
        std::cout << "\n--- Adventure Menu ---\n";
        std::cout << "1. Open a door\n";
        std::cout << "2. Pick up a key\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            // Pick a random door that needs a random key
            int randomIndex = rand() % mKeyNames.Size();
            std::string requiredKey = mKeyNames[randomIndex];

            std::cout << "You arrive at a door and need a " << requiredKey << "\n";

            if (inventory.Has(requiredKey))
            {
                std::cout << "You have the " << requiredKey << " and have unlocked the door!\n";
                inventory.UseKey(requiredKey, 1);
                doorsUnlocked++;
            }
            else
            {
                std::cout << "You do not have the " << requiredKey << ", the door will remain locked.\n";
                failedAttempts++;
            }
        }
        else if (choice == 2)
        {
            int randomIndex = rand() % mKeyNames.Size();
            std::string randomKey = mKeyNames[randomIndex];
            inventory.PickupKey(randomKey, 1);

            std::cout << "You picked up a " << randomKey << "!\n";
            std::cout << "Total count of " << randomKey << ": " << inventory.GetKeyCount(randomKey) << "\n";
        }
        else if (choice == 3)
        {
            std::cout << "\n--- Game Over ---\n";

            // Print all owned keys and counts
            Vector<std::string> ownedKeys;
            inventory.ObtainKeys(ownedKeys);

            if (ownedKeys.Size() == 0)
            {
                std::cout << "You have no keys remaining.\n";
            }
            else
            {
                std::cout << "Keys remaining in inventory:\n";
                for (int i = 0; i < ownedKeys.Size(); i++)
                {
                    std::string keyName = ownedKeys[i];
                    std::cout << "  " << keyName << " | Count: " << inventory.GetKeyCount(keyName) << "\n";
                }
            }

            std::cout << "Doors unlocked: " << doorsUnlocked << "\n";
            std::cout << "Failed unlock attempts: " << failedAttempts << "\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice, please enter 1, 2, or 3.\n";
        }
    }
}

// Assignment 6 
void Assignment6()
{
    enum Stats
    {
        Health,
        Attack,
        Speed,
        AttackCount,
        Count
    };

    class Player
    {
    public:
        void Initialize(const std::string& name)
        {
            mName = name;

            mStats[static_cast<std::size_t>(Stats::Health)] = 100;
            mStats[static_cast<std::size_t>(Stats::Attack)] = 5 + (rand() % 16); // random 5 to 20
            mStats[static_cast<std::size_t>(Stats::Speed)] = 5 + (rand() % 16); // random 5 to 20
            mStats[static_cast<std::size_t>(Stats::AttackCount)] = 1;
        }

        int GetStat(Stats stat) const
        {
            return mStats[static_cast<std::size_t>(stat)];
        }

        void SetStat(Stats stat, int value)
        {
            mStats[static_cast<std::size_t>(stat)] = value;
        }

        bool IsAlive() const
        {
            return mStats[static_cast<std::size_t>(Stats::Health)] > 0;
        }

        const std::string& GetName() const
        {
            return mName;
        }
    private:
        std::string mName;
        Array<int, static_cast<std::size_t>(Stats::Count)> mStats;

    };

    class Team
    {
    public:
        void Initialize(const std::string& teamName, int numPlayers)
        {
            mTeamName = teamName;
            mPlayers.Resize(numPlayers);
            for (int i = 0; i < numPlayers; ++i)
            {
                mPlayers[i].Initialize(mTeamName + "-Player" + std::to_string(i));  // teamName-Player1
            }
        }

        Player* GetNextBattlingPlayer()
        {
            Player* fastestPlayer = nullptr;
            for (std::size_t i = 0; i < mPlayers.Size(); ++i)
            {
                Player& player = mPlayers[i];
                if (!player.IsAlive() || player.GetStat(Stats::AttackCount) <= 0)
                {
                    continue;
                }
                if (fastestPlayer == nullptr || player.GetStat(Stats::Speed) > fastestPlayer->GetStat(Stats::Speed))
                {
                    fastestPlayer = &player;
                }
            }
            return fastestPlayer;
        }

        void DamagePlayer(Player* attacker)
        {
            if (attacker == nullptr)
            {
                return;
            }

            Vector<int> livingPlayers;
            for (std::size_t i = 0; i < mPlayers.Size(); ++i)
            {
                if (mPlayers[i].IsAlive())
                {
                    livingPlayers.PushBack(static_cast<int>(i));
                }
            }

            if (livingPlayers.Size() == 0)
            {
                attacker->SetStat(Stats::AttackCount, 0);
                return;
            }

            int randomIndex = livingPlayers[rand() % livingPlayers.Size()];
            Player& target = mPlayers[randomIndex];
            int damage = attacker->GetStat(Stats::Attack);
            int newHealth = target.GetStat(Stats::Health) - damage;
            target.SetStat(Stats::Health, std::max(0, newHealth));

            attacker->SetStat(Stats::AttackCount, attacker->GetStat(Stats::AttackCount) - 1);

            if ((rand() % 100) < 25)
            {
                int newSpeed = target.GetStat(Stats::Speed) - 10;
                target.SetStat(Stats::Speed, std::max(1, newSpeed));
            }

            if ((rand() % 100) < 10)
            {
                int newSpeed = attacker->GetStat(Stats::Speed) + 5;
                attacker->SetStat(Stats::Speed, std::min(50, newSpeed));
            }
        }

        int GetRemainingPlayers() const
        {
            int count = 0;
            for (std::size_t i = 0; i < mPlayers.Size(); ++i)
            {
                if (mPlayers[i].IsAlive())
                {
                    ++count;
                }
            }
            return count;
        }

        void OrderPlayers()
        {
            auto order = [](const Player& a, const Player& b) -> bool
                {
                    int speedA = (a.GetStat(Stats::AttackCount) <= 0 || !a.IsAlive()) ? 0 : a.GetStat(Stats::Speed);
                    int speedB = (b.GetStat(Stats::AttackCount) <= 0 || !b.IsAlive()) ? 0 : b.GetStat(Stats::Speed);
                    return speedB < speedA;
                };

            Globals::IntroSort(mPlayers.Begin(), mPlayers.End(), order);
        }

        void StartTurn()
        {
            for (std::size_t i = 0; i < mPlayers.Size(); ++i)
            {
                if (mPlayers[i].IsAlive())
                {
                    mPlayers[i].SetStat(Stats::AttackCount, 1);
                }
            }
            OrderPlayers();
        }

        const std::string& GetName() const
        {
            return mTeamName;
        }

        Vector<Player>& GetPlayers()
        {
            return mPlayers;
        }
    private:
        std::string mTeamName;
        Vector<Player> mPlayers;
    };
    // main code
    Team teamOne;
    Team teamTwo;
    teamOne.Initialize("Team One", 10);
    teamTwo.Initialize("Team Two", 10);


    std::cout << "BATTLE STARTS NOW!\n\n";

    int turnNumber = 0;

    while (teamOne.GetRemainingPlayers() > 0 && teamTwo.GetRemainingPlayers() > 0)
    {
        ++turnNumber;
        std::cout << "<--- Turn " << turnNumber << " --->\n";
        std::cout << teamOne.GetName() << " remaining: " << teamOne.GetRemainingPlayers() << " |vs| " << teamTwo.GetName() << " remaining: " << teamTwo.GetRemainingPlayers() << "\n";
        std::cout << "\n\n";

        teamOne.StartTurn();
        teamTwo.StartTurn();

        bool anyoneCanAttack = true;
        while (anyoneCanAttack && teamOne.GetRemainingPlayers() > 0 && teamTwo.GetRemainingPlayers() > 0)
        {
            Player* playerA = teamOne.GetNextBattlingPlayer();
            Player* playerB = teamTwo.GetNextBattlingPlayer();

            anyoneCanAttack = (playerA != nullptr || playerB != nullptr);
            if (!anyoneCanAttack)
            {
                break;
            }

            bool oneGoesFirst = false;
            if (playerA != nullptr && playerB != nullptr)
            {
                int speedA = playerA->GetStat(Stats::Speed);
                int speedB = playerB->GetStat(Stats::Speed);

                if (speedA == speedB)
                {
                    oneGoesFirst = (rand() % 2) == 0;
                }
                else
                {
                    oneGoesFirst = speedA > speedB;
                }
            }
            else
            {
                oneGoesFirst = (playerA != nullptr);
            }

            if (oneGoesFirst && playerA != nullptr)
            {
                int remainingBefore = teamTwo.GetRemainingPlayers();
                std::cout << "[" << teamOne.GetName() << "] " << playerA->GetName()
                    << " (SPEED:" << playerA->GetStat(Stats::Speed)
                    << " ATTACK:" << playerA->GetStat(Stats::Attack) << ") attacks "
                    << teamTwo.GetName() << "!\n";

                teamTwo.DamagePlayer(playerA);

                int remainingAfter = teamTwo.GetRemainingPlayers();

                if (remainingAfter < remainingBefore)
                {
                    std::cout << "  >> One of " << teamTwo.GetName() << " players was eliminated! (" << remainingAfter << " remaining)\n";
                }

                else
                {
                    std::cout << "  >> Hit! " << teamTwo.GetName() << " still has " << remainingAfter << " players standing.\n";
                }
            }
            else if (!oneGoesFirst && playerB != nullptr)
            {
                int remainingBefore = teamOne.GetRemainingPlayers();
                std::cout << "[" << teamTwo.GetName() << "] " << playerB->GetName()
                    << " (SPEED:" << playerB->GetStat(Stats::Speed)
                    << " ATTACK:" << playerB->GetStat(Stats::Attack) << ") attacks "
                    << teamOne.GetName() << "!\n";

                teamOne.DamagePlayer(playerB);

                int remainingAfter = teamOne.GetRemainingPlayers();

                if (remainingAfter < remainingBefore)
                {
                    std::cout << "  >> One of " << teamOne.GetName() << " players was eliminated! (" << remainingAfter << " remaining)\n";
                }

                else
                {
                    std::cout << "  >> Hit! " << teamOne.GetName() << " still has " << remainingAfter << " players standing.\n";
                }
            }

            teamOne.OrderPlayers();
            teamTwo.OrderPlayers();
        }

        std::cout << "\n";
    }

    std::cout << "RING RING RING! BATTLE OVER\n";

    if (teamOne.GetRemainingPlayers() > 0 && teamTwo.GetRemainingPlayers() <= 0)
    {
        std::cout << teamOne.GetName() << " WINS with " << teamOne.GetRemainingPlayers() << " players remaining!\n";
    }
    else if (teamTwo.GetRemainingPlayers() > 0 && teamOne.GetRemainingPlayers() <= 0)
    {
        std::cout << teamTwo.GetName() << " WINS with " << teamTwo.GetRemainingPlayers() << " players remaining!\n";
    }
    else
    {
        std::cout << "It's a DRAW! Both teams have been eliminated, better luck next time teams" << "\n";
    }
}

void MSTGraphClass()
{
     std::cout << "Coustom MST:\n";
// a, b, c, d, e
Vector<std::string> nodes;
nodes.PushBack("A");
nodes.PushBack("B");
nodes.PushBack("C");
nodes.PushBack("D");
nodes.PushBack("E");

// using Prims Algoritm
MSTGraph<std::string, int> mstGraphPA;
for (std::size_t i = 0; i < nodes.Size(); ++i)
{
    mstGraphPA.AddItem(&nodes[i]);
}
// link all the nodes edges
mstGraphPA.AddEdge(0, 1, 9);
mstGraphPA.AddEdge(0, 2, 5);
mstGraphPA.AddEdge(0, 3, 2);
mstGraphPA.AddEdge(1, 3, 6);
mstGraphPA.AddEdge(1, 4, 5);
mstGraphPA.AddEdge(2, 3, 4);
mstGraphPA.AddEdge(2, 4, 5);
mstGraphPA.AddEdge(3, 4, 4);

mstGraphPA.GenerateMST(0);

std::cout << "MST:\n";
const Vector<MSTGraph<std::string, int>::Edge>& mstEdge = mstGraphPA.GetMST();
for (std::size_t i = 0; i < mstEdge.Size(); ++i)
{
    std::cout << nodes[mstEdge[i].fromIndex] << "-" << nodes[mstEdge[i].toIndex] << " ";
}

std::cout << "\n";
std::cout << "\n";
std::cout << "Kruskal's MST:\n";
MSTGraphK<int> mstGraphKA;
mstGraphKA.AddEdge(0, 1, 9);
mstGraphKA.AddEdge(0, 2, 5);
mstGraphKA.AddEdge(0, 3, 2);
mstGraphKA.AddEdge(1, 3, 6);
mstGraphKA.AddEdge(1, 4, 5);
mstGraphKA.AddEdge(2, 3, 4);
mstGraphKA.AddEdge(2, 4, 5);
mstGraphKA.AddEdge(3, 4, 4);
mstGraphKA.GenerateMST();
const Vector<MSTGraphK<int>::Edge>& mstEdgesK = mstGraphKA.GetMST();
for (std::size_t i = 0; i < mstEdgesK.Size(); ++i)
{
    std::cout << nodes[mstEdgesK[i].fromNode] << "-" << nodes[mstEdgesK[i].toNode] << " ";
}

}

// Assignment 7
void Assignment7()
{
    class House
    {
    public:
        House(const std::string& name, const Vector2& pos)
            : mName(name), mPosition(pos)
        {

        }
        House()
        {

        }
        std::string GetName() const
        {
            return mName;
        }
        Vector2 GetPosition() const
        {
            return mPosition;
        }
    private:
        std::string mName;
        Vector2 mPosition;
    };

    class City
    {
    public:
        void AddHouse(const std::string& name, const Vector2& pos)
        {
            // goes through mHouses and see if the house is already taken or not
            for (std::size_t i = 0; i < mHouses.Size(); ++i)
            {
                if (name == mHouses[i].GetName() || pos == mHouses[i].GetPosition())
                {
                    std::cout << "This house is already taken.\n";
                    return;
                }
            }
            // push back the new houses
            House newHouse(name, pos);
            mHouses.PushBack(newHouse);
        }

        void ConnectAllHouses()
        {
            // go through all the houses and add them as a node of mHouseGraph using .AddItem
            for (std::size_t i = 0; i < mHouses.Size(); ++i)
            {
                mHousesGraph.AddItem(&mHouses[i]);
            }

            // go through all the houses and add a i and j value and also get the distance between them and use it as the weight
            for (std::size_t i = 0; i < mHouses.Size(); ++i)
            {
                for (std::size_t j = i + 1; j < mHouses.Size(); ++j)
                {
                    float distance = mHouses[i].GetPosition().Distance(mHouses[j].GetPosition());
                    mHouseEdgesGraph.AddEdge(i, j, distance);
                    mHousesGraph.AddEdge(i, j, distance, true);
                }
            }
        }

        float GetTotalRoadDistancePrim()
        {
            // return the MST from mHousesGraph using Prim's algorithm
            mHousesGraph.GenerateMST(0);
            const auto& mstEdges = mHousesGraph.GetMST();

            // sum up the weights for the total road dinstance 
            float totalDistance = 0.0f;
            for (std::size_t i = 0; i < mstEdges.Size(); ++i)
            {
                totalDistance += mstEdges[i].weight;
            }

            // finally return the total distance calculated
            return totalDistance;
        }

        float GetToalRoadDistanceKruskal()
        {
            // same code as before but this time we use MSTGraphK functions instead of MSTGraph
            mHouseEdgesGraph.GenerateMST();
            const auto& mstEdges = mHouseEdgesGraph.GetMST();

            float totalDistance = 0.0f;
            for (std::size_t i = 0; i < mstEdges.Size(); ++i)
            {
                totalDistance += mstEdges[i].weight;
            }

            // finally return the total distance calculated
            return totalDistance;
        }

        void PrintMST()
        {
            std::cout << "=== Prim's Connections ===\n";
            const auto& primEdges = mHousesGraph.GetMST();
            for (std::size_t i = 0; i < primEdges.Size(); ++i)
            {
                std::cout << mHouses[primEdges[i].fromIndex].GetName()
                    << " -> "
                    << mHouses[primEdges[i].fromIndex].GetName()
                    << " | Distance: " << primEdges[i].weight << "m\n";
            }
        }
    private:
        Vector<House> mHouses;
        MSTGraph<House, float> mHousesGraph;
        MSTGraphK<float> mHouseEdgesGraph;
    };

    // main code

     // Create a City
    City city;

    // Populate the city with the houses from the diagram :O
    city.AddHouse("A", Vector2(20.0f, 40.0f));
    city.AddHouse("B", Vector2(50.0f, 20.0f));
    city.AddHouse("C", Vector2(90.0f, 40.0f));
    city.AddHouse("D", Vector2(60.0f, 80.0f));
    city.AddHouse("E", Vector2(30.0f, 120.0f));
    city.AddHouse("F", Vector2(100.0f, 110.0f));
    city.AddHouse("G", Vector2(150.0f, 130.0f));
    city.AddHouse("H", Vector2(160.0f, 90.0f));
    city.AddHouse("I", Vector2(140.0f, 60.0f));
    city.AddHouse("J", Vector2(180.0f, 30.0f));
    city.AddHouse("K", Vector2(200.0f, 120.0f));
    city.AddHouse("L", Vector2(220.0f, 70.0f));
    city.AddHouse("M", Vector2(240.0f, 50.0f));

    // Connect all houses
    city.ConnectAllHouses();

    // Print MST connections for both
    city.PrintMST();

    // Print total cost for both (should be the same)
    float primDistance = city.GetTotalRoadDistancePrim();
    std::cout << "\n=== Prim's ===\n";
    std::cout << "Total distance: " << primDistance << " meters\n";
    std::cout << "Total cost: $" << primDistance * 10.0f << "\n";

    float kruskalDistance = city.GetToalRoadDistanceKruskal();
    std::cout << "\n=== Kruskal's ===\n";
    std::cout << "Total distance: " << kruskalDistance << " meters\n";
    std::cout << "Total cost: $" << kruskalDistance * 10.0f << "\n";

    std::cout << "\nBoth methods match: " << (primDistance == kruskalDistance ? "YES" : "NO") << "\n";

}

// Assignment 8
class City
{
public:
    City(std::string name, Vector2 positon)
        :mName(name), mPosition(positon)
    {

    }

    City()
    {

    }

    std::string GetName() const
    {
        return mName;
    }

    Vector2 GetPosition() const
    {
        return mPosition;
    }
private:
    std::string mName;
    Vector2 mPosition;
};

class GPS
{
public:
    ~GPS()
    {
        for (std::size_t i = 0; i < mCities.Size(); ++i)
        {
            delete mCities[i];
        }
        mCities.Clear();
    }

    void AddCity(const std::string& name, const Vector2& pos)
    {
        for (std::size_t i = 0; i < mCities.Size(); ++i)
        {
            if (name == mCities[i]->GetName() || pos == mCities[i]->GetPosition())
            {
                std::cout << "This city already exist\n";
                return;
            }
        }
        City* newCity = new City(name, pos);
        mCities.PushBack(newCity);
        mCityGraph.AddItem(mCities[mCities.Size() - 1]);
    }

    void ConnectCities(const City* a, const City* b)
    {
        std::size_t cityA = 0;
        std::size_t cityB = 0;
        bool foundA = false;
        bool foundB = false;
        for (std::size_t i = 0; i < mCities.Size(); ++i)
        {
            if (a->GetPosition() == mCities[i]->GetPosition())
            {
                cityA = i;
                foundA = true;
            }
            if (b->GetPosition() == mCities[i]->GetPosition())
            {
                cityB = i;
                foundB = true;
            }
        }
        if (!foundA || !foundB)
        {
            std::cout << "Invalid cities\n";
            return;
        }
        float weight = a->GetPosition().Distance(b->GetPosition());
        mCityGraph.AddEdge(cityA, cityB, weight);
    }

    float FindPath(const City* from, const City* to, Vector<const City*>& pathOutput)
    {
        int startIndex = -1;
        int endIndex = -1;
        for (int i = 0; i < (int)mCities.Size(); ++i)
        {
            if (mCities[i]->GetPosition() == from->GetPosition())
            {
                startIndex = i;
            }
            if (mCities[i]->GetPosition() == to->GetPosition())
            {
                endIndex = i;
            }
        }
        if (startIndex == -1 || endIndex == -1)
        {
            return -1.0f;
        }

        return mCityGraph.GetPath(startIndex, endIndex, pathOutput);
    }

    const City* GetCity(const std::string& name) const
    {
        for (std::size_t i = 0; i < mCities.Size(); ++i)
        {
            if (mCities[i]->GetName() == name)
            {
                return mCities[i];
            }
        }
        return nullptr;
    }

private:
    Vector<City*> mCities;
    WeightedGraph<City, float> mCityGraph;
};
int main()
{
    GPS gps;

    // b. Populate cities
    gps.AddCity("Powel River", { 420, 605 });
    gps.AddCity("Vancouver", { 475, 635 });
    gps.AddCity("Abbotsford", { 505, 650 });
    gps.AddCity("Penticton", { 600, 615 });
    gps.AddCity("Kelowna", { 603, 593 });
    gps.AddCity("Kamloops", { 570, 555 });
    gps.AddCity("Nelson", { 685, 608 });
    gps.AddCity("Creston", { 715, 625 });
    gps.AddCity("Cranbrook", { 740, 598 });
    gps.AddCity("Revelstoke", { 642, 526 });
    gps.AddCity("Lillooet", { 512, 556 });
    gps.AddCity("Prince George", { 447, 376 });
    gps.AddCity("Burns Lake", { 375, 362 });
    gps.AddCity("Smithers", { 330, 330 });
    gps.AddCity("Terrace", { 285, 345 });
    gps.AddCity("Prince Rupert", { 227, 352 });
    gps.AddCity("Dawson Creek", { 550, 268 });
    gps.AddCity("Fort St. John", { 530, 243 });
    gps.AddCity("Fort Nelson", { 470, 102 });
    gps.AddCity("Dease Lake", { 250, 120 });
    gps.AddCity("Williams Lake", { 500, 475 });
    gps.AddCity("Quesnel", { 485, 430 });

    // Connect cities (edges based on geographic proximity/roads)
    gps.ConnectCities(gps.GetCity("Vancouver"), gps.GetCity("Abbotsford"));
    gps.ConnectCities(gps.GetCity("Vancouver"), gps.GetCity("Powel River"));
    gps.ConnectCities(gps.GetCity("Vancouver"), gps.GetCity("Kamloops"));
    gps.ConnectCities(gps.GetCity("Abbotsford"), gps.GetCity("Penticton"));
    gps.ConnectCities(gps.GetCity("Penticton"), gps.GetCity("Kelowna"));
    gps.ConnectCities(gps.GetCity("Penticton"), gps.GetCity("Creston"));
    gps.ConnectCities(gps.GetCity("Kelowna"), gps.GetCity("Kamloops"));
    gps.ConnectCities(gps.GetCity("Kelowna"), gps.GetCity("Revelstoke"));
    gps.ConnectCities(gps.GetCity("Kamloops"), gps.GetCity("Lillooet"));
    gps.ConnectCities(gps.GetCity("Kamloops"), gps.GetCity("Revelstoke"));
    gps.ConnectCities(gps.GetCity("Kamloops"), gps.GetCity("Williams Lake"));
    gps.ConnectCities(gps.GetCity("Revelstoke"), gps.GetCity("Cranbrook"));
    gps.ConnectCities(gps.GetCity("Revelstoke"), gps.GetCity("Nelson"));
    gps.ConnectCities(gps.GetCity("Nelson"), gps.GetCity("Creston"));
    gps.ConnectCities(gps.GetCity("Nelson"), gps.GetCity("Cranbrook"));
    gps.ConnectCities(gps.GetCity("Creston"), gps.GetCity("Cranbrook"));
    gps.ConnectCities(gps.GetCity("Lillooet"), gps.GetCity("Powel River"));
    gps.ConnectCities(gps.GetCity("Lillooet"), gps.GetCity("Williams Lake"));
    gps.ConnectCities(gps.GetCity("Williams Lake"), gps.GetCity("Quesnel"));
    gps.ConnectCities(gps.GetCity("Williams Lake"), gps.GetCity("Prince George"));
    gps.ConnectCities(gps.GetCity("Quesnel"), gps.GetCity("Prince George"));
    gps.ConnectCities(gps.GetCity("Prince George"), gps.GetCity("Burns Lake"));
    gps.ConnectCities(gps.GetCity("Prince George"), gps.GetCity("Dawson Creek"));
    gps.ConnectCities(gps.GetCity("Burns Lake"), gps.GetCity("Smithers"));
    gps.ConnectCities(gps.GetCity("Smithers"), gps.GetCity("Terrace"));
    gps.ConnectCities(gps.GetCity("Smithers"), gps.GetCity("Dease Lake"));
    gps.ConnectCities(gps.GetCity("Terrace"), gps.GetCity("Prince Rupert"));
    gps.ConnectCities(gps.GetCity("Dease Lake"), gps.GetCity("Fort Nelson"));
    gps.ConnectCities(gps.GetCity("Dawson Creek"), gps.GetCity("Fort St. John"));
    gps.ConnectCities(gps.GetCity("Fort St. John"), gps.GetCity("Fort Nelson"));

    // d. Find and print paths
    const float speed = 80.0f; 

    auto PrintPath = [&](const std::string& fromName, const std::string& toName)
        {
            Vector<const City*> path;
            float distance = gps.FindPath(gps.GetCity(fromName), gps.GetCity(toName), path);

            std::cout << "\nRoute: " << fromName << " -> " << toName << "\n";
            std::cout << "Path: ";
            for (int i = path.Size() - 1; i >= 0; --i)
            {
                std::cout << path[i]->GetName();
                if (i > 0) std::cout << " -> ";
            }
            std::cout << "\n";
            std::cout << "Total Distance: " << distance << " km\n";

            // e. Print estimated travel time
            float hours = distance / speed;
            int h = (int)hours;
            int m = (int)((hours - h) * 60);
            std::cout << "Estimated Duration: " << h << "h " << m << "m\n";
        };

    PrintPath("Vancouver", "Cranbrook");   // d.i
    PrintPath("Prince Rupert", "Kelowna");   // d.ii
    PrintPath("Fort Nelson", "Creston");     // d.iii


    // :) last homework 

    return 0;
}
