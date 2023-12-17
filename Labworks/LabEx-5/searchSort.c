#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("[%d] ", arr[i]);
	}
}

void numBinarySearch()
{
	int arr[] = {2,4,6,8,9,0,10,13,20,12};
	int n = sizeof(arr) / sizeof(arr[0]); // Number of elements in array
	int x = 8;							  // Element to be searched for
	int low = 0;						  // Starting index
	int high = n - 1;					  // Ending index
	printf("\nGiven array is\n");
	printArray(arr, n);
	printf("\n\nEntered element to search is %d\n", x);
	// Sorting before searching binary 
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\nSorted array is: \n");
	printArray(arr, n);
	// write the code for binary search
	int found=0;
	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (x == arr[mid])
		{
			printf("\n\nElement found at index %d\n", mid);
			found=1;
			return;
		}
		else if (x > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	if(!found){
		printf("\n\nElement not found.\n");
	}
}

void insertionSort()
{
	// perform insertion sort on numbers
	int n = 5;
	int arr[10] = {3, 7, 2, 1, 9,50,32,12,4,6};
	printf("Insertion Sort:\n");
	printf("\nGiven array is\n");
	printArray(arr, n);
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (!(j < 0 || key < arr[j]))
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
	printf("\nSorted array is: \n");
	printArray(arr, n);
}

void bubbleSort()
{
	// perform bubble sort
	int n = 5;
	int arr[5] = {64, 25, 12, 22, 11,45,0,14,55,90};
	printf("\nBubble Sort : ");
	printf("\nGiven array is\n");
	printArray(arr, n);
	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
    printf("\nSorted array is: \n");
	printArray(arr, n);
}

void numSentinelSearch()
{
	// perform sentinel search on numbers
	int x = 8;
	int arr[] = {-2, 10, 23, 45, 66, 89};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("\nGiven array is\n");
	printArray(arr, n);
	printf("\n\nEntered element to search is %d\n", x);

	arr[n] = x;
	n++;

	int found = 0;	   // Flag to indicate success
	int position = -1; // Store the position if found

	// Search for the target value
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == x)
		{
			found = 1;
			position = i;
			break;
		}
	}
	if (found)
	{
		printf("Element %d found at position %d.\n", x, position);
	}
	else
	{
		printf("Element %d not found.\n", x);
	}
}

void stringSentinelSearch()
{
	// perform sentinel search on String
	char str[] = "The cute cow ate the green grass";
	char ch = 'g';
	int len = strlen(str);
	printf("String :%s\nCharacter To search:%c\n", str, ch);
	// Append the target character as a sentinel to the string
	str[len] = ch;
	len++;

	int count = 0;	   // Counter for occurrences
	int position = -1; // Store first position if found

	// Search for the target character
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ch)
		{
			count++;
			if (position == -1)
				position = i; // Store first position
		}
	}

	if (count == 0)
	{
		printf("Character '%c' not found in the string.\n", ch);
	}
	else
	{
		printf("Character '%c' found %d times.\n", ch, count);
		if (position != -1)
		{
			printf("First occurrence of '%c' is at position %d.\n", ch, position);
		}
	}
}

void numLinearSearch()
{
	// perform linear search
	int x = 10;
	int arr[] = {-2, 10, 22, 35, 42, 50, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is \n");
	printArray(arr, size);
	printf("\nEntered element to search is %d\n", x);

	int foundAt = -1;
	for (int i = 0; i < size; ++i)
	{
		if (x == arr[i])
		{
			foundAt = i;
			break;
		}
	}
	if (foundAt != -1)
		printf("Element is present at index %d\n", foundAt);
	else
	{
		printf("Element is not present in array\n");
	}
}

void stringLinearSearch()
{
	// perform a linear search or a string character by character
	char str[] = "The cute cow ate the green grass";
	char ch = 'g';
	int len = strlen(str);
	printf("String :%s\nCharacter To search:%c\n", str, ch);
	int flag = -1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ch)
		{
			flag = i;
			break;
		}
	}
	if (flag != -1)
		printf("Character First Found at position %d\n", flag);
	else
	{
		printf("Character Not Found\n");
	}
}

void main()
{
	int opt;
	opt = 0;
	while (1)
	{
		printf("\n");
		printf(" +------------Worker-Menu------------+\n");
		printf(" | 1.Binary Search in Numbers        |\n");
		printf(" | 2.Sentinel Search in Number       |\n");
		printf(" | 3.Sentinel Search in String       |\n");
		printf(" | 4.Bubble Sort in Number           |\n");
		printf(" | 5.Insertion Sort in Number        |\n");
		printf(" | 6.Linear Search in Number         |\n");
		printf(" | 7.Linear Search in String         |\n");
		printf(" | 8.Exit                            |\n");
		printf(" +-----------------------------------+\n");
		printf("enter your option : ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			numBinarySearch();
			break;
		case 2:
			numSentinelSearch();
			break;
		case 3:
			stringSentinelSearch();
			break;
		case 4:
			bubbleSort();
			break;
		case 5:
			insertionSort();
			break;
		case 6:
			numLinearSearch();
			break;
		case 7:
			stringLinearSearch();
			break;
		case 8:exit(0);

		}
		getch();
	}
}