#include "sort.h"

/**
 * swap - swaps two numbers
 * @num1: first number
 * @num2: second number
 */
void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * partition - find partiton position
 * @array: array of integer
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: number of elements in @array
 *
 * Return: position of pivot
 */
size_t partition(int *array, int low, int high, size_t size);
{
	int pivot = array[high];
	int ptr = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (ptr != j)
			{
				swap(&array[ptr], &array[j]);
				print_array(array, size);
			}
			ptr++;
		}
	}
	if (ptr != high)
	{
		swap(&array[ptr], &array[high]);
		print_array(array, size);
	}
	return (ptr);
}

/**
 * quicksort - quick sort with recursion
 * @array: array of integer
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: number of elements in @array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
