// Week7Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <assert.h>

// create data for IpAddress
class IpAddress
{
public:
    IpAddress()
    {
        for (int i = 0; i < 4; ++i)
        {
            mAddress[i] = rand() % 1000;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const IpAddress& a)
    {
        os << a.mAddress[0] << "." << a.mAddress[1] << "." << a.mAddress[2] << "." << a.mAddress[3];
        return os;
    }
    bool operator<(const IpAddress& rhs) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mAddress[i] != rhs.mAddress[i])
            {
                return mAddress[i] < rhs.mAddress[i];
            }
        }
        return false;
    }
    bool operator<=(const IpAddress& rhs) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mAddress[i] > rhs.mAddress[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator==(const IpAddress& rhs) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mAddress[i] != rhs.mAddress[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator>=(const IpAddress& rhs) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mAddress[i] < rhs.mAddress[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator>(const IpAddress& rhs) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mAddress[i] != rhs.mAddress[i])
            {
                return mAddress[i] > rhs.mAddress[i];
            }
        }
        return false;
    }
private:
    int mAddress[4];
};





// Node for storing data
struct Node
{
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

int gCounter = 0;
// function to create a node
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
// inserts a node into the BST
Node* Insert(Node* node, int data)
{
    if (node == nullptr)
    {
        return CreateNode(data);
    }
    if (data < node->data)
    {
        node->left = Insert(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Insert(node->right, data);
    }
    else
    {
        assert(false, "Data must be unique");
    }
    return node;
}

// finds a node in the BST
bool Search(Node* node, int data)
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->data == data)
    {
        return true;
    }
    if (data < node->data)
    {
        return Search(node->left, data);
    }
    return Search(node->right, data);
}

Node* GetMinNode(Node* node)
{
    Node* minNode = node;
    while (minNode != nullptr && minNode->left != nullptr)
    {
        ++gCounter;
        minNode = minNode->left;
    }
    return minNode;
}

Node* GetMaxNode(Node* node)
{
    Node* maxNode = node;
    while (maxNode != nullptr && maxNode->right != nullptr)
    {
        ++gCounter;
        maxNode = maxNode->right;
    }
    return maxNode;
}

// deletes a node in the BST
Node* Delete(Node* node, int data)
{
    if (node == nullptr)
    {
        return node;
    }
    if (data < node->data)
    {
        node->left = Delete(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = Delete(node->right, data);
    }
    else
    {
        // check to see if a node has a child
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            node = nullptr;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            node = nullptr;
            return temp;
        }
        // find the node to replace from the children
        Node* temp = GetMinNode(node->right);
        node->data = temp->data;
        node->right = Delete(node->right, temp->data);
    }
    return node;
}

void PrintInOrder(Node* root)
{
    if (root != nullptr)
    {
        PrintInOrder(root->left);
        std::cout << root->data << " ";
        PrintInOrder(root->right);
    }
}
void PrintReverseOrder(Node* root)
{
    if (root != nullptr)
    {
        PrintReverseOrder(root->right);
        std::cout << root->data << " ";
        PrintReverseOrder(root->left);
    }
}

//================================================================================
// AVL TREE NODES
struct AVLNode
{
    IpAddress data;
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    int height = 0;
};
AVLNode* CreateAVLNode(IpAddress data)
{
    AVLNode* newNode = new AVLNode();
    newNode->data = data;
    newNode->height = 0;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
void PrintInOrder(AVLNode* root)
{
    if (root != nullptr)
    {
        PrintInOrder(root->left);
        std::cout << root->data << "\n";
        PrintInOrder(root->right);
    }
}
void PrintReverseOrder(AVLNode* root)
{
    if (root != nullptr)
    {
        PrintReverseOrder(root->right);
        std::cout << root->data << "\n";
        PrintReverseOrder(root->left);
    }
}
bool Search(AVLNode* node, IpAddress data)
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->data == data)
    {
        return true;
    }
    if (data < node->data)
    {
        return Search(node->left, data);
    }
    return Search(node->right, data);
}
AVLNode* GetMinNode(AVLNode* root)
{
    AVLNode* minNode = root;
    while (minNode != nullptr && minNode->left != nullptr)
    {
        minNode = minNode->left;
    }
    return minNode;
}
AVLNode* GetMaxNode(AVLNode* root)
{
    AVLNode* maxNode = root;
    while (maxNode != nullptr && maxNode->right != nullptr)
    {
        maxNode = maxNode->right;
    }
    return maxNode;
}
// the height of the tree from this node point
int NodeHeight(AVLNode* node)
{
    if (node != nullptr)
    {
        return node->height;
    }
    return 0;
}
// the biggest difference in the tree height between both child nodes
// if > 1, the tree needs to be rebalanced
int BalanceFactor(AVLNode* node)
{
    if (node != nullptr)
    {
        return NodeHeight(node->left) - NodeHeight(node->right);
    }
    return 0;
}
// Rotate Right
AVLNode* RotateRight(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* temp = x->right;
    x->right = y;
    y->left = temp;
    y->height = std::max(NodeHeight(y->left), NodeHeight(y->right)) + 1;
    x->height = std::max(NodeHeight(x->left), NodeHeight(x->right)) + 1;
    return x;
}
// Rotate Left
AVLNode* RotateLeft(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* temp = y->left;
    y->left = x;
    x->right = temp;
    x->height = std::max(NodeHeight(x->left), NodeHeight(x->right)) + 1;
    y->height = std::max(NodeHeight(y->left), NodeHeight(y->right)) + 1;
    return y;
}
AVLNode* Insert(AVLNode* node, IpAddress data)
{
    if (node == nullptr)
    {
        return CreateAVLNode(data);
    }
    if (data < node->data)
    {
        node->left = Insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = Insert(node->right, data);
    }
    else
    {
        assert(false, "Data must be unique");
    }

    node->height = 1 + std::max(NodeHeight(node->left), NodeHeight(node->right));
    int balanceFactor = BalanceFactor(node);
    // Case 1, left is too long
    if (balanceFactor > 1 && data < node->left->data)
    {
        // return rotate right
        return RotateRight(node);
    }
    // Case 4, right is too long
    if (balanceFactor < -1 && data > node->right->data)
    {
        // return rotate left
        return RotateLeft(node);
    }
    // Case 2, right arm of the left side is too long
    if (balanceFactor > 1 && data > node->left->data)
    {
        // rotate left
        node->left = RotateLeft(node->left);
        // return rotate right
        return RotateRight(node);
    }
    // Case 3, left arm of the right side is too long
    if (balanceFactor < -1 && data < node->right->data)
    {
        // rotate right
        node->right = RotateRight(node->right);
        // return rotate left
        return RotateLeft(node);
    }
    return node;
}
AVLNode* Delete(AVLNode* node, IpAddress data)
{
    if (node == nullptr)
    {
        return node;
    }
    if (data < node->data)
    {
        node->left = Delete(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = Delete(node->right, data);
    }
    else
    {
        if (node->left == nullptr)
        {
            AVLNode* temp = node->right;
            delete node;
            node = nullptr;
            return temp;
        }
        if (node->right == nullptr)
        {
            AVLNode* temp = node->left;
            delete node;
            node = nullptr;
            return temp;
        }
        AVLNode* temp = GetMinNode(node->right);
        node->data = temp->data;
        node->right = Delete(node->right, temp->data);

        // AVL step for balancing
        node->height = 1 + std::max(NodeHeight(node->left), NodeHeight(node->right));
        int balanceFactor = BalanceFactor(node);

        if (balanceFactor > 1 && BalanceFactor(node->left) >= 0)
        {
            return RotateRight(node);
        }
        if (balanceFactor < -1 && BalanceFactor(node->right) <= 0)
        {
            return RotateLeft(node);
        }
        if (balanceFactor > 1 && BalanceFactor(node->left) < 0)
        {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }
        if (balanceFactor < -1 && BalanceFactor(node->right) > 0)
        {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }
    }
    return node;
}

//================================================================================
void Exercise1()
{
    Node* root = nullptr;
    std::cout << "Binary Search Tree:\n";
    for (int i = 0; i < 20; ++i)
    {
        int data = 1 + (rand() % 1000);
        while (Search(root, data))
        {
            data = 1 + (rand() % 1000);
        }
        std::cout << data << " ";
        root = Insert(root, data);
    }
    std::cout << "\n";
    PrintInOrder(root);
    std::cout << "\n";
    PrintReverseOrder(root);
    std::cout << "\n";

    Delete(root, 335);
    PrintInOrder(root);
    std::cout << "\n";
    Delete(root, 963);
    PrintInOrder(root);
    std::cout << "\n";

    gCounter = 0;
    std::cout << "MinValue: " << GetMinNode(root)->data << " NumTested: " << gCounter << "\n";
    gCounter = 0;
    std::cout << "MaxValue: " << GetMaxNode(root)->data << " NumTested: " << gCounter << "\n";
}
void Exercise2BST()
{
    // Build a Binary Search Tree​*
    // Pass in 100 random 8 digit numbers(eg: ip address)​
    // Add them to the BST​
    // Print them all in order lowest to highest​
    // Print them in reverse order​
    // Remove 20​
    // Print in order and ensure they are all correctly removed
    Node* root = nullptr;
    std::cout << "Binary Search Tree:\n";
    for (int i = 0; i < 100; ++i)
    {
        int data = rand() % 100000000;
        root = Insert(root, data);
    }
    PrintInOrder(root);
    std::cout << "\n";
    std::cout << "\n";
    PrintReverseOrder(root);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Starting Root Node: " << root->data << "\n";
    for (int i = 0; i < 20; ++i)
    {
        root = Delete(root, root->data);
        std::cout << "New Root Node: " << root->data << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
    PrintInOrder(root);
    std::cout << "\n";
    std::cout << "\n";
}

void Exercise3TestAVL()
{
    // COMMENTED OUT BECAUSE THE DATA CHANGED, SO THIS WONT WORK
    //AVLNode* root = nullptr;
    //std::cout << "AVL Tree:\n";
    //for (int i = 0; i < 20; ++i)
    //{
    //    int data = 1 + (rand() % 100);
    //    while (Search(root, data))
    //    {
    //        data = 1 + (rand() % 100);
    //    }
    //    root = Insert(root, data);
    //}
    //PrintInOrder(root);
    //std::cout << "\n\n";
    //PrintReverseOrder(root);
    //std::cout << "\n\n";

    //root = Delete(root, 79);
    //root = Delete(root, 62);
    //root = Delete(root, 42);
    //root = Delete(root, 96);
    //PrintInOrder(root);
    //std::cout << "\n\n";

    //std::cout << "Min Value: " << GetMinNode(root)->data << "\n";
    //std::cout << "Max Value: " << GetMaxNode(root)->data << "\n";
}

int main()
{
    //Modify the Binary Search Tree to self - balance itself​*
    //Making it an AVL tree​*
    //Create a class for "IpAddress"​
    //Store an array of 4 ints​
    //Each int can be 0 - 999​
    //Needs compare operators for <, <= , == , >, and >= ​
    //Needs a print to print the array "array[0].array[1].array[2].array[3]"​
    //Pass in 100 random ip addresses​
    //Throw an error if there are duplicates​*
    //Add them to the AVL​
    //Print them all in order lowest to highest​
    //Print them in reverse order​
    //Remove 20​
    //Print in order and ensure they are all correctly removed
    AVLNode* root = nullptr;
    std::cout << "AVL Tree:\n";
    for (int i = 0; i < 10; ++i)
    {
        IpAddress newAddress;
        root = Insert(root, newAddress);
    }
    PrintInOrder(root);
}
