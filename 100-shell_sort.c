#include "sort.h"

/**
 * shell_sort - implements shell sort algorithm using Knuth sequence
 * @array: int array to sort
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j;
	size_t n;
	long int gap = 1;

	n = size / 3;
	while (gap < n)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = 0; i < gap; ++i)
		{
			for (j = i; j < size; j += gap)
