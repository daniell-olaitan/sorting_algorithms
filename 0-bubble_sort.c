#include "sort.h"

void print_arr(int *arr, size_t size);

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
					print_arr(array, size);
				}
			}
			if (!swap)
				break;
		}
	}
}

/**
 * print_arr - prints an array of ints
 * @arr: the array to be printed
 * @size: number of elements in arr
 *
 */
void print_arr(int *arr, size_t size)
{
	size_t i = 0;

	while (arr && i < size)
	{
		if (i > 0)
			printf(", ");

		printf("%i", arr[i]);
		i++;
	}
	printf("\n");
}
