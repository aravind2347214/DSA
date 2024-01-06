//   write me the algorithm for quicksort in c

//  this is a simple implementation of quicksort algorithm.
//  it takes an array and its size as input parameters, and returns void.

#include<stdio.h>
#include<stdlib.h>
void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        /* pi is partitioning index, i and j are boundaries of left subarray */
        int pi = l, i = l + 1, j = r;
        int temp;
        /* this loop will run till i is less than j */
        while (i <= j)
        {
            /* If element at i is smaller than or equal to pivot then increment i */
            if (arr[i] <= arr[pi])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j--;
            }
            else
            {
                temp = arr[i];
                arr[i] = arr[pi];
                arr[pi] = temp;
                i++;
            }
        }
        /* pi is now on the correct position in the sorted array */
        /* swap elements at i and j */
        /* so, put the smallest one at the beginning of the list */
        temp = arr[i];
        arr[i] = arr[pi];
        arr[pi] = temp;
        /* recur for the two partitions */
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, r);
    }
}
/* Function to print an array */
void PrintArray(int arr[], int n)
{
    int i;
    printf("The Sorted Array: \n");
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
/* Driver program to test above function*/
int main()
{
    int arr[] = {-7, 5, 2, 4, -3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n - 1);
    PrintArray(arr, n);
    return 0;
}