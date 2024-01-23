#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme for quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements to be sorted
 *
 * Return: Index of the pivot
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
	}
		while (array[i] < pivot);

		do {
			j--;
	}
		while (array[j] > pivot);

	if (i < j)
	{
		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	else
	{
	return (j);
	}
	}
}

/**
 * quick_sort_hoare_recursive - Recursively sorts
 * a partition using Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements to be sorted
 */
void quick_sort_hoare_recursive(int *array,
		size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot = hoare_partition(array, low, high, size);

		if (pivot > low)
			quick_sort_hoare_recursive(array, low, pivot, size);

		quick_sort_hoare_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 * Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}

