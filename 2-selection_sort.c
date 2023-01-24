#include "sort.h"

/**
 * selection_sort - implementation of selection sort
 * @array: the given array
 * @size: array size
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		min = size - 1;
		for (j = size - 2; j > i; --j)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (array[i] > array[min])
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
