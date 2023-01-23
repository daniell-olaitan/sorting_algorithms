#include "sort.h"

/**
 * bubble_sort - implements bubble sort algorithm
 * @array: the array of int to be sorted
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	if (array && size > 1)
	{
		for (i = 0; i < size - 1; ++i)
		{
			swap = 0;
			for (j = 0; j < size - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
					swap = 1;
					print_array(array, size);
				}
			}
			if (!swap)
				break;
		}
	}
}
