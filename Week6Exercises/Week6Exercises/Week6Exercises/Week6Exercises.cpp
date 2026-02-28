// Week6Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <set>
//const int MAX_HASH_SIZE = 20;
//int HashFunction(int key)
//{
//    return key % MAX_HASH_SIZE;
//}
//struct Node
//{
//    int key;    // is the id used to obtain hash value
//    int data;   // data stored in the node
//    Node* next; // stores copies of objects that share the same index
//};
//std::array<Node*, MAX_HASH_SIZE> hashTable = { nullptr };
//void Insert(int key, int data)
//{
//    int index = HashFunction(key);
//    Node* tmp = hashTable[index];
//    while (tmp != nullptr)
//    {
//        if (tmp->key == key)
//        {
//            std::cout << "Key " << key << " is already added!\n";
//            return;
//        }
//        tmp = tmp->next;
//    }
//    Node* newNode = new Node();
//    newNode->key = key;
//    newNode->data = data;
//    newNode->next = hashTable[index];
//    hashTable[index] = newNode;
//    std::cout << "Insert " << key << " : " << data << " : " << index << "\n";
//}
//int Search(int key)
//{
//    int index = HashFunction(key);
//    Node* foundNode = hashTable[index];
//    while (foundNode != nullptr)
//    {
//        if (foundNode->key == key)
//        {
//            return foundNode->data;
//        }
//        foundNode = foundNode->next;
//    }
//    return -1;
//}
//void Delete(int key)
//{
//    int index = HashFunction(key);
//    Node* node = hashTable[index];
//    Node* prev = nullptr;
//    while (node != nullptr)
//    {
//        if (node->key == key)
//        {
//            if (prev != nullptr)
//            {
//                prev->next = node->next; // ====/   \=== stitching linked list in the middle
//            }
//            else
//            {
//                hashTable[index] = node->next; // new root/=====
//            }
//            delete node;
//            node = nullptr;
//            break;
//        }
//        prev = node;
//        node = node->next;
//    }
//}
//void Print()
//{
//    std::cout << "Printing Hash Table Size: " << MAX_HASH_SIZE << "\n";
//    for (int i = 0; i < MAX_HASH_SIZE; ++i)
//    {
//        if (hashTable[i] != nullptr)
//        {
//            Node* node = hashTable[i];
//            while (node != nullptr)
//            {
//                std::cout << node->data << " index (" << i << ")\n";
//                node = node->next;
//            }
//        }
//    }
//}
//void Exercise1PracticeHashTable()
//{
//    std::cout << "Working with Hash Tables and Sorting\n";
//    Insert(1, rand() % 100);
//    Insert(2, rand() % 100);
//    Insert(4, rand() % 100);
//    Insert(15, rand() % 100);
//    Insert(22, rand() % 100);
//    Insert(30, rand() % 100);
//    Insert(36, rand() % 100);
//
//    Print();
//
//    Delete(2);
//
//    Print();
//}

class Texture
{
public:
    Texture() : mPixelColors(nullptr) {}
    ~Texture()
    {
        if (mPixelColors != nullptr)
        {
            delete[] mPixelColors;
            mPixelColors = nullptr;
        }
    }
    void Initialize(const std::string& filePath, int size)
    {
        mFilePath = filePath;
        mPixelColors = new float[size * size * 4];
    }
    const std::string& GetFilePath() const
    {
        return mFilePath;
    }

private:
    std::string mFilePath = "";
    float* mPixelColors = nullptr;
};
struct Node
{
    Texture* data;
    Node* next;
};
const int MAX_HASH_SIZE = 1000;
std::array<Node*, MAX_HASH_SIZE> HashTable = { nullptr };
int HashFunction(const std::string& key)
{
    int hashValue = 0;
    for (int i = 0; i < key.size(); ++i)
    {
        int value = (int)key[i];
        hashValue = (hashValue * 256 + value) % MAX_HASH_SIZE;
    }
    return hashValue;
}
void InsertTexture(const std::string& filePath)
{
    int index = HashFunction(filePath);
    Node* tmp = HashTable[index];
    while (tmp != nullptr)
    {
        if (tmp->data->GetFilePath() == filePath)
        {
            std::cout << "Texture " << filePath << " is already added!\n";
            return;
        }
        tmp = tmp->next;
    }
    Texture* newTexture = new Texture();
    newTexture->Initialize(filePath, 100 + (rand() % 157));
    Node* newNode = new Node();
    newNode->data = newTexture;
    newNode->next = HashTable[index];
    HashTable[index] = newNode;
}
const Texture* FindTexture(const std::string& filePath)
{
    int index = HashFunction(filePath);
    Node* foundNode = HashTable[index];
    while (foundNode != nullptr)
    {
        if (foundNode->data->GetFilePath() == filePath)
        {
            return foundNode->data;
        }
        foundNode = foundNode->next;
    }
    return nullptr;
}
void DeleteTexture(const std::string& filePath)
{
    int index = HashFunction(filePath);
    Node* node = HashTable[index];
    Node* prev = nullptr;
    while (node != nullptr)
    {
        if (node->data->GetFilePath() == filePath)
        {
            if (prev != nullptr)
            {
                prev->next = node->next;
            }
            else
            {
                HashTable[index] = node->next;
            }
            std::cout << "Texture " << filePath << " was deleted\n";
            delete node->data;
            node->data = nullptr;
            delete node;
            node = nullptr;
            break;
        }
        prev = node;
        node = node->next;
    }
}
void Print()
{
    for (int i = 0; i < MAX_HASH_SIZE; ++i)
    {
        Node* node = HashTable[i];
        while (node != nullptr)
        {
            std::cout << i << ") " << node->data->GetFilePath() << "\n";
            node = node->next;
        }
    }
}
std::vector<std::string> directories = {
    "/Models/Textures/",
    "/UI/Textures/",
    "/Gameplay/Textures/",
    "/Environment/Textures/"
};
void HashTableExercise2()
{

    // Create a class called Texture​
    // Have an array of floats for pixel colors​
    // Create it with size, initialize array with size* size * 4​
    // Width, Height, and RGBA​
    // Create a hash table array that will store the textures​
    // Create 100 of textures and add them to the hash table, using their
    // name as the key(store the hash value)​
    // Iterate through the hash values and print the name of each texture

    int maxTextures = 100;
    for (int i = 0; i < maxTextures; ++i)
    {
        int dirIndex = rand() % directories.size();
        std::string fullPath = directories[dirIndex] + "TextureName_" + std::to_string(i);
        InsertTexture(fullPath);
    }
    Print();

    std::cout << "==========================================\n";
    std::cout << "==========================================\n";
    std::string findTexture = "TextureName_" + std::to_string(rand() % 100);
    std::cout << "Find Texture " << findTexture << "\n";
    const Texture* texture = FindTexture(findTexture);
    if (texture != nullptr)
    {
        std::cout << "Texture " << texture->GetFilePath() << " was found!\n";
    }
    else
    {
        std::cout << "Texture " << findTexture << " was not found!!!\n";
    }
    std::cout << "==========================================\n";
    std::cout << "==========================================\n";
    std::cout << "Deleting Textures:\n";
    //for (int i = 0; i < 60; ++i)
    //{
    //    DeleteTexture("TextureName_" + std::to_string(rand() % 100));
    //}
    //Print();
}

// Create a vector with 100 random numbers​
// Print numbers​
// Use a Bubble Sort to sort them from lowest to highest​
// Print numbers
// because they are global functions, they each need their own template
template<typename T>
void Swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
template<typename T>
void BubbleSort(std::vector<T>& values)
{
    int size = values.size();
    // size - 1 because we need at least 2 elements to compare
    for (int i = 0; i < size - 1; ++i)
    {
        //  size - i - 1 because each pass moves the largest to the end plus we need 2 to compare
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (values[j] > values[j + 1])
            {
                Swap(values[j], values[j + 1]);
            }
        }
    }
}
void BubbleSortExample1()
{
    std::cout << "Bubble Sort:\n";
    std::vector<int> myValues;
    for (int i = 0; i < 100; ++i)
    {
        myValues.push_back(rand() % 1000);
        std::cout << myValues.back() << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
    BubbleSort(myValues);
    std::cout << "After Bubble Sort:\n";
    for (int i = 0; i < myValues.size(); ++i)
    {
        std::cout << myValues[i] << " ";
    }
    std::cout << std::endl;
}

class City
{
public:
    City(const std::string& name, int distanceFromHome)
        : mName(name)
        , mDistanceFromHome(distanceFromHome)
    {

    }
    void Print() const
    {
        std::cout << mName << " is " << mDistanceFromHome << "km from home\n";
    }
    bool operator>(const City& rhs)
    {
        return mDistanceFromHome > rhs.mDistanceFromHome;
    }
    bool operator<(const City& rhs)
    {
        return mDistanceFromHome < rhs.mDistanceFromHome;
    }
private:
    std::string mName;
    int mDistanceFromHome;
};
void PrintAllCities(const std::vector<City>& cities)
{
    for (int i = 0; i < cities.size(); ++i)
    {
        cities[i].Print();
    }
}
void BubbleSortExample2()
{
    std::vector<City> citiesNearHome;
    citiesNearHome.push_back(City("Burnaby", 10));
    citiesNearHome.push_back(City("Surrey", 20));
    citiesNearHome.push_back(City("Langley", 60));
    citiesNearHome.push_back(City("Chilliwack", 100));
    citiesNearHome.push_back(City("New_West", 15));
    citiesNearHome.push_back(City("North_Van", 23));
    citiesNearHome.push_back(City("Richmond", 3));
    citiesNearHome.push_back(City("Coquitlam", 12));
    PrintAllCities(citiesNearHome);

    std::cout << "\n\n";
    std::cout << "BubbleSort:\n";
    BubbleSort(citiesNearHome);
    PrintAllCities(citiesNearHome);

}

template<typename T>
void SelectionSort(std::vector<T>& values)
{
    int size = values.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (values[j] < values[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            Swap(values[i], values[minIndex]);
        }
    }
}
void SelectionSortExercise1()
{
    std::cout << "Selection Sort:\n";
    std::vector<int> myValues;
    for (int i = 0; i < 100; ++i)
    {
        myValues.push_back(rand() % 1000);
        std::cout << myValues.back() << " ";
    }
    std::cout << "\n\n";
    std::cout << "Sorted Values:\n";
    SelectionSort(myValues);
    for (int i = 0; i < myValues.size(); ++i)
    {
        std::cout << myValues[i] << " ";
    }
    std::cout << "\n";
}
void SelectionSortExercise2()
{
    std::vector<City> citiesNearHome;
    citiesNearHome.push_back(City("Burnaby", 10));
    citiesNearHome.push_back(City("Surrey", 20));
    citiesNearHome.push_back(City("Langley", 60));
    citiesNearHome.push_back(City("Chilliwack", 100));
    citiesNearHome.push_back(City("New_West", 15));
    citiesNearHome.push_back(City("North_Van", 23));
    citiesNearHome.push_back(City("Richmond", 3));
    citiesNearHome.push_back(City("Coquitlam", 12));
    PrintAllCities(citiesNearHome);

    std::cout << "\n\n";
    std::cout << "BubbleSort:\n";
    SelectionSort(citiesNearHome);
    PrintAllCities(citiesNearHome);
}

void SwapInt(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    return 0;
}

