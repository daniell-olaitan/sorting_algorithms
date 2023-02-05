#include "sort"

/**
 * counting_sort - implements a counting sort algorithm
 * @array: int array to sort
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	size_t i;
	int max = 0, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; i <= max; ++i)
		count[array[i]] = count[array[i]] + 1;

	for (i = 1; i <= max; ++i)
		count[i] = count[i] + count[i - 1];

	print_array(array, size);
	for (i = max; i >= 0; --i)
	{
		tmp = array[i];
		array[count[tmp]] = tmp;
		count[tmp] = count[tmp] - 1;
	}

	free(count);
}
