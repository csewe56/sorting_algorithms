#include "sort.h"

/**
 * heapify - Turn an array into a max heap
 * @array: The array to be turned into a max heap
 * @size: Number of elements in @array
 * @i: Index of the current node
 * @size_orig: Original size of the array
 */
void heapify(int *array, size_t size, size_t i, size_t size_orig)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size_orig);
		heapify(array, size, largest, size_orig);
	}
}

/**
 * heap_sort - Sorts an array of integers
 * in ascending order using the Heap sort
 * algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1; (int)i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

