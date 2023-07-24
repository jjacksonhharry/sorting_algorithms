#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - implementation of bubble sort algorithm
 * that sorts an array of integers in ascending order
 *
 * @array: the array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp, swapped = 1;

	if (size <= 1 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
