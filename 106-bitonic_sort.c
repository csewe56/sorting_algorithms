#include "sort.h"

/**
 * bitonic_merge - Merges two bitonic sequences in ascending order
 * @array: The array to be sorted
 * @low: Starting index of the first sequence
 * @count: Number of elements to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
				print_array(array, count);
			}
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array to be sorted
 * @low: Starting index of the sequence
 * @count: Number of elements to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}

