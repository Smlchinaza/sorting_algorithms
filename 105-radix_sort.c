#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort_radix - Performs counting sort on an array based on a specific
 * significant digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The current significant digit to consider
 */
void counting_sort_radix(int *array, int size, int exp)
{
	int *output = NULL;
	int count[10] = {0};
	int i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
	}
}
