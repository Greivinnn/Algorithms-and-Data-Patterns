// Week8Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;

void StartAlgorithm()
{
    gStartTime = std::chrono::steady_clock::now();
}
void PrintAlgorithmTime()
{
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime);
    std::cout << "Time (mc) " << duration.count() << "\n";
}

//=========================================================================================
//INSERTION SORT ===========================================================================
void InsertionSort(std::vector<int>& vec)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        int key = vec[i];
        // compare and shift the elements
        int j = i - 1;
        while (j >= 0)
        {
            if (vec[j] > key)
            {
                vec[j + 1] = vec[j];
                --j;
            }
            else
            {
                break;
            }
        }
        vec[j + 1] = key;
        // [][][][]|[][][][]
        // [][]||[][]|[][][]
    }
}

void Exercise1InsertionSort()
{
    // Create Insertion Sort functionality​
    // Create a vector of 20 random numbers from 1 - 100​
    // Print the numbers when added​
    // Run through the sort algorithm and ensure the numbers are sorted
    std::cout << "Insertion Sort:\n";
    std::vector<int> vec(20);
    for (int i = 0; i < vec.size(); ++i)
    {
        int value = 1 + (rand() % 100);
        vec[i] = value;
        std::cout << value << " ";
    }
    std::cout << "\n";
    InsertionSort(vec);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";

}

//=========================================================================================
//MERGE SORT ===========================================================================

void Merge(std::vector<int>& vec, int left, int mid, int right)
{
    // get the size of each section
    int leftSize = (mid - left) + 1;
    int rightSize = right - mid;

    // create temp versions of each side
    std::vector<int> tempLeft(leftSize);
    std::vector<int> tempRight(rightSize);
    for (int i = 0; i < leftSize; ++i)
    {
        tempLeft[i] = vec[left + i];
    }
    for (int i = 0; i < rightSize; ++i)
    {
        tempRight[i] = vec[mid + i + 1];
    }

    // swapping using the temp values and adding back to vec
    int leftIndex = 0;  // index in tempLeft
    int rightIndex = 0; // index in tempRight
    int vecIndex = left;// index in vec
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        // if templeft is less than right index, use the left index and increment
        if (tempLeft[leftIndex] <= tempRight[rightIndex])
        {
            vec[vecIndex] = tempLeft[leftIndex];
            ++leftIndex;
        }
        // otherwise use the right side
        else
        {
            vec[vecIndex] = tempRight[rightIndex];
            ++rightIndex;
        }
        // either way, the vec get updated and we find the next value
        ++vecIndex;
    }
    // pass over remaining left
    while (leftIndex < leftSize)
    {
        vec[vecIndex] = tempLeft[leftIndex];
        ++vecIndex;
        ++leftIndex;
    }
    // pass over remaining right
    while (rightIndex < rightSize)
    {
        vec[vecIndex] = tempRight[rightIndex];
        ++vecIndex;
        ++rightIndex;
    }
}
// left and right would be equivalent to the "begin()" and "end()" for iterators
void MergeSort(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + ((right - left) / 2);
        // split the container in half
        MergeSort(vec, left, mid);
        MergeSort(vec, mid + 1, right);
        // after splitting, merge back together and sort
        Merge(vec, left, mid, right);
    }
}

void Exercise2MergeSort()
{
    // Create MergeSort functionality​
    // Create a vector of 20 random numbers from 1 - 100​
    // Print the numbers when added​
    // Run through the sort algorithm and ensure the numbers are sorted
    std::cout << "Merge Sort:\n";
    std::vector<int> vec(20);
    for (int i = 0; i < vec.size(); ++i)
    {
        int value = 1 + (rand() % 100);
        vec[i] = value;
        std::cout << value << " ";
    }
    std::cout << "\n";
    MergeSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";
}

//=========================================================================================
//QUICK SORT ===========================================================================

// need a swap for Quick Sort
void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(std::vector<int>& vec, int left, int right)
{
    int pivot = vec[right]; // choose last element as the pivot
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        if (vec[j] < pivot)
        {
            ++i;
            Swap(vec[i], vec[j]);
        }
    }
    Swap(vec[i + 1], vec[right]);
    return i + 1;
}
void QuickSort(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        int p = Partition(vec, left, right);
        QuickSort(vec, left, p - 1);
        QuickSort(vec, p + 1, right);
    }
}

void Exercise3QuickSort()
{
    // Create Quick Sort functionality​
    // Create a vector of 20 random numbers from 1 - 100​
    // Print the numbers when added​
    // Run through the sort algorithm and ensure the numbers are sorted
    std::cout << "Quick Sort:\n";
    std::vector<int> vec(20);
    for (int i = 0; i < vec.size(); ++i)
    {
        int value = 1 + (rand() % 100);
        vec[i] = value;
        std::cout << value << " ";
    }
    std::cout << "\n";
    QuickSort(vec, 0, vec.size() - 1);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n\n";
}

//=========================================================================================
//BUCKET SORT ===========================================================================

void BucketSort(std::vector<int>& vec)
{
    const int size = vec.size();
    int maxValue = 0;
    for (int i = 0; i < size; ++i)
    {
        maxValue = std::max(maxValue, vec[i]);
    }
    // take the max value, add 1, this will prevent a 0-1, will guarantee 0-99
    ++maxValue;
    // create buckets or table of elements
    std::vector<std::vector<int>> buckets(size);
    // add elements to respective buckets
    for (int i = 0; i < size; ++i)
    {
        int bucketIndex = ((size * vec[i]) / maxValue);
        buckets[bucketIndex].push_back(vec[i]);
    }
    // sorting method for each bucket (use insertion)
    for (int i = 0; i < size; ++i)
    {
        InsertionSort(buckets[i]);
    }
    // combine all buckets back into the container
    int vecIndex = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            vec[vecIndex] = buckets[i][j];
            ++vecIndex;
        }
    }
}

void Exercise4BucketSort()
{
    std::cout << "Bucket Sort:\n";
    std::vector<int> vec(20);
    for (int i = 0; i < vec.size(); ++i)
    {
        int value = 1 + (rand() % 100);
        vec[i] = value;
        std::cout << value << " ";
    }
    std::cout << "\n";
    BucketSort(vec);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n\n";
}

//=========================================================================================
//RADIX SORT ===========================================================================
void PrintVec(const std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void CountingSort(std::vector<int>& vec, int exp)
{
    std::vector<int> output(vec.size());
    int count[10] = { 0 };

    for (int i = 0; i < vec.size(); ++i)
    {
        // (3268 / 1) % 10 = 8
        // (3268 / 10) % 10 = 6
        // (3268 / 100) % 10 = 2
        int index = (vec[i] / exp) % 10;
        ++count[index];
    }
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }
    // sort based on the item value and count to determine the index
    for (int i = vec.size() - 1; i >= 0; --i)
    {
        int index = (vec[i] / exp) % 10;
        output[count[index] - 1] = vec[i];
        --count[index];
    }
    // set the value to the sorted output
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = output[i];
    }
}

void RadixSort(std::vector<int>& vec)
{
    int maxValue = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        maxValue = std::max(maxValue, vec[i]);
    }

    for (int exp = 1; maxValue / exp > 0; exp *= 10)
    {
        CountingSort(vec, exp);
        //PrintVec(vec);
    }
}

void Exercise5RadixSort()
{
    std::cout << "Radix Sort:\n";
    std::vector<int> vec(20);
    for (int i = 0; i < vec.size(); ++i)
    {
        int value = 1 + (rand() % 10000);
        vec[i] = value;
        std::cout << value << " ";
    }
    std::cout << "\n";
    RadixSort(vec);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n\n";
}
//=========================================================================================
// SORTING RACE ===========================================================================

void Exercise6SortingRace()
{
    std::cout << "Sorting Race:\n";
    int vectorSize = 10000;
    std::vector<int> vecA(vectorSize);
    std::vector<int> vecB(vectorSize);
    std::vector<int> vecC(vectorSize);
    std::vector<int> vecD(vectorSize);
    std::vector<int> vecE(vectorSize);
    for (int i = 0; i < vectorSize; ++i)
    {
        int value = 1 + (rand() % 1000000);
        vecA[i] = value;
        vecB[i] = value;
        vecC[i] = value;
        vecD[i] = value;
        vecE[i] = value;
    }
    // slower with bigger values, but simple
    std::cout << "Insertion Sort:\n";
    StartAlgorithm();
    InsertionSort(vecA);
    PrintAlgorithmTime();
    std::cout << "\n";
    // divide and conquer, but uses a lot of recursion and can limit stack space
    std::cout << "Merge Sort:\n";
    StartAlgorithm();
    MergeSort(vecB, 0, vecB.size() - 1);
    PrintAlgorithmTime();
    std::cout << "\n";
    // also uses divide and conquer, uses less memory than merge sort
    std::cout << "Quick Sort:\n";
    StartAlgorithm();
    QuickSort(vecC, 0, vecC.size() - 1);
    PrintAlgorithmTime();
    std::cout << "\n";
    // fairly, fast but requires more memory to work
    std::cout << "Bucket Sort:\n";
    StartAlgorithm();
    BucketSort(vecD);
    PrintAlgorithmTime();
    std::cout << "\n";
    // fast, but limited to fixed size data (eg: ints, strings, longs...)
    std::cout << "Radix Sort:\n";
    StartAlgorithm();
    RadixSort(vecE);
    PrintAlgorithmTime();
    std::cout << "\n";
}

int main()
{
    std::cout << "Sorting!\n";
    //Exercise1InsertionSort();
    //Exercise2MergeSort();
    //Exercise3QuickSort();
    //Exercise4BucketSort();
    //Exercise5RadixSort();
    Exercise6SortingRace();
}

