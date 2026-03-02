#include <iostream>
#include <array>
#include <vector>
#include <string>

const int MAX_HASH_SIZE = 20;
int HashFunction(int key)
{
    return key % MAX_HASH_SIZE;
}

struct Node
{
    int key;    // is the id used to obtain hash value
    int data;   // data stored in the node
    Node* next; // stores copes of objects that share the same index
};

std::array<Node*, MAX_HASH_SIZE> hashTable = { nullptr };

void Insert(int key, int data)
{
    int index = HashFunction(key);
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = data;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    std::cout << "Insert " << key << " : " << data << " : " << index << "\n";
}

int Search(int key)
{
    int index = HashFunction(key);
    Node* foundNode = hashTable[index];
    while (foundNode != nullptr)
    {
        if (foundNode->key == key)
        {
            return foundNode->data;
        }
        foundNode = foundNode->next;
    }
    return -1;
}

void Delete(int key)
{
    int index = HashFunction(key);
    Node* node = hashTable[index];
    Node* prev = nullptr;
    while (node != nullptr)
    {
        if (node->key == key)
        {
            if (prev != nullptr)
            {
                prev->next = node->next;
            }
            else
            {
                hashTable[index] = node->next;
            }
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
    std::cout << "Printing Hash Table Size: " << MAX_HASH_SIZE << "\n\n";
    for (int i = 0; i < MAX_HASH_SIZE; ++i)
    {
        if (hashTable[i] != nullptr)
        {
            Node* node = hashTable[i];
            while (node != nullptr)
            {
                std::cout << node->data << "\n";
                node = node->next;
            }
            std::cout << hashTable[i]->data << "\n";
        }
    }
}

int main()
{
   /* Create a class called Texture
        • Have an array of floats for pixel colors
        • Create it with size, initialize array with size* size * 4
        o Width, Height, and RGBA
        • Create a hash table array that will store the textures
        • Create 100 of textures and add them to the hash table, using their
        name as the key(store the hash value)
        • Iterate through the hash values and print the name of each texture*/

    std::cout << "Working with Hash Tables and Sorting";
    Insert(1, rand() % 100);
    Insert(2, rand() % 100);
    Insert(4, rand() % 100);
    Insert(15, rand() % 100);
    Insert(22, rand() % 100);
    Insert(30, rand() % 100);
    Insert(36, rand() % 100);

    Print();

    Delete(2);

    Print();
}
