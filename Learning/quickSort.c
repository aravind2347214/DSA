#include <stdio.h>
#include <stdlib.h>
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element
    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1; // Return the pivot index
}
// Function to perform Quick Sort on the array
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Find the pivot index
        int pivotIndex = partition(arr, low, high);
        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, size);
        // Perform Quick Sort
    quickSort(arr, 0, size - 1);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}
