/*
Array class with templates seen in class
Arturo Burela A01019906
Fernando Alcántara A01019595
September 14, 2016


Partial_Evaluation_1

*/
#ifndef A
#define A

#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>
class Array {
    private:
        // Pointer to the data itself
        T * data = NULL;
        // Reference to the size of the array
        int size;
        // Private methods
        int binarySearchRecursive(T item, int start, int end);
        void mergeSortRecursion(T * temp, int start, int end);
        void mergeSortMerge(T * temp, int start, int middle, int end);
        void quickSortRecursion(int start, int end);
        int quickSortPartitionHoare(int start, int end);
        int quickSortPartitionLomuto(int start, int end);
        void swap(T * a, T * b);        
    public:
        // Constructor
        Array(int _size = 10);
        // Destructor
        ~Array();
        // Access methods
        void setElement(int index, T item);
        T getElement(int index);
        // Basic methods
        void printRecursive(int start);
        int getLast() { return size - 1; }
        // Search methods
        int linearSearch(T item);
        int binarySearchIterative(T item);
        int binarySearchRecursive(T item);
        // Sorting methods
        void bubbleSort();
        void insertionSort();
        void selectionSort();
        void mergeSort();
        void quickSort();
        // Helper methods
        bool checkOrdered();
        T & operator[] (const int index);   // Write access
        const T & operator[] (const int index) const; // Read only
        
};

template <class T>
Array<T>::Array(int _size)
{
    // Init the random seed
    srand(time(NULL));
    // Allocate the space if the size is a positive number
    if (_size > 0)
    {
        size = _size;
        data = new T[size];
    }     
    else
    {
        std::cout << "Error! Invalid array size!" << std::endl;
        exit(1);
    }
}

template <class T>
Array<T>::~Array()
{
    delete [] data;
}


template <class T>
void Array<T>::setElement(int index, T item)
{
    if (index >= 0 && index <size)
        data[index] = item;
}

template <class T>
T Array<T>::getElement(int index)
{
    //if (index >= 0 && index <size)
    //{
        return data[index];
    //}
    //else
    //{
      //  std::cout << "Invalid index!" << std::endl;
        //return data[0];
    //}
}

template <class T>
T & Array<T>::operator[] (const int index)   // Write access
{
    if (index >= 0 && index <size)
    {
        return data[index];
    }
    else
    {
      std::cout << "Invalid index!" << std::endl;
      return data[0];
    }
}

template <class T>
const T & Array<T>::operator[] (const int index) const // Read only
{
    if (index >= 0 && index <size)
    {
        return data[index];
    }
    else
    {
        std::cout << "Invalid index!" << std::endl;
        return data[0];
    }
}
        
template <class T>
void Array<T>::printRecursive(int index)
{
    if (index < size)
    {
        std::cout << " " << data[index];
        printRecursive(index + 1);
    }
    else
    {
        std::cout << std::endl;
    }
}

// Search for the element specified using linear search
// Return -1 if not found, otherwise return the index where item was found
template <class T>
int Array<T>::linearSearch(T item)
{
    for (int i=0; i<size; i++)
    {
        if (data[i] == item)
            return i;
    }
    return -1;
}

// Search for the element specified using binary search
// Return -1 if not found, otherwise return the index where item was found
template <class T>
int Array<T>::binarySearchIterative(T item)
{
    // Set the initial limits of the search
    int start = 0;
    int end = size - 1;
    // Index for the middle of the search range
    int middle;
    
    while (start <= end)
    {
        //std::cout << "Searching between " << start << " and " << end << std::endl;
        // Update the middle
        middle = (start + end) / 2;
        // Update the search range
        if (data[middle] < item)
            start = middle + 1;
        else if (data[middle] > item)
            end = middle - 1;
        else
            return middle;
    }
    return -1;
}

// Search for the element specified using binary search
// Return -1 if not found, otherwise return the index where item was found
template <class T>
int Array<T>::binarySearchRecursive(T item)
{
    return binarySearchRecursive(item, 0, size-1);
}

// Recursive method to search in a delimited array
// Receives the indices that indicate the search range
// Return -1 if not found, otherwise return the index where item was found
template <class T>
int Array<T>::binarySearchRecursive(T item, int start, int end)
{
    // Base case to finish the recursion
    if (end < start)
        return -1;
        
    //std::cout << "Searching between " << start << " and " << end << std::endl;
    int middle = (start + end) / 2;
    if (item > data[middle])
        return binarySearchRecursive(item, middle + 1, end);
    else if (item < data[middle])
        return binarySearchRecursive(item, start, middle - 1);
    else
        return middle;
}

// Push the largest values back, one by one
template <class T>
void Array<T>::bubbleSort()
{
    int comparisons = 0;
    int swaps = 0;
    
    for (int i=0; i<size; i++)
    {
        for (int j=1; j<size - i; j++)
        {
            comparisons++;
            if (data[j] < data[j-1])
            {
                swap(&data[j], &data[j-1]);
                swaps++;
            }
        }
    }
    std::cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << std::endl;
}

// Shift the last value indicated by index i back until}
// it finds its correct position
template <class T>
void Array<T>::insertionSort()
{
    int comparisons = 0;
    int swaps = 0;
    
    T value;
    int j;
    
    for (int i=1; i<size; i++)
    {
        // Store the value that must be inserted in place
        value = data[i];
        // Start at the first unordered element
        j = i;
        // Compare against the element before
        while (j>0 && value<data[j-1])
        {
            comparisons++;
            data[j] = data[j-1];
            swaps++;
            j--;
        }
        data[j] = value;
        swaps++;
    }
    std::cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << std::endl;
}

// Look for the next smallest number and place it at index i
template <class T>
void Array<T>::selectionSort()
{
    int comparisons = 0;
    int swaps = 0;
    
    int min_index;
    
    for (int i=0; i<size; i++)
    {
        // Initialize the values for the loop
        min_index = i;
        for (int j=i+1; j<size; j++)
        {
            comparisons++;
            if (data[j] < data[min_index])
            {
                // Store the index of the smallest element found
                min_index = j;
            }
        }
        // Swap the smallest for the current position
        swap(&data[i], &data[min_index]);
        swaps++;
    }
    std::cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << std::endl;
}

// Switch the values of two variables
template <class T>
void Array<T>::swap(T * a, T * b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// Public access to the merge sort algorithm
template <class T>
void Array<T>::mergeSort()
{
    // Create a temporary array
    T * temp = new T[size];
    // Call the recursive method
    mergeSortRecursion(temp, 0, size);
    // Free the temporary array
    delete [] temp;
    
}

template <class T>
void Array<T>::mergeSortRecursion(T * temp, int start, int end)
{
    // Recursive case, the array has more than 1 element
    if (end - start > 1)
    {
        int middle = (start + end) / 2;
        // Sort the first half of the array
        mergeSortRecursion(temp, start, middle);
        // Sort the second half of the array
        mergeSortRecursion(temp, middle, end);
        // Merge the two halves using the temporary array
        mergeSortMerge(temp, start, middle, end);
    }
}

template <class T>
void Array<T>::mergeSortMerge(T * temp, int start, int middle, int end)
{
    // Define the starting indices for the sorted subarrays
    int i = start;
    int j = middle;
    // Loop over the sorted section
    for (int k=start; k<end; k++)
    {
        // Select from the first half if:
        // - There are still elements in that half
        // - There are no more elements in the other half
        // - The first element in the first half is smaller than
        //   the first element in the second half
        if (i<middle && (j>=end || data[i]<data[j]))
            temp[k] = data[i++];
        else
            temp[k] = data[j++];
    }
    
    // Copy the modified elements in temp back to the array
    for (int k=start; k<end; k++)
    {
        data[k] = temp[k];
    }
}

template <class T>
void Array<T>::quickSort()
{
    quickSortRecursion(0, size-1);
}

template <class T>
void Array<T>::quickSortRecursion(int start, int end)
{
    if (start < end)
    {
        //int pivot = quickSortPartitionLomuto(start, end);
        int pivot = quickSortPartitionHoare(start, end);
        quickSortRecursion(start, pivot-1);
        quickSortRecursion(pivot+1, end);
    }
}

/*
int Array<T>::quickSortPartitionLomuto(int start, int end)
{
    // Select the pivot as the middle element in the array
    int middle = (start + end) / 2;
    int pivot_value = data[middle];
    int pivot_index = start; // Index where the pivot should go
    
    for (int i = start; i<=end; i++)
    {
        if (data[i] < pivot_value)
        {
            // Move the smaller elements to the first half of the array
            swap(&data[i], &data[pivot_index]);
            // Increment the index for the pivot
            pivot_index++;
        }
    }
    // Move the pivot to the position it should be at
    swap(&data[middle], &data[pivot_index]);
    
    return pivot_index;
}
*/

template <class T>
int Array<T>::quickSortPartitionLomuto(int start, int end)
{
    // Select the pivot as the last element in the array
    int pivot_value = data[end];
    int pivot_index = start; // Index where the pivot should go
    
    for (int i = start; i<end; i++)
    {
        if (data[i] < pivot_value)
        {
            // Move the smaller elements to the first half of the array
            swap(&data[i], &data[pivot_index]);
            // Increment the index for the pivot
            pivot_index++;
        }
    }
    // Move the pivot to the position it should be at
    swap(&data[end], &data[pivot_index]);
    
    return pivot_index;
}

template <class T>
int Array<T>::quickSortPartitionHoare(int start, int end)
{
    int pivot_index = start;
    int i = start;
    int j = end + 1;
    
    while (i < j)
    {
        // Count the elements larger than the pivot
        do
        {
            j--;
        } while (data[j] > data[pivot_index]);
        // Count the elements smaller than the pivot
        do
        {
            i++;
        } while (data[i] < data[pivot_index] && i <= end);
        // Swap elements that are on the wrong side
        if (i < j)
            swap(&data[i], &data[j]);
    }
    // Place the pivot in its correct position
    swap(&data[pivot_index], &data[j]);
    return j;
}

template <class T>
bool Array<T>::checkOrdered()
{
    for (int i=1; i<size; i++)
    {
        if (data[i] < data[i-1])
            return false;
    }
    return true;
}
#endif