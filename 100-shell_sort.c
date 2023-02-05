#include "sort.h"

/**
 * shell_sort - implements shell sort algorithm using Knuth sequence
 * @array: int array to sort
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, p;
	size_t gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = 0; i < gap; ++i)
		{
			for (j = i + gap; j < size; j += gap)
			{
				p = j;
				if (array[p] < array[p - gap])
				{
					while (p > i &&
					       array[p] < array[p - gap])
					{
						tmp = array[p];
						array[p] = array[p - gap];
						array[p - gap] = tmp;
						p -= gap;
					}
				}
			}
		}
		print_array(array, size);
		if (gap == 1)
			break;

		gap = (gap - 1) / 3;
	}
}
