#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * @size: Number of elements in array
 * @array: The array to be sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, mid = 1;
	int tmp;

	while (mid < size / 3)
		mid = mid * 3 + 1;

	while (mid > 0)
	{
		for (i = mid; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= mid && array[j - mid] > tmp)
			{
				array[j] = array[j - mid];
				j -= mid;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		mid /= 3;
	}

}
