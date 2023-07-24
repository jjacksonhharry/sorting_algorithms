#include "sort.h"

/**
 * partition - implementation of lomuto partition scheme
 * @array: unsorted array
 * @low: starting index
 * @high: ending index
 *
 * Return: index of the pivot
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (pivot != array[i])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_lemuto - helps quicksort implement the lomuto partition
 * @array: the array to be sorted
 * @low: starting index
 * @high: last index
 */
void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t index; /* partition index */

	if (low < high)
	{
		index = partition(array, low, high, size);

		/* There is a left partition */
		if (index > 0)
			quick_sort_lomuto(array, low, index - 1, size);
		/* there is a right partition */
		if (index < high)
			quick_sort_lomuto(array, index + 1, high, size);
	}
}

/**
 * quick_sort - implementation of the quicksort algorithm
 * using the lomuto partition
 * @array: an unsorted array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	quick_sort_lomuto(array, 0, size - 1, size);
}
