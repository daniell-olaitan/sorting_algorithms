#include "sort.h"

int partition(int *arr, int low, int high, size_t size);
void swap(int *arr, int a, int b, size_t size);
void quick_sort_r(int *arr, int low, int high, size_t size);

/**
 * quick_sort - implements quick sort algorithm
 * @array: the array to be sorted in ascending order
 * @size: the size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_r(array, 0, size - 1, size);
}

/**
 * quick_sort_r - recursive version of quick_sort
 * @arr: array to sort
 * @low: low of subarray
 * @high: high of subarray
 * @size: size of array
 *
 */
void quick_sort_r(int *arr, int low, int high, size_t size)
{
	int pivot;

	if (high - low < 1)
		return;

	pivot = partition(arr, low, high, size);
	quick_sort_r(arr, low, pivot - 1, size);
	quick_sort_r(arr, pivot + 1, high, size);
}

/**
 * swap - swaps two element of an array
 * @arr: the array
 * @a: the lower limit of the subarray
 * @b: the higher limit of the subarray
 * @size: array size
 *
 */
void swap(int *arr, int a, int b, size_t size)
{
	int tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	if (tmp != arr[a])
		print_array(arr, size);
}

/**
 * partition - partitions an array
 * @arr: the array to partition
 * @low: the lower limit of the subarray
 * @high: the higher limit of the subarray
 * @size: size of array
 *
 * Return: position of pivot
 */
int partition(int *arr, int low, int high, size_t size)
{
	int i, j, pivot = arr[high];

	i = low - 1;
	for (j = low; j < high; ++j)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr, i, j, size);
		}
	}

	swap(arr, ++i, high, size);
	return (i);
}
