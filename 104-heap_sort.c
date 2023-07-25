#include "sort.h"

/**
 * heapify - Builds a max heap from an array
 * @array: The array to heapify
 * @size: The size of the array
 * @index: The index to start heapifying from
 */
void heapify(int *array, size_t size, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		int temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}
