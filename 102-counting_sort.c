#include "sort.h"

/**
 * counting_sort - implements a counting sort algorithm
 * @array: int array to sort
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, j;
	int max = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return;

	j = (size_t)max;
	for (i = 0; i <= j; ++i)
		count[i] = 0;

	for (i = 0; i < size; ++i)
		count[array[i]] = count[array[i]] + 1;

	for (i = 1; i <= j; ++i)
		count[i] = count[i] + count[i - 1];

	print_array(count, max + 1);
	for (i = size - 1; ; --i)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] = count[array[i]] - 1;
		if (i == 0)
			break;
	}
	for (i = 0; i < size; ++i)
		array[i] = output[i];

	free(count);
	free(output);
}
