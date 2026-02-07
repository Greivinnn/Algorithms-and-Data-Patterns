// VGP241Midterm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <stack>

// PART 2 (don't forget the word document for Part 1)
int GetFactorial(int number)
{
    // TODO make this a recursive function that obtains the factorial of the number passed in (eg: 4 = 4 * 3 * 2 * 1 = 24)
    if (number <= 1)
    {
        return 1;
    }

    return number * GetFactorial(number - 1);
}
void Questions1()
{
    std::cout << "Question 1:\n";
    // TODO finish the function above to obtain the factorial of the following numbers
    std::cout << "5! = " << GetFactorial(5) << "\n";
    std::cout << "7! = " << GetFactorial(7) << "\n";
    std::cout << "4! = " << GetFactorial(4) << "\n";
    std::cout << "10! = " << GetFactorial(10) << "\n";
    std::cout << "8! = " << GetFactorial(8) << "\n";
    std::cout << "\n";
}
int StringLength(const char* str)
{
    // TODO return the length of the string

    if (str == nullptr)
    {
        return 0;
    }

    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}
void Questions2()
{
    std::cout << "Question 2:\n";
    // TODO finish the function above to return the length of a string
    std::cout << "The length of 'hello' is " << StringLength("hello") << "\n";
    std::cout << "The length of 'world' is " << StringLength("world") << "\n";
    std::cout << "The length of 'fantastic' is " << StringLength("fantastic") << "\n";
    std::cout << "The length of 'algorithm' is " << StringLength("algorithm") << "\n";
    std::cout << "\n";
}
class Home
{
};
class HomeOwner
{
public:
    HomeOwner()
    {
        mMyHome = new Home();
    }
    // copy constructor
    HomeOwner(const HomeOwner& other)
    {
        mMyHome = new Home(*other.mMyHome);
    }
    HomeOwner& operator=(const HomeOwner& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete mMyHome;
        mMyHome = new Home(*other.mMyHome);
        return *this;
    }
    ~HomeOwner()
    {
        delete mMyHome;
        mMyHome = nullptr;
    }
private:
    Home* mMyHome = nullptr;
};
void Questions3()
{
    std::cout << "Question 3:\n";
    HomeOwner newHomeOwner;
    HomeOwner otherHomeOwner = newHomeOwner;



    // TODO create deep copy capabilities for HoweOwner
    std::cout << "\n";
}
void IsPalendrome(const std::string& word)
{
    // TODO fill out this function and print if the word is a palendrom
    int left = 0;
    int right = word.length() - 1;

    bool isPalindrome = true;

    while (left < right)
    {
        if (word[left] != word[right])
        {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
    {
        std::cout << word << " is a palindrome!\n";
    }
    else
    {
        std::cout << word << " is NOT a palindrome.\n";
    }
}
void Questions4()
{
    std::cout << "Question 4:\n";
    // TODO fill out the function to test if the word is a palendrome
    IsPalendrome("HELLO");
    IsPalendrome("LEVEL");
    IsPalendrome("10110101");
    IsPalendrome("10100101");
    IsPalendrome("TACOCAT");
    std::cout << "\n";
}

struct Car
{
    Car(const std::string& name, int cost, int milage, int tankSize)
        : name(name)
        , cost(cost)
        , milage(milage)
        , gasTankSize(tankSize)
    {

    }
    std::string name;
    int cost;
    int milage;
    int gasTankSize;

    void Print() const
    {
        std::cout << name << " Cost: $" << cost << " : Milage: " << milage << "km : TankSize: " << gasTankSize << "L\n";
    }
};
struct SortByCost
{
    bool operator()(const Car& a, const Car& b) const
    {
        if (a.cost == b.cost)
        {
            return a.cost < b.cost;
        }
        return a.cost > b.cost;
    }
    
};
struct SortByMilage
{
    bool operator()(const Car& a, const Car& b) const
    {
        if (a.milage == b.milage)
        {
            return a.cost < b.cost;
        }
        return a.milage > b.milage;
    }
};
struct SortByTankSize
{
    bool operator()(const Car& a, const Car& b) const
    {
        if (a.gasTankSize == b.gasTankSize)
        {
            return a.cost < b.cost;
        }
        return a.gasTankSize > b.gasTankSize;
    }
};
void Questions5()
{
    std::cout << "Question 5:\n";
    std::vector<Car> cars;
    cars.push_back(Car("Ford", 10000, 65000, 50));
    cars.push_back(Car("Toyota", 9000, 88000, 50));
    cars.push_back(Car("Dodge", 33500, 45000, 72));
    cars.push_back(Car("Prius", 15000, 10000, 50));
    cars.push_back(Car("Subaru", 12000, 101000, 66));
    cars.push_back(Car("Nissan", 14000, 25000, 66));
    cars.push_back(Car("BMW", 50000, 73000, 72));
    std::priority_queue<Car, std::vector<Car>, SortByCost> carsSortedByCost;
    std::priority_queue<Car, std::vector<Car>, SortByMilage> carsSortedByMilage;
    std::priority_queue<Car, std::vector<Car>, SortByTankSize> carsSortedByTankSize;
    for (int i = 0; i < cars.size(); ++i)
    {
        carsSortedByCost.push(cars[i]);
        carsSortedByMilage.push(cars[i]);
        carsSortedByTankSize.push(cars[i]);
    }

    // TODO Fill in the commented out sort functors (between question and the struct Car)
    // add the cars to the priority queues
    // print out each of the queues in the order they are added
    // NOTE: if when sorting, there is a tie in comparison value, sort highest to lowest based on price
    std::cout << "Sorted By Cost:\n";
    // TODO print the cars in carsSortedByCost
    while (!carsSortedByCost.empty())
    {
        carsSortedByCost.top().Print();
        carsSortedByCost.pop();
    }
    // call .Print() for each car

    std::cout << "Sorted By Milage:\n";
    while (!carsSortedByMilage.empty())
    {
        carsSortedByMilage.top().Print();
        carsSortedByMilage.pop();
    }
    // TODO print the cars in carsSortedByMilage  
    // call .Print() for each car

    std::cout << "Sorted By Tank Size:\n";
    while (!carsSortedByTankSize.empty())
    {
        carsSortedByTankSize.top().Print();
        carsSortedByTankSize.pop();
    }
    // TODO print the cars in carsSortedByTankSize  
    // call .Print() for each car

    std::cout << "\n";
}
void AddToNode(std::array<int, 3>& node, std::array<int, 3>& nodeAtLevel, int k)
{
    // node = the new node being added to the tree
    // nodeAtLevel = the last node in the KDTree that the node is being added to
    // k = the level that the tree is on
    // TODO print which side the node will be added on

    int dimension = k % 3; // 0 for x, 1 fro y, 2 for z
    if (node[dimension] < nodeAtLevel[dimension])
    {
        std::cout << "Node is added to the Left\n";
    }
    else
    {
        std::cout << "Node is added to the Right\n";
    }
   
}
void Questions6()
{
    std::cout << "Question 6:\n";
    std::vector<std::array<int, 3>> listOfVectors =
    {
        {10, 10, 10},
        {5, 12, 8},
        {13, 4, 4},
        {2, 20, 6},
        {15, 5, 1},
        {11, 7, 9},
        {3, 9, 5}
    };
    std::array<int, 3> nodeAtLevel = { 9, 11, 7 };
    for (int i = 0; i < listOfVectors.size(); ++i)
    {
        AddToNode(listOfVectors[i], nodeAtLevel, i % 3);
    }

    std::cout << "\n";
}
void PrintConnectionsDFS(const std::vector<std::vector<int>>& graph, int startIndex)
{
    std::cout << "Print Connections (DFS):\n";
    
    // track visited nodes
    std::vector<bool> visited(graph.size(), false);

    std::stack<int> stack;
    stack.push(startIndex);

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();
        if (visited[current])
        {
            continue;
        }

        visited[current] = true;
        std::cout << current << " ";

        for (int i = graph[current].size() - 1; i >= 0; --i)
        {
            int neighbor = graph[current][i];
            if (!visited[neighbor])
            {
                stack.push(neighbor);
            }
        }
    }

    std::cout << "\n";
}
void PrintConnectionsBFS(const std::vector<std::vector<int>>& graph, int startIndex)
{
    std::cout << "Print Connections (BFS):\n";
    // TODO implement BFS algorithm

    std::vector<bool> visited(graph.size(), false);

    // use queue for BFS
    std::queue<int> queue;
    queue.push(startIndex);
    visited[startIndex] = true;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        std::cout << current << " ";

        for (int i = 0; i < graph[current].size(); ++i)
        {
            int neighbor = graph[current][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    std::cout << "\n";
}
void AddLink(std::vector<std::vector<int>>& graph, int index, int linkIndex)
{
    graph[index].push_back(linkIndex);
    graph[linkIndex].push_back(index);
}
void Questions7()
{
    std::cout << "Question 7:\n";
    // TODO - implement the above DFS and BFS algorithms
    int numNodes = 20;
    std::vector<std::vector<int>> adjacencyList;
    adjacencyList.resize(numNodes);
    AddLink(adjacencyList, 0, 1);
    AddLink(adjacencyList, 0, 2);
    AddLink(adjacencyList, 0, 3);
    AddLink(adjacencyList, 1, 4);
    AddLink(adjacencyList, 1, 5);
    AddLink(adjacencyList, 2, 6);
    AddLink(adjacencyList, 2, 7);
    AddLink(adjacencyList, 2, 8);
    AddLink(adjacencyList, 3, 9);
    AddLink(adjacencyList, 3, 10);
    AddLink(adjacencyList, 4, 11);
    AddLink(adjacencyList, 4, 12);
    AddLink(adjacencyList, 5, 13);
    AddLink(adjacencyList, 5, 14);
    AddLink(adjacencyList, 6, 15);
    AddLink(adjacencyList, 7, 16);
    AddLink(adjacencyList, 7, 17);
    AddLink(adjacencyList, 8, 18);
    AddLink(adjacencyList, 8, 19);

    PrintConnectionsDFS(adjacencyList, 10);
    PrintConnectionsBFS(adjacencyList, 3);
    std::cout << "\n";
}
int main()
{
    std::cout << "Hello World!\n";

    Questions1();
    Questions2();
    Questions3();
    Questions4();
    Questions5();
    Questions6();
    Questions7();
}