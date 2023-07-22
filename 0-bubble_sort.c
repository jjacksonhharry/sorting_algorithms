#include "sort.h"

/**
 * bubble_sort - implementation of bubble sort algorithm
 * that sorts an array of integers in ascending order
 *
 * @array: the array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, swapped = 1;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
