#include "sort.h"

/**
 * swap_func - Swaping two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_func(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Using the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_func(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
