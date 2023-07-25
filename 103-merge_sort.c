#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);  /* Forward declaration */

/**
 * merge - Merges two subarrays into one sorted array
 * @array: Pointer to the original array
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	size_t size = left_size + right_size;
	int *temp = malloc(sizeof(int) * size);

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	printf("[Done]: ");
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
		if (i < size - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}

	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2 || array == NULL)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, mid, right, size - mid);

	printf("\n");
}
