#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Compares two elements based on the given direction
 * @array: The array containing the elements
 * @idx1: The index of the first element
 * @idx2: The index of the second element
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t idx1, size_t idx2, int dir)
{
	if ((array[idx1] > array[idx2] && dir) || (array[idx1] < array[idx2] && !dir))
	{
		int temp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = temp;
	}
}

/**
 * bitonic_merge - Merges two subarrays into a bitonic sequence
 * @array: The array to sort
 * @start: The starting index of the subarray
 * @size: The size of the subarray
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	size_t i;
	if (size > 1)
	{
		size_t mid = size / 2;
		for (i = start; i < start + mid; i++)
			bitonic_compare(array, i, i + mid, dir);
		bitonic_merge(array, start, mid, dir);
		bitonic_merge(array, start + mid, mid, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array to sort
 * @start: The starting index of the sequence
 * @size: The size of the sequence
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", size, size * 2, (dir ? "UP" : "DOWN"));
		print_array(array + start, size);

		bitonic_sort_recursive(array, start, mid, 1);
		bitonic_sort_recursive(array, start + mid, mid, 0);
		bitonic_merge(array, start, size, dir);

		printf("Result [%lu/%lu] (%s):\n", size, size * 2, (dir ? "UP" : "DOWN"));
		print_array(array + start, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using bitonic sort
 * @array: The array to sort
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
