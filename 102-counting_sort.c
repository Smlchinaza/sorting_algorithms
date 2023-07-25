#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *output = NULL;
	int max_value = 0;
	size_t i;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Create a counting array with size = max_value + 1 */
	count = malloc((max_value + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize the counting array with 0 */
	for (i = 0; i <= (size_t)max_value; i++)
		count[i] = 0;

	/* Count the frequency of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the counting array to store the cumulative frequencies */
	for (i = 1; i <= (size_t)max_value; i++)
		count[i] += count[i - 1];

	/* Create the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Build the output array based on the counting array */
	for (i = size - 1; i != (size_t)(-1); i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Free the allocated memory */
	free(count);
	free(output);

	/* Print the counting array */
	printf("%d", count[0]);
	for (i = 1; i <= (size_t)max_value; i++)
		printf(", %d", count[i]);
	printf("\n");
}
